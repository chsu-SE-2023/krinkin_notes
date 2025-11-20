using Shelves;
using Goods;

namespace CLI;

public class Interface
{
    private Dictionary<int, (string, Command)> prevMenu = [];
    private Dictionary<int, (string, Command)> currentMenu = [];

    private Dictionary<int, (string, Command)> CurrentMenu
    {
        get => currentMenu;
        set
        {
            prevMenu = currentMenu;
            currentMenu = value;
        }
    }

    private const int SHELVE_SIZE = 13;
    private readonly Shelve<Product> shelve = SHELVE_SIZE;
    private readonly int cmd_index = 1;


    public Interface()
    {
        DialogueMain();

        while (true)
        {
            Console.Clear();
            if (cmd_index > CurrentMenu.Count) cmd_index = 1;
            if (cmd_index < 1) cmd_index = CurrentMenu.Count;

            for (var i = 1; i <= CurrentMenu.Count; i++)
            {
                Console.BackgroundColor = (cmd_index == i ? ConsoleColor.White : ConsoleColor.Black);
                Console.ForegroundColor = (cmd_index == i ? ConsoleColor.Black : ConsoleColor.White);
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
        (currentMenu, prevMenu) = (prevMenu, currentMenu);
    }

    private static void Pause()
    {
        Console.WriteLine("Нажмите Enter для продолжения...");
        Console.ReadLine();
    }

    private void DialogueMain()
    {
        CurrentMenu = new()
        {
            { 1, ( "Вывести информацию", DialogueShow ) },
            { 2, ( "Добавить товар на витрину", DialogueAddProduct ) },
            { 3, ( "Убрать товар с витрины", DialogueRemove ) },
            { 4, ( "Поменять товары местами (не реализовано)", () => throw new NotImplementedException() ) },
            { 5, ( "Заменить товар (не реализовано)", () => throw new NotImplementedException() ) },
            { 6, ( "Найти товар", DialogueSearch ) },
            { 7, ( "Сортировать", DialogueSort ) },
            { 8, ( "Выход", () => Environment.Exit(0) ) },
        };
    }

    private void DialogueSearch()
    {
        CurrentMenu = new()
        {
            { 1, ( "По идентификатору (не реализовано)", () => throw new NotImplementedException() ) },
            { 2, ( "По имени (не реализовано)", () => throw new NotImplementedException() ) },
            { 3, ( "Назад", Back ) },
        };
    }

    private void DialogueSort()
    {
        CurrentMenu = new()
        {
            { 1, ( "По идентификатору", () => { shelve.OrderByID(); Pause(); } ) },
            { 2, ( "По имени", () => { shelve.OrderByName(); Pause(); } ) },
            { 3, ( "Назад", Back ) },
        };
    }

    private void DialogueShow()
    {
        Console.WriteLine(shelve);
		Pause();
    }

    private void DialogueRemove()
    {
        CurrentMenu = new() { };
        var goods = shelve.GetList();

        var index = 1;
        for (var i = 0; i < goods.Length; i++)
            if (goods[i] != null)
            {
                var val = i;
                CurrentMenu.Add(index, (goods[i]!.Name, () => { shelve.Remove(val); Back(); }));
                index++;
            }
        CurrentMenu.Add(index, ("Назад", () => Back()));
    }

    private void DialogueAddProduct()
    {
        CurrentMenu = new()
        {
            { 1, ( "Switch", DialogueAddSwitch ) },
            { 2, ( "Router", DialogueAddRouter ) },
            { 3, ( "Назад", Back ) },
        };
    }

    private void DialogueAddSwitch()
    {
        Console.WriteLine("ID продукта: "); var id = Convert.ToInt32(Console.ReadLine());
        Console.WriteLine("Имя продукта: "); var name = Console.ReadLine();
        Console.WriteLine("Количество портов LAN: "); var lanCount = Convert.ToInt32(Console.ReadLine());
        Console.WriteLine("Пропускная способность: "); var bandwidth = Convert.ToInt32(Console.ReadLine());
        if (name != null)
        {
            var sw = new Switch(id, name, lanCount, bandwidth);
            shelve.Add(sw);
        }
    }

    private void DialogueAddRouter()
    {
        Console.WriteLine("ID продукта: "); var id = Convert.ToInt32(Console.ReadLine());
        Console.WriteLine("Имя продукта: "); var name = Console.ReadLine();
        Console.WriteLine("Количество портов LAN: "); var lanCount = Convert.ToInt32(Console.ReadLine());
        Console.WriteLine("Максимальная версия WiFi: "); var maxWifiVersion = Convert.ToInt32(Console.ReadLine());
        Console.WriteLine("Пропускная способность: "); var bandwidth = Convert.ToInt32(Console.ReadLine());
        if (name != null)
        {
			var rt = new Router(id, name, lanCount, maxWifiVersion, bandwidth);
			shelve.Add(rt);
		}
    }
}

public delegate void Command();