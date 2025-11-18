/// <summary> 
///     Формат вывода QR-кода, должен быть в отдельно файле /// 
/// </summary> 
public enum QrCodeType 
{ 
    /// <summary> 
    ///     Текстовая информация 
    /// </summary> 
    Text = 1, 
 	/// <summary> 
    ///     QR-код 
    /// </summary> 
    QrCode = 2, 
    /// <summary> 
    ///     Полная информация: QR-код + текст 
    /// </summary> 
    Full = 3
} 
