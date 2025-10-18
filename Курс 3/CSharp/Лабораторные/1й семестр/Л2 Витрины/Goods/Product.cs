using System.Text;

namespace Goods;

/// <summary>
/// Абстрактный класс товара
/// </summary>
abstract public class Product
{
    /// <summary>
    /// Свойство, хранящее QR код
    /// </summary>
    private QRCode? QR;
    public QrCodeType QRType
    {
        get => QRCode.Type;
        set => QRCode.Type = value;
    }

    /// <summary>
    /// Свойство, хранящее идентификатор товара
    /// </summary>
    private int _id;
    public int ID
    {
        get => _id;
        set
        {
            QR = new QRCode(value.ToString());
            _id = value;
        }
    }

    /// <summary>
    /// Свойство, хранящее наименование товара
    /// </summary>
    public string Name { get; set; }

    /// <summary>
    /// Конструктор товара
    /// </summary>
    public Product(int id, string name)
    {
        ID = id;
        Name = name;
    }

    /// <summary>
    /// Абстрактные свойства, хранящие тип товара и 
    /// информацию о нём.
    /// </summary>
    public abstract string Info { get; }
    public abstract string Type { get; }

    /// <summary>
    /// Перегрузка ToString()
    /// </summary>
    public override string ToString()
    {
        StringBuilder sb = new();
        sb.Append($"{Type}: {Name}\n");
        sb.Append(Info);
        sb.Append(QR?.ToString());
        return sb.ToString();
    }
}
