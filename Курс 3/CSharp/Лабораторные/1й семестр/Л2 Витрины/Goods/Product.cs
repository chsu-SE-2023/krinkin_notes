using System.Text;

namespace Goods;

abstract public class Product
{

    private QRCode? QR;
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
        
    public string Name { get; set; }

    public Product(int id, string name)
    {
        ID = id;
        Name = name;
    }

    public override string ToString()
    {
        StringBuilder sb = new();
        sb.Append($"Тип товара: {Name}");
        sb.Append($"Информация 1: значение");
        sb.Append(QR.ToString());
        return "";
    }
}
