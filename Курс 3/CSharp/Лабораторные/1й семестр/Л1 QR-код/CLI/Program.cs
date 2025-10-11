
Console.Write("Введите текст: ");
var input = Console.ReadLine();
if (input != null)
{
    QRCode code = new(input);
    Console.WriteLine(code.QRData.Data);
    Console.WriteLine(code.ToString());
}
