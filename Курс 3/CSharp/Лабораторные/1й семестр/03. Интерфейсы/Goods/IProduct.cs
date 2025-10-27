using QRLib;

namespace Goods
{
    public interface IProduct
    {
        IQRCode QRData { get; set; }
        int ID { get; set; }
        string Info { get; }
        string Name { get; set; }
        string Type { get; }

        string ToString();
    }
}