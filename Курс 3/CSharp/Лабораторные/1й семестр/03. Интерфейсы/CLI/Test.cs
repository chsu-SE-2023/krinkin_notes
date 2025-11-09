using Shelves;
using Goods;
using QRLib;

var samples = new List<IProduct>
{
    new Switch(3000, "D-Link DGS-1024D/J1A", 24, 1000),
    new Switch(1000, "MikroTik CRS326-24G-2S+RM", 24, 1000),
    new Switch(2000, "Keenetic PoE+ Switch 5 KN-4610", 5, 1000)
};
var r_samples = new List<Router>
{
    new Router(5555, "Keenetic Air KN-1613", 3, 5, 1167),
    new Router(6666, "ASUS RT-BE50", 3, 7, 3570)
};

IQRCode.Type = QrCodeType.Full;

IShelve<IProduct> shelve = (Shelve<IProduct>) 13; shelve.ID = 1;
Shelve<Router> r_shelve = (11, 2);

foreach (var product in samples)
{
    shelve.Add(product);
}
foreach (var product in r_samples)
{
    shelve.Add(product);
}
shelve.OrderByName();

var sample1 = new Router(7777, "Xiaomi Router AX3200 RB01", 3, 6, 3202);
var sample2 = new Router(4000, "Keenetic Speedster KN-3013", 3, 5, 1167);

r_shelve[0] = sample1;
shelve[5] = r_shelve[0];
shelve[6] = sample2;

shelve.ID = 2;
sample1.ID++;
sample2.ID++;

Console.WriteLine(shelve);

r_shelve[0] = (Router?) shelve[5];
Console.WriteLine(r_shelve);

// TODO: Явная реализация интерфейса
// (ID должен меняться)
Console.WriteLine(sample1);
sample1.ID++;
Console.WriteLine(sample1);