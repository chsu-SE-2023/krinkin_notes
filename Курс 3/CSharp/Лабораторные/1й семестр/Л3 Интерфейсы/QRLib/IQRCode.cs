
namespace QRLib;

public interface IQRCode
{
    static abstract QrCodeType Type { get; set; }
    string Text { set; }
    QR Version { get; set; }
    EccLevel Ecc { get; set; }
    Mask Mask { get; set; }
    EncodingMode Mode { get; set; }
    QrCodeData QRData { get; }

    string ToString();
}