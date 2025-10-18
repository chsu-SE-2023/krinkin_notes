namespace Shelves;

using System.Text;
using Goods;

/// <summary>
/// Класс витрины
/// </summary>
public class Shelve
{
    /// <summary>
    /// Структура данных для хранения товаров.
    /// Может содержать null, что означает свободное место.
    /// </summary>
    private List<Product?> goods;

    /// <summary>
    /// Свойство, хранящее идентификатор витрины
    /// </summary>
    public int ID { get; set; }

    /// <summary>
    /// Приватный конструктор витрины
    /// </summary>
    private Shelve(int size)
    {
        goods = new(size);
        for (var i = 0; i < goods.Capacity; i++)
            goods.Add(null);
    }

    /// <summary>
    /// Преобразование из int (размера) в пустую витрину
    /// заданной вместимости
    /// </summary>
    public static implicit operator Shelve(int size) => new(size);

    /// <summary>
    /// Индексатор.
    /// </summary>
    public Product? this[int index]
    {
        get
        {
            if (index > goods.Capacity || index < goods.Capacity)
                return null;
            var value = goods[index];
            goods[index] = null;
            return value;
        }
        set
        {
            if (index > goods.Capacity || index < goods.Capacity)
                return;
            Add(value, index);
        }
    }

    /// <summary>
    /// Метод, добавляющий товар на первое свободное место
    /// </summary>
    public void Add(Product product)
    {
        var empty = goods.FindIndex(x => x == null);
        if (empty != -1)
            goods[empty] = product;
        else
            throw new OverflowException("Для товара нет места");
    }

    /// <summary>
    /// Метод, добавляющий товар по указанному индексу.
    /// Заменяет товар, если место занято. Заменённый товар возвращается
    /// </summary>
    public Product? Add(Product product, int index)
    {
        Product? old = null;
        if (goods[index] != null)
            old = goods[index];
        goods[index] = product;
        return old;
    }

    /// <summary>
    /// Метод, удаляющий товар с витрины
    /// </summary>
    public void Remove(Product product)
    {
        var index = goods.FindIndex(x => x == product);
        Remove(index);
    }

    /// <summary>
    /// Метод, удаляющий товар с витрины по индексу
    /// </summary>
    public void Remove(int index)
    {
        goods[index] = null;
    }

    /// <summary>
    /// Метод, осуществляющий поиск товара
    /// по его идентификатору
    /// </summary>
    public Product? Search(int id)
    {
        return goods.Find(x => x?.ID == id);
    }

    /// <summary>
    /// Метод, осуществляющий поиск товара
    /// по его имени
    /// </summary>
    public Product? Search(string name)
    {
        return goods.Find(x => x?.Name == name);
    }

    /// <summary>
    /// Метод, осуществляющий соритировку витрины
    /// по идентификатору товаров
    /// </summary>
    public void OrderByID()
    {
        goods = [.. goods.OrderBy(x => x?.ID)];
    }

    /// <summary>
    /// Метод, осуществляющий соритировку витрины
    /// по имени товаров
    /// </summary>
    public void OrderByName()
    {
        goods = [.. goods.OrderBy(x => x?.Name)];
    }

    /// <summary>
    /// Перегрузка ToString()
    /// </summary>
    public override string ToString()
    {
        StringBuilder sb = new();
        foreach (var product in goods)
        {
            sb.Append("".PadLeft(80, '='));
            sb.Append(product?.ToString());
            if (product == null) sb.Append("Пустая ячейка\n");
        }
        return sb.ToString();
    }
}
