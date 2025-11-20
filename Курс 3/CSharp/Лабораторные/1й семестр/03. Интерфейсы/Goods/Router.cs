using QRLib;

using System.Text;

namespace Goods;

/// <summary>
/// Товар - роутер
/// </summary>
/// <remarks>
/// Конструктор класса
/// </remarks>
public sealed class Router(int id, string name, int lanCount, int bandwidth, int maxWifiVersion) : Switch(id, name, lanCount, bandwidth), IProduct
{
    public int MaxWiFiVersion { get; init; } = maxWifiVersion;
    public override IQRCode QRData { get; } = new QRRecord("");
    IQRCode IProduct.QRData { get; } = new QRRecord(id.ToString()); // Явная реализация интерфейса

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

	public override string ToString()
	{
		StringBuilder sb = new();
		sb.Append($"{Type}: {Name}\n");
		sb.Append(Info);
		sb.Append(QRData);
		return sb.ToString();
	}
}