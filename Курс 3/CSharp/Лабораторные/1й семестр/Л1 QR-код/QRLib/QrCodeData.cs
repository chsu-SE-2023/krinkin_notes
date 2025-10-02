public record QrCodeData 
{ 
    public QR Version {get; init;} 
    public EccLevel CorrectionLevel {get; init;}
    public string Data { get; init; } 
} 
