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
    /// Свойство, хранящее идентификатор витрины
    /// </summary>
    public int ID
    {
        get => id;
        set
        {
            id = value;
            UpdateQRs();
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
            if (index > goods.Length || index < 0)
                return default;
            var value = goods[index];
            goods[index] = default;
            return value;
        }
        set
        {
            if (index > goods.Length || index < 0)
                return;
            goods[index] = value;
            UpdateQRs(index);
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
        goods[index] = default;
    }

    /// <summary>
    /// Метод, заменяющий товар по индексу. Заменённый товар возвращается
    /// </summary>
    public T? Replace(T product, int index)
    {
        T? old = default;
        if (goods[index] != null)
            old = goods[index];
        this[index] = product;
        return old;
    }

    /// <summary>
    /// Метод, осуществляющий поиск товара
    /// по его идентификатору
    /// </summary>
    public T? Search(int id)
    {
        return Array.Find(goods, x => x?.ID == id);
    }

    /// <summary>
    /// Метод, осуществляющий поиск товара
    /// по его имени
    /// </summary>
    public T? Search(string name)
    {
        return Array.Find(goods, x => x?.Name == name);
    }

    /// <summary>
    /// Пестановка товара
    /// </summary>
    public void Swap(int index, int new_index)
    {
        if ((index > goods.Length || index < goods.Length) &&
            (new_index > goods.Length || new_index < goods.Length))
            (this[index], this[new_index]) = (this[new_index], this[index]);
    }

    /// <summary>
    /// Метод, осуществляющий соритировку витрины
    /// по идентификатору товаров
    /// </summary>
    public void OrderByID()
    {
        goods = [.. goods.OrderBy(x => x?.ID)];
        UpdateQRs();
    }

    /// <summary>
    /// Метод, осуществляющий соритировку витрины
    /// по имени товаров
    /// </summary>
    public void OrderByName()
    {
        goods = [.. goods.OrderBy(x => x?.Name)];
        UpdateQRs();
    }

    /// <summary>
    /// Перегрузка ToString()
    /// </summary>
    public override string ToString()
    {
        StringBuilder sb = new();
        foreach (var product in goods)
        {
            sb.Append("".PadLeft(20, '='));
            sb.Append('\n');
            sb.Append(product?.ToString());
            if (product == null) sb.Append("Пустая ячейка\n");
        }
        return sb.ToString();
    }

    /// <summary>
    /// Метод, добавляющий в QR данные о витрине
    /// </summary>
    private void UpdateQRs(int? index = null)
    {
        if (index == null)
        {
            for (var i = 0; i < goods.Length; i++)
                if (goods[i] != null)
                    goods[i]!.QRData.Text = $"{goods[i]!.ID} {this.ID} {i}";
        }
        else
            if (goods[(int)index] != null)
            goods[index.Value]!.QRData.Text = $"{goods[index.Value]!.ID} {this.ID} {index}";
    }

    public T?[] GetList()
    {
        return goods;
    }
}
