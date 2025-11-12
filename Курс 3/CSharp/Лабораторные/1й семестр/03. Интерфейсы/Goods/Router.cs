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
    public int MaxWiFiVersion { get; } = maxWifiVersion;
    public new IQRCode QRData { get; set; } = new QRRecord(id.ToString());
    IQRCode IProduct.QRData { get; } = new QRRecord(id.ToString());

    private int _id;
    public new int ID
    {
        get => _id;
        set
        {
            QRData = new QRRecord(value.ToString());
            _id = value;
        }
    }

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
		sb.Append(QRData?.ToString());
		return sb.ToString();
	}
}