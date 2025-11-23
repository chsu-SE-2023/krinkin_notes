namespace Shelves;

using System.Text;
using Goods;

/// <summary>
/// Класс витрины
/// </summary>
public class Shelve<T> : IShelve<T> where T : class, IProduct
{
    /// <summary>
    /// Структура данных для хранения товаров.
    /// Может содержать null, что означает свободное место.
    /// </summary>
    private T?[] goods;
    private int id;

    /// <summary>
    /// Делегат изменения идентификатора
    /// </summary>
    private Action<IShelve<T>> updatedID;

    /// <summary>
    /// Свойство, хранящее идентификатор витрины
    /// </summary>
    public int ID
    {
        get => id;
        set
        {
            id = value;
            updatedID?.Invoke(this);
        }
    }

    /// <summary>
    /// Приватный конструктор витрины
    /// </summary>
    private Shelve(int size)
    {
        goods = new T?[size];
    }

    /// <summary>
    /// Преобразование из int (размера) в пустую витрину
    /// заданной вместимости
    /// </summary>
    public static implicit operator Shelve<T>(int size) => new(size);
    public static implicit operator Shelve<T>((int, int) prms) => new(prms.Item1) { ID = prms.Item2 };

    /// <summary>
    /// Индексатор.
    /// </summary>
    public T? this[int index]
    {
        get
        {
            if (index > goods.Length || index < 0 || goods[index] == null)
                return null;
            
            var value = goods[index];
            goods[index].IDChangeHandler -= OnProductIDChanged;
            updatedID -= goods[index].OnIDChanged;
            goods[index] = null;
            return value;
        }
        set
        {
            if (index > goods.Length || index < 0 || value == null)
                return;
            _ = this[index];
            
            goods[index].IDChangeHandler += OnProductIDChanged;
            updatedID += goods[index].OnIDChanged;
            goods[index].OnIDChanged(this);
        }
    }

    private void OnProductIDChanged(object sender, IDChangeEventArgs e)
    {
        if (sender is T product)
        {
            product.OnIDChanged(this);
        }
    }

    /// <summary>
    /// Метод, добавляющий товар на первое свободное место
    /// </summary>
    public void Add(T product)
    {
        var empty = Array.FindIndex(goods, x => x == null);
        if (empty != -1)
        {
            Add(product, empty);
        }
    }

    /// <summary>
    /// Метод, добавляющий товар по указанному индексу.
    /// </summary>
    public void Add(T product, int index)
    {
        if (goods[index] == null)
            this[index] = product;
    }

    /// <summary>
    /// Метод, удаляющий товар с витрины
    /// </summary>
    public void Remove(T product)
    {
        Remove(Array.FindIndex(goods, x => x == product));
    }

    /// <summary>
    /// Метод, удаляющий товар с витрины по индексу
    /// </summary>
    public void Remove(int index)
    {
        goods[index] = null;
    }

    /// <summary>
    /// Метод, заменяющий товар по индексу. Заменённый товар возвращается
    /// </summary>
    public T? Replace(T product, int index)
    {
        T? old = null;
        if (goods[index] != null)
            old = goods[index];
        this[index] = product;
        return old;
    }

    private int Search(Predicate<T> condition)
    {
        return Array.FindIndex(goods, condition!);
    }

    /// <summary>
    /// Метод, осуществляющий поиск товара
    /// по его идентификатору
    /// </summary>
    public int Search(int id)
    {
        return Search(x => x?.ID == id);
    }

    /// <summary>
    /// Метод, осуществляющий поиск товара
    /// по его имени
    /// </summary>
    public int Search(string name)
    {
        return Search(x => x?.Name == name);
    }

    /// <summary>
    /// Перестановка товара
    /// </summary>
    public void Swap(int index, int new_index)
    {
        if ((index > goods.Length || index < goods.Length) &&
            (new_index > goods.Length || new_index < goods.Length))
            (this[index], this[new_index]) = (this[new_index], this[index]);
    }

    private void OrderBy(Func<T, string> sorter)
    {
        T?[] sorted = [.. goods.Where(x => x != null).OrderBy(sorter!)];
        T?[] nulls = [.. goods.Where(x => x == null)];
        goods = [.. sorted, .. nulls];
        updatedID?.Invoke(this);
    }

    /// <summary>
    /// Метод, осуществляющий соритировку витрины
    /// по идентификатору товаров
    /// </summary>
    public void OrderByID()
    {
        OrderBy(x => x?.ID.ToString()!);
    }

    /// <summary>
    /// Метод, осуществляющий соритировку витрины
    /// по имени товаров
    /// </summary>
    public void OrderByName()
    {
        OrderBy(x => x?.Name!);
    }

    /// <summary>
    /// Перегрузка ToString()
    /// </summary>
    public override string ToString()
    {
        StringBuilder sb = new();
		for (var i = 0; i < goods.Length; i++)
        {
			sb.Append('\n');
			sb.Append($"{i}".PadLeft(10, '='));
			sb.Append("".PadRight(10, '='));
            sb.Append('\n');
            sb.Append(goods[i]?.ToString());
            if (goods[i] == null) sb.Append("Пустая ячейка\n");
        }
        return sb.ToString();
    }

    public T?[] GetList()
    {
        return goods;
    }
}
