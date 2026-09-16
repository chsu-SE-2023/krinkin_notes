**Spring Framework** - облегчённая платформа для построения Enterprise приложений на Java.

- Можно применить к любому Java приложению
- Облегчённая - не размер дистрибутива, а степень воздействия на код 
- Модульная структура (IoC, Web, Data Access, Messaging, ...)
#### Основа Spring

Ядро Spring Framework основано на принципе _инверсии управления_ (IoC), когда создание и управление зависимостями между компонентами становятся внешними.

Мартин Фаулер назвал процесс внедрения зависимостей во время выполнения, приводящее к инверсии Dependency Injection - DI.

Реализация DI в Spring основана на двух концепциях:
- JavaBean
- Интерфейсы

В Spring любой управляемый ресурс - это bean.

С помощью интерфейсов можно получить максимальную отдачу от DI: бины могут использовать любую реализацию интерфейса для удовлетворения их зависимостей.

Конфигурирование через XML или классы Java, или аннотации в коде или через Groovy.

Средства и инструменты:
- АОП - абстрактное объектное программирование
- SpEL - Spring ... Language
- Валидация - Проверка доступности
- Доступ к реляционным данным
- Управление транзакциями
- MVC на веб-уровне
- WebSocket

- **Core** обеспечивает основные части фреймворка включая свойства IoC и DI.
- **Beans** - это классы, созданием экземпляров которых и установкой в них зависимостей управляет контейнер фреймворка Spring.
- **Context** - построен на основе Beans и Core и позволяет получить доступ к любому объекту, который определён в настройках . Ключевым элементом модуля Context и является интерфейса ApplicationContext.
#### Inversion of Control

Ядро Spring Framework основано на принципе _инверсии управления_ (IoC), когда создание и управление зависимостями между компонентами становятся внешними.

Проблема

``` java
class ClassicalMusic {...}

class MusicPlayer {
    private ClassicalMusic clmusic:
    
    public void PlayMusic() {
        clmusic = new ClassicalMusic();
        ...
    }
}
```

Присутствует сильная зависимость от ClassicalMusic();

Решение 1: Интерфейс

``` java
interface Music {...}

class ClassicalMusic implements Music {...}
class RockMusic implements Music {...}

class MusicPlayer {
    private Music music:
    
    public void PlayMusic() {
        music = new ClassicalMusic();
        ...
        music = new RockMusic();
        ...
    }
}
```

Здесь сильная зависимость заменена на слабую.

Решение 2: Бины
``` java
interface Music {...}

class ClassicalMusic implements Music {...}
class RockMusic implements Music {...}

class MusicPlayer {
    private Music music:
    
    public void PlayMusic() {
        ClassPathXmlApplicationContext context = newClassPathXmlApplicationContext("applicationContext.xml");
        music = contextGetBean("classicalMusic", ClassicalMusic.class);
        ...
        music = contextGetBean("rockMusic", RockMusic.class);
        ...
    }
}
```

Здесь объекты заменены на бины

Решение 3: Инвертирование
``` java
interface Music {...}

class ClassicalMusic implements Music {...}
class RockMusic implements Music {...}

class MusicPlayer {
    private Music music:
    
    MusicPlayer(Music music) {
        this.music = music;
    }
    
    public void PlayMusic() {
        ...
    }
}
```

``` java
class Play {
    public static void main(String[] args) {
    MusicPlayer mp = new MusicPlayer(new RockMusic());
    }
}
```

Здесь управление инвестировано и объект создаётся во внешнем классе.