
using System.Text;

namespace QRLib;

public record QRRecord : IQRCode
{
    /// <summary>
    /// Свойство с текстом
    /// </summary>
    public string Text { private get; set; }

    /// <summary>
    /// Свойство с версией QR. Если значение не установлено, то устанавливается оптимальное
    /// </summary>
    private QR _version = QR.V1;
    public QR Version
    {
        get => _version;
        set => _version = value;
    }

    /// <summary>
    /// Свойство с версией коррекции ошибок. Если значение не установлено, то устанавливается оптимальное
    /// </summary>
    private EccLevel? _ecc;
    public EccLevel Ecc
    {
        get => _ecc == null ? EccLevel.L : (EccLevel)_ecc;
        set => _ecc = value;
    }

    /// <summary>
    /// Свойство с маской. Если значение не установлено, то устанавливается оптимальное
    /// </summary>
    private Mask? _mask;
    public Mask Mask
    {
        get => _mask == null ? Mask.M001 : (Mask)_mask;
        set => _mask = value;
    }

    /// <summary>
    /// Свойство с режимом кодирования. Если значение не установлено, то устанавливается оптимальное
    /// </summary>
    private EncodingMode? _mode;
    public EncodingMode Mode
    {
        get => _mode == null ? EncodingMode.Binary : (EncodingMode)_mode;
        set => _mode = value;
    }

    /// <summary>
    /// Свойство с данными, хранящимися в QR коде.
    /// </summary>
    public QrCodeData QRData
    {
        get
        {
            return new()
            {
                Data = QrCodeBuilder.GetQrCode(Text, ref _version, ref _mode, ref _ecc, ref _mask),
                Version = Version,
                CorrectionLevel = Ecc
            };
        }
    }

    /// <summary>
    /// Коструктор класса принимающий кодируемый текст.
    /// </summary>
    public QRRecord(string text)
    {
        Text = text;
    }

    /// <summary>
    /// Перегрузка ToString().
    /// </summary>
    public override string ToString()
    {
        StringBuilder sb = new();
        if (IQRCode.Type == QrCodeType.QrCode || IQRCode.Type == QrCodeType.Full)
        {
            sb.Append(QRData.Data);
        }

        if (IQRCode.Type == QrCodeType.Text || IQRCode.Type == QrCodeType.Full)
        {
            sb.Append($"Text: * {Text} *\n");
            sb.Append($"Version: {Version}\n");
            sb.Append($"Correction level: {Ecc}\n");
            sb.Append($"Data lenght: {Text.Length}");
        }
        return sb.ToString();
    }

}
