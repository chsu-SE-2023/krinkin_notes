
Console.Write("1. Текстовый\n2. Только рисунок\n3. Рисунок и текст\nТип вывода информации: ");
QRCode.Type = Enum.Parse<QrCodeType>(Console.ReadLine());

while (true)
{
	Console.Write("Введите текст (для выхода введите пустой символ): ");
	var input = Console.ReadLine();

	if (input != null)
	{
		QRCode code = new(input);
		Console.WriteLine(code.ToString());
	} else
	{
		break;
	}
}
