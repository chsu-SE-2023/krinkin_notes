using Shelves;
using Goods;
using System.Text;

namespace CLI;

public class Interface
{
    private List<(string, Action)> currentMenu = [];
    private List<(string, Action)> CurrentMenu
    {
        get => currentMenu;
        set
        {
            History.Push(currentMenu);
            currentMenu = value;
            cmd_index = 0;
        }
    }

    private Shelve<Product> shelve;
    private int cmd_index = 0;
    private Stack<List<(string, Action)>> History = new();

    public Interface()
    {
        Console.WriteLine("Введите размер витрины: ");
        shelve = Convert.ToInt32(Console.ReadLine());

        DialogueMain();

        while (true)
        {
            Console.Clear();

            if (cmd_index > CurrentMenu.Count-1) cmd_index = 0;
            if (cmd_index < 0) cmd_index = CurrentMenu.Count-1;

            for (var i = 0; i < CurrentMenu.Count; i++)
            {
                Console.BackgroundColor = cmd_index == i ? ConsoleColor.White : ConsoleColor.Black;
                Console.ForegroundColor = cmd_index == i ? ConsoleColor.Black : ConsoleColor.White;
                Console.WriteLine($" * {CurrentMenu[i].Item1}");
                Console.ResetColor();
            }
            switch (Console.ReadKey().Key)
            {
                case ConsoleKey.UpArrow: cmd_index--; break;
                case ConsoleKey.DownArrow: cmd_index++; break;
                case ConsoleKey.Enter:
                    {
                        Console.Clear();
                        CurrentMenu[cmd_index].Item2();
                        break;
                    };
            }
        }
    }

    private void Back()
    {
        currentMenu = History.Pop();
    }

    private static void Pause()
    {
        Console.WriteLine("Нажмите Enter для продолжения...");
        Console.ReadLine();
    }

    private void DialogueMain()
    {
        CurrentMenu = 
        [
            ( "Вывести информацию", DialogueShow ),
            ( "Добавить товар на витрину", DialogueAddProduct ),
            ( "Убрать товар с витрины", () => ObjectSelectDialogue(shelve.Remove, "Удалить") ),
            ( "Поменять товары местами", () => ObjectSelectDialogue(DialogueSwap, "Поменять", false) ),
            ( "Заменить товар", () => ObjectSelectDialogue(DialogueReplace, "Заменить", false) ),
            ( "Найти товар", DialogueSearch ),
            ( "Сортировать", DialogueSort ),
            ( "Изменить идентификатор", DialogueChangeID ),
            ( "Выход", () => Environment.Exit(0) ),
        ];
    }

    private void ObjectSelectDialogue(Action<int> action, string suffix = "", bool back = true)
    {
        CurrentMenu = [];
        var goods = shelve.GetList();

        var index = 1;
        for (var i = 0; i < goods.Length; i++)
            if (goods[i] != null)
            {
                var val = i;
                var name = new StringBuilder();
                name.Append(suffix)
                    .Append(": ")
                    .Append(goods[i]!.Name);
                CurrentMenu.Add((name.ToString(), () => { action.Invoke(val); if (back) Back(); }));
                index++;
            }
        CurrentMenu.Add(("Назад", Back));
    }

    private void DialogueShow()
    {
        Console.WriteLine(shelve);
        Pause();
    }

    private void DialogueSearch()
    {
        CurrentMenu = 
        [
            ( "По идентификатору", DialogueSearchByID ),
            ( "По имени", DialogueSearchByName ),
            ( "Назад", Back ),
        ];
    }

    private void DialogueSearchBy(object value)
    {
        var index = -1;
        if (value is int id) index = shelve.Search(id);
        if (value is string name) index = shelve.Search(name);
        if (index != -1) Console.WriteLine(shelve[index]);
        else Console.WriteLine("Продукт не найден!");
        Pause();
    }

    private void DialogueSearchByID()
    {
        Console.WriteLine("ID продукта: "); var id = Convert.ToInt32(Console.ReadLine());
        DialogueSearchBy(id);
    }

    private void DialogueSearchByName()
    {
        Console.WriteLine("Имя продукта: "); var name = Console.ReadLine();
        DialogueSearchBy(name);
    }

    private void DialogueSort()
    {
        CurrentMenu = 
        [
            ( "По идентификатору", () => { shelve.OrderByID(); Pause(); } ),
            ( "По имени", () => { shelve.OrderByName(); Pause(); } ),
            ( "Назад", Back ),
        ];
    }

    private void DialogueSwap(int old_index)
    {
        ObjectSelectDialogue((index) => shelve.Swap(old_index, index), suffix: "На");
    }

    private void DialogueReplace(int index)
    {
        CurrentMenu = 
        [
            ( "Switch", () => { shelve.Replace(DialogueCreateSwitch(), index); Back(); } ),
            ( "Router", () => { shelve.Replace(DialogueCreateRouter(), index); Back(); } ),
            ( "Назад", Back ),
        ];
    }

    private void DialogueAddProduct()
    {
        CurrentMenu = 
        [
            ( "Switch", () => shelve.Add(DialogueCreateSwitch()) ),
            ( "Router", () => shelve.Add(DialogueCreateRouter()) ),
            ( "Назад", Back ),
        ];
    }

    private Switch DialogueCreateSwitch()
    {
        Console.WriteLine("ID продукта: "); var id = Convert.ToInt32(Console.ReadLine());
        Console.WriteLine("Имя продукта: "); var name = Console.ReadLine();
        Console.WriteLine("Количество портов LAN: "); var lanCount = Convert.ToInt32(Console.ReadLine());
        Console.WriteLine("Пропускная способность: "); var bandwidth = Convert.ToInt32(Console.ReadLine());
        return new Switch(id, name, lanCount, bandwidth);
    }

    private Router DialogueCreateRouter()
    {
        Console.WriteLine("ID продукта: "); var id = Convert.ToInt32(Console.ReadLine());
        Console.WriteLine("Имя продукта: "); var name = Console.ReadLine();
        Console.WriteLine("Количество портов LAN: "); var lanCount = Convert.ToInt32(Console.ReadLine());
        Console.WriteLine("Максимальная версия WiFi: "); var maxWifiVersion = Convert.ToInt32(Console.ReadLine());
        Console.WriteLine("Пропускная способность: "); var bandwidth = Convert.ToInt32(Console.ReadLine());
        return new Router(id, name, lanCount, maxWifiVersion, bandwidth);
    }

    private void DialogueChangeID()
    {
        CurrentMenu =
        [
            ( "Продукта", () => ObjectSelectDialogue(DialogueChangeProductID) ),
            ( "Витрины", DialogueChangeSvelveID ),
            ( "Назад", Back ),
        ];
    }

    private void DialogueChangeProductID(int index)
    {
        Console.WriteLine("Новый ID продукта: "); 
        var id = Convert.ToInt32(Console.ReadLine());
        shelve[index]!.ID = id; // TODO: Borked
    }

    private void DialogueChangeSvelveID()
    {
        Console.WriteLine("Новый ID витрины: ");
        var id = Convert.ToInt32(Console.ReadLine());
        shelve.ID = id;
    }
}
