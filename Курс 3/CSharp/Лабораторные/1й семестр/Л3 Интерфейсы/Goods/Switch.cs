
using System.Text;

namespace Goods;

public class Switch(int id, string name, int lanCount, int bandwidth) : Product(id, name)
{
    public int LanCount { get; init; } = lanCount;
    public int Bandwidth { get; init; } = bandwidth;

    public override string Type => "Коммутатор";
    public override string Info
    {
        get
        {
            StringBuilder sb = new();
            sb.Append($"Количество LAN портов: {LanCount}\n");
            sb.Append($"Пропускная способность: {Bandwidth} Mbit\n");
            return sb.ToString();
        }
    }
}

