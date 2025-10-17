namespace Goods;

public class Router: Product
{
    public int WiFiVersion { get; init; }

    public Router(int id, string name) : base(id, name)
    {

    }

    public override string ToString()
    {
        return base.ToString();
    }
}