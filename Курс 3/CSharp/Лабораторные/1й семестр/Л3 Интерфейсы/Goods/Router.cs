using QRLib;

using System.Text;

namespace Goods;

/// <summary>
/// Товар - роутер
/// </summary>
/// <remarks>
/// Конструктор класса
/// </remarks>
public sealed class Router(int id, string name, int lanCount, int bandwidth, int maxWifiVersion) : Switch(id, name, lanCount, bandwidth)
{
    public int MaxWiFiVersion { get; init; } = maxWifiVersion;
    public IQRCode QRCode { get; init; } = new QRRecord("");

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
            sb.Append(base.Info);
            sb.Append($"Максимальная версия WiFi: WiFi {MaxWiFiVersion}\n");
            return sb.ToString();
        }
    }
}