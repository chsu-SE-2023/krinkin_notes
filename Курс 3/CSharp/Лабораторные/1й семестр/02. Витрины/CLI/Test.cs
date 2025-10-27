using Shelves;
using Goods;

Console.WriteLine("".PadLeft(120, '='));

Shelve shelve = 13;
shelve.ID = 10;

Product.QRType = QrCodeType.Full;

var sample = new Router(1000, "TP-Link Archer AX1500", 4, 6, 1267);
var samples = new List<Product>
{
    new Router(2000, "Keenetic Air KN-1613", 3, 5, 1167),
    new Router(3000, "Xiaomi Router AX3200 RB01", 3, 6, 3202),
    new Router(4000, "ASUS RT-BE50", 3, 7, 3570)
};

foreach (var product in samples)
{
    shelve.Add(product);
}
shelve[4] = sample;

sample.ID++;
Console.WriteLine(sample);

shelve.OrderByName();

shelve.ID++;
Console.WriteLine(shelve);