using System;
using System.Data;
using System.Data.OleDb;

namespace Lab3
{
	public class DataBase
	{
		private OracleConnection dbConnection = null;

		public DataBase()
		{
			if (dbConnection == null || dbConnection?.State == ConnectionState.Closed)
			{
				// Установка соединения
				string connection = "User Id=system;Password=root;Data source=127.0.0.1;";
				dbConnection = new OleDbConnection(connection);
				dbConnection.Open();
			}
		}

		~DataBase()
		{
			try
			{
				this.dbConnection.Close();
			}
			catch (Exception) { }
		}
	}
}
