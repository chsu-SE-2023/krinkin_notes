
Console.Write("Введите текст: ");
var input = Console.ReadLine();


Console.Write("1. Текстовый\n2. Только рисунок\n3. Рисунок и текст\nТип вывода информации: ");
var type = Int32.Parse(Console.ReadLine());

if (input != null)
{
    QRCode code = new(input);
    string data = type switch
    {
        1 => code.ToString(),
        2 => code.QRData.Data,
        3 => code.QRData.Data + "\n" + code.ToString(),
        _ => ""
    };

    Console.WriteLine(data);
}
