namespace DataBaseApp
{
    internal class Queries
    {
        /// <summary>
        /// Запрос студентов с указанием фамилии и даты рождения
        /// </summary>
        /// <returns>SQL строка</returns>
        public static string SurnameDate()
        {
            return 
@"SELECT Фамилия, ДатаРождения FROM student1
    UNION
SELECT Фамилия, ДатаРождения FROM student2;";
        }

        /// <summary>
        /// Запрос студентов-отличников по математике
        /// </summary>
        /// <returns>SQL строка</returns>
        public static string GoodOnesMath()
        {
            return 
@"SELECT * FROM (
    SELECT * FROM student1
    UNION
    SELECT * FROM student2
) WHERE Математика = 5;";
        }

        /// <summary>
        /// Запрос студентов-отличников по всем предметам
        /// </summary>
        /// <returns>SQL строка</returns>
        public static string GoodOnes()
        {
            return 
@"SELECT * FROM (
    SELECT * FROM student1
    UNION
    SELECT * FROM student2
) WHERE Математика = 5 AND Информатика = 5 AND Иностранный = 5;";
        }

        /// <summary>
        /// Запрос студентов, чей возраст старше 20 лет
        /// </summary>
        /// <returns>SQL строка</returns>
        public static string OldOnes()
        {
            return 
@"SELECT * FROM (
    SELECT * FROM student1
    UNION
    SELECT * FROM student2
) WHERE DateDiff(""yyyy"",ДатаРождения,Date()) >= 20;";
        }
    }
}