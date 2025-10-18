using System.Text;

namespace Goods;

/// <summary>
/// Товар - роутер
/// </summary>
public class Router : Product
{
    public int MaxWiFiVersion { get; init; }
    public int LanCount { get; init; }
    public int Bandwidth { get; init; }

    /// <summary>
    /// Переопределение типа и информации о свойствах
    /// для доступа из базового класса
    /// </summary>
    public override string Type => "Роутер";
    public override string Info
    {
        get
        {
            StringBuilder sb = new();
            sb.Append($"Максимальная версия WiFi: WiFi {MaxWiFiVersion}\n");
            sb.Append($"Количество LAN портов: {LanCount}\n");
            sb.Append($"Пропускная способность: {Bandwidth} Mbit\n");
            return sb.ToString();
        }
    }

    /// <summary>
    /// Конструктор класса
    /// </summary>
    public Router(int id, string name, int lanCount, int maxWifiVersion, int bandwidth) : base(id, name)
    {
        LanCount = lanCount;
        MaxWiFiVersion = maxWifiVersion;
        Bandwidth = bandwidth;
    }
}