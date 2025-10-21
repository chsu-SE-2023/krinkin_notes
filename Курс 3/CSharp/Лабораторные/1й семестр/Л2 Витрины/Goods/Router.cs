using System.Text;

namespace Goods;

/// <summary>
/// Товар - роутер
/// </summary>
/// <remarks>
/// Конструктор класса
/// </remarks>
public class Router(int id, string name, int lanCount, int maxWifiVersion, int bandwidth) : Product(id, name)
{
    public int MaxWiFiVersion { get; init; } = maxWifiVersion;
    public int LanCount { get; init; } = lanCount;
    public int Bandwidth { get; init; } = bandwidth;

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
}