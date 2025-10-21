using Shelves;
using Goods;

Console.WriteLine("".PadLeft(120, '='));

Dictionary<int, (string, Command)> main_commands = new()
{
    { 1, ( "Добавить товар на витрину", () => throw new NotImplementedException() ) },
    { 2, ( "Убрать товар с витрины", () => throw new NotImplementedException() ) },
    { 3, ( "Поменять товары местами", () => throw new NotImplementedException() ) },
    { 4, ( "Заменить товар", () => throw new NotImplementedException() ) },
    { 5, ( "Найти товар", () => commands = search_commands ) },
    { 6, ( "Выход", () => Environment.Exit(0) ) },
};

Dictionary<int, (string, Command)> search_commands = new()
{
    { 1, ( "По идентификатору", () => throw new NotImplementedException() ) },
    { 2, ( "По имени", () => throw new NotImplementedException() ) },
    { 6, ( "Выход", () => Environment.Exit(0) ) },
};

int cmd_index = 0;
var commands = main_commands;

void SearchDialogByID()
{
    Console.WriteLine("");
}

void SearchDialogByName()
{
    Console.WriteLine();
}

while (true)
{
    Console.Clear();
    for (var i = 1; i <= commands.Count; i++)
    {
        Console.BackgroundColor = (cmd_index == i ? ConsoleColor.White : ConsoleColor.Black);
        Console.ForegroundColor = (cmd_index == i ? ConsoleColor.Black : ConsoleColor.White);
        Console.WriteLine($" * {commands[i].Item1}");
        Console.ResetColor();
    }
    switch (Console.ReadKey().Key)
    {
        case ConsoleKey.UpArrow: cmd_index--; break;
        case ConsoleKey.DownArrow: cmd_index++; break;
        case ConsoleKey.Enter: commands[cmd_index].Item2(); break;
    }
}

delegate void Command();