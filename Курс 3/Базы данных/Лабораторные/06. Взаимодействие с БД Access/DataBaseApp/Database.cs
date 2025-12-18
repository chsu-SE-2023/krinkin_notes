using System;
using System.Data;
using System.Data.Common;
using System.Data.OleDb;
using System.Text;
using System.Windows.Forms;

namespace DataBaseApp
{
    internal class Database
    {
        private OleDbConnection dbConnection = null;

        /// <summary>
        /// Конструктор, открывающий новое подключение к базе данных
        /// </summary>
        /// <param name="dataBaseFile">Имя файла базы данных</param>
        public Database(string dataBaseFile)
        {
            if (dbConnection == null || dbConnection?.State == ConnectionState.Closed)
            {
                // Установка соединения
                string connection = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=" + dataBaseFile;
                dbConnection = new OleDbConnection(connection);
                dbConnection.Open();
            }
        }

        /// <summary>
        /// Деконструктор, закрывающий подключение
        /// </summary>
        ~Database()
        {
            try
            {
                this.dbConnection.Close();
            } catch (Exception) { }
            
        }

        /// <summary>
        /// Метод, возвращющий структуру таблицы базы данных
        /// </summary>
        /// <param name="tableName">Название таблицы в базе данных</param>
        /// <returns>Структура таблицы</returns>
        public DataTable GetSchema(string tableName)
        {
            string query = "SELECT * FROM " + tableName;
            OleDbCommand dbCommand = new OleDbCommand(query, dbConnection);
            OleDbDataReader dbDataReader = dbCommand.ExecuteReader();
            var schema = dbDataReader.GetSchemaTable();
            dbDataReader.Close();
            return schema;
        }

        /// <summary>
        /// Метод, возвращающий список таблиц в файле базы даных
        /// </summary>
        /// <returns>Список таблиц</returns>
        public DataTable GetTableList()
        {
            // Исключение внутренних таблиц
            string[] restrictions = new string[4];
            restrictions[3] = "Table";

            return dbConnection.GetSchema("Tables", restrictions);
        }

        /// <summary>
        /// Метод, возвращающий курсор чтения в базе данных
        /// </summary>
        /// <param name="query">SQL-запрос</param>
        /// <returns>Курсор чтения</returns>
        public OleDbDataReader GetOleDbReader(string query)
        {
            OleDbCommand dbCommand = new OleDbCommand(query, dbConnection);
            return dbCommand.ExecuteReader();
        }

        /// <summary>
        /// Метод добавления записи в таблицу
        /// </summary>
        /// <param name="rowIndex">Индекс строки графической таблицы, содержащей запись</param>
        public void AddRow(string tableName, DataGridViewRow row)
        {
            DataTable schema = GetSchema(tableName);

            // Формирование запроса
            StringBuilder query = new StringBuilder($"INSERT INTO {tableName} (");
            for (int i = 0; i < schema.Rows.Count; i++)
            {
                query.Append($"{schema.Rows[i][0]}");
                if (i < schema.Rows.Count - 1) query.Append(",");
            }
            query.Append(") VALUES (");
            for (int i = 0; i < schema.Rows.Count; i++)
            {
                query.Append($"@par{i}");
                if (i < schema.Rows.Count - 1) query.Append(",");
            }
            query.Append(");");

            OleDbCommand dbCommand = new OleDbCommand(query.ToString(), dbConnection);

            // Заполнение параметров
            for (int i = 0; i < schema.Rows.Count; i++)
            {
                Type type = schema.Rows[i][5] as Type;
                dbCommand.Parameters.Add($"@par{i}", Convert.ChangeType(row.Cells[i].Value, type));
            }

            dbCommand.ExecuteNonQuery();
        }

        /// <summary>
        /// Метод редактирования записи
        /// </summary>
        /// <param name="rowIndex">Индекс строки графической таблицы, содержащей запись</param>
        public void EditRow(string tableName, DataGridViewRow row)
        {
            DataTable schema = GetSchema(tableName);

            // Формирование запроса
            StringBuilder query = new StringBuilder($"UPDATE {tableName} SET ");
            for (int i = 0; i < schema.Rows.Count; i++)
            {
                query.Append($"{schema.Rows[i][0]}=@par{i}_new");
                if (i < schema.Rows.Count - 1) query.Append(",");
            }
            query.Append(" WHERE ");
            for (int i = 0; i < schema.Rows.Count; i++)
            {
                query.Append($"{schema.Rows[i][0]}=@par{i}_old");
                if (i < schema.Rows.Count - 1) query.Append(" AND ");
            }
            query.Append(";");

            OleDbCommand dbCommand = new OleDbCommand(query.ToString(), dbConnection);

            // Заполнение параметров
            for (int i = 0; i < schema.Rows.Count; i++)
            {
                Type type = schema.Rows[i][5] as Type;
                dbCommand.Parameters.Add($"@par{i}_new", Convert.ChangeType(row.Cells[i].EditedFormattedValue, type));
            }
            for (int i = 0; i < schema.Rows.Count; i++)
            {
                Type type = schema.Rows[i][5] as Type;
                dbCommand.Parameters.Add($"@par{i}_old", Convert.ChangeType(row.Cells[i].FormattedValue, type));
            }

            dbCommand.ExecuteNonQuery();
        }

        /// <summary>
        /// Метод удаления записей из таблицы 
        /// </summary>
        public void DeleteRow(string tableName, DataGridViewRow row)
        {
            DataTable schema = GetSchema(tableName);

            // Формирование запроса
            StringBuilder query = new StringBuilder($"DELETE FROM {tableName} WHERE ");
            for (int i = 0; i < schema.Rows.Count; i++)
            {
                query.Append($"{schema.Rows[i][0]}=@par{i}");
                if (i < schema.Rows.Count - 1) query.Append(" AND ");
            }
            query.Append(";");

            OleDbCommand dbCommand = new OleDbCommand(query.ToString(), dbConnection);

            // Заполнение параметров
            for (int i = 0; i < schema.Rows.Count; i++)
            {
                Type type = schema.Rows[i][5] as Type;
                dbCommand.Parameters.Add($"@par{i}", Convert.ChangeType(row.Cells[i].Value, type));
            }

            dbCommand.ExecuteNonQuery();
        }

        /// <summary>
        /// Метод возврающий отсортированную таблицу
        /// </summary>
        /// <param name="tableName">Название таблицы</param>
        /// <param name="field">Поле</param>
        /// <returns>Курсор с отсортрованной таблицей</returns>
        public OleDbDataReader OrderBy(string tableName, string field)
        {
            string query = $"SELECT * FROM {tableName} ORDER BY {field} DESC;";
            OleDbCommand dbCommand = new OleDbCommand(query.ToString(), dbConnection);
            return dbCommand.ExecuteReader();
        }
    }
}
