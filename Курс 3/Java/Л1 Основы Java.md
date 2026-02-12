#### Простейшая Java программа

```
public class First {
	public static void main(String[] args) {
		System.out.println("Hallo world!");
	}
}
```

Функция `main` должна иметь три спецификатора: `public`, `static`, `void`.
Имя файла должно совпадать с именем `public` класса. В одном файле может быть только один `public` класс.
`static` - статические функции (методы) создаются в единственном экземпляре. Статические функции можно вызывать пользуясь именем класса не создавая ни одного объекта.
#### Простые типы данных

- Целые - `long`, `int`, `short`, `byte`
- Действительные - `double`, `float`
- Символьный - `char`
- Логический - `boolean`

Для каждого простого типа существует класс-обёртка элементы которых уже объекты, например для целых типов это класс `Integer`, для `char` - `Char`.
#### Класс String

- `lenght()` - определение длины строки
- `charAt()` - выбор символа из строки
- `substring()` - выбор подстроки
- `equals()` - сравнение строк на равенство
- `compareTo()` - лексикографическое сравнение срок
- `indexOf()` - номер первого вхождения подстроки в строку

`StringBuffer()` - да
#### Большие числа

Для работы с большими числами существуют два класса:
- `BigInteger`
- `BigDecimal`

![[Pasted image 20260212174616.png]]

``` Example 
public class Main {
	public static void main(String[] args) {
		int n = 100;
		BigInteger f = BigInteger.valueOf(1);
		for (int i = 1; i < n; i++) 
		    f.multiply(BigInteger.valueOf(i));
		System.out.println("f=" + f);
	}
}
```

