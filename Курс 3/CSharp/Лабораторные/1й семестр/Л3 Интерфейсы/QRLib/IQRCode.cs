
namespace QRLib;

public interface IQRCode
{
    public static QrCodeType Type { get; set; } = QrCodeType.QrCode;
    string Text { set; }
    QrCodeData QRData { get; }
}