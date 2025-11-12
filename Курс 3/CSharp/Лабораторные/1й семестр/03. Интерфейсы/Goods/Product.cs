using System.Text;
using QRLib;

namespace Goods;

/// <summary>
/// Абстрактный класс товара
/// </summary>
abstract public class Product : IProduct
{
    /// <summary>
    /// Свойство, хранящее QR код
    /// </summary>
    public IQRCode QRData { get; } = new QRCode("");

    public static QrCodeType QRType
    {
        get => IQRCode.Type;
        set => IQRCode.Type = value;
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
            QRData.Text = value.ToString();
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
    protected Product(int id, string name)
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
        sb.Append(QRData?.ToString());
        return sb.ToString();
    }
}
