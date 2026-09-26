using System;
using System.Collections.Generic;
using System.Data;
using System.Data.OleDb;
using System.Linq;
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
            DataTable dataTable = new DataTable();
            string query = "SELECT * FROM " + tableName;
            OleDbDataAdapter adapter = new OleDbDataAdapter(query, dbConnection);
            adapter.FillSchema(dataTable, SchemaType.Source);
            return dataTable;
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
        /// Метод, проверяющий является ли заданное поле первичным ключом
        /// </summary>
        /// <param name="schema"></param>
        /// <param name="columnName"></param>
        /// <returns></returns>
        public static bool IsPrimaryKey(DataTable schema, string columnName)
        {
            foreach (DataColumn primaryKey in schema.PrimaryKey)
                if (columnName == primaryKey.ColumnName) return true;
            return false;
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
            for (int i = 0; i < schema.Columns.Count; i++)
            {
                query.Append($"{schema.Columns[i].ColumnName}");
                if (i < schema.Columns.Count - 1) query.Append(",");
            }
            query.Append(") VALUES (");
            for (int i = 0; i < schema.Columns.Count; i++)
            {
                query.Append($"@par{i}");
                if (i < schema.Columns.Count - 1) query.Append(",");
            }
            query.Append(");");

            OleDbCommand dbCommand = new OleDbCommand(query.ToString(), dbConnection);

            // Заполнение параметров
            for (int i = 0; i < schema.Columns.Count; i++)
            {
                Type type = schema.Columns[i].DataType;
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
            for (int i = 0; i < schema.Columns.Count; i++)
            {
                if (IsPrimaryKey(schema, schema.Columns[i].ColumnName)) continue;
                query.Append($"[{schema.Columns[i].ColumnName}]=@par{i}_new");
                if (i < schema.Columns.Count - 1) query.Append(",");
            }
            query.Append(" WHERE ");
            for (int i = 0; i < schema.Columns.Count; i++)
            {
                query.Append($"[{schema.Columns[i].ColumnName}]=@par{i}_old");
                if (i < schema.Columns.Count - 1) query.Append(" AND ");
            }
            query.Append(";");

            OleDbCommand dbCommand = new OleDbCommand(query.ToString(), dbConnection);

            // Заполнение параметров
            for (int i = 0; i < schema.Columns.Count; i++)
            {
                if (IsPrimaryKey(schema, schema.Columns[i].ColumnName)) continue;
                Type type = schema.Columns[i].DataType;
                dbCommand.Parameters.Add($"@par{i}_new", Convert.ChangeType(row.Cells[i].EditedFormattedValue, type));
            }
            for (int i = 0; i < schema.Columns.Count; i++)
            {
                Type type = schema.Columns[i].DataType;
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
            for (int i = 0; i < schema.Columns.Count; i++)
            {
                query.Append($"{schema.Columns[i].ColumnName}=@par{i}");
                if (i < schema.Columns.Count - 1) query.Append(" AND ");
            }
            query.Append(";");

            OleDbCommand dbCommand = new OleDbCommand(query.ToString(), dbConnection);

            // Заполнение параметров
            for (int i = 0; i < schema.Columns.Count; i++)
            {
                Type type = schema.Columns[i].DataType;
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

        public Dictionary<string, string> GetQueries()
        {
            Dictionary<string, string> queries = new Dictionary<string, string>();
            DataTable schemaTable = dbConnection.GetOleDbSchemaTable(
                OleDbSchemaGuid.Views,
                new object[] { null, null, null }
            );
            foreach (DataRow row in schemaTable.Rows)
            {
                queries.Add(row["TABLE_NAME"].ToString(), row["VIEW_DEFINITION"].ToString());
            }
            return queries;
        }
    }
}
