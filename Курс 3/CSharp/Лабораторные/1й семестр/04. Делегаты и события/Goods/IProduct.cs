using QRLib;

namespace Goods
{
    public interface IProduct
    {
        IQRCode QRData { get; }
        int ID { get; set; }
        string Info { get; }
        string Name { get; set; }
        string Type { get; }
        event EventHandler<IDChangeEventArgs> IDChangeHandler;
    }
}