using System;
using System.Data;
using System.Data.OleDb;
using System.Windows.Forms;

namespace DataBaseApp
{
    public partial class Form1 : Form
    {

        Database database;

        public Form1()
        {
            InitializeComponent();
        }

        /// <summary>
        /// Добавление новой записи в историю событий
        /// </summary>
        /// <param name="message"></param>
        private void history(string message)
        {
            textBoxHistory.Text += $"[{DateTime.Now.ToLongTimeString()}] {message}\r\n";
        }

        /// <summary>
        /// Диалог подтверждения действия
        /// </summary>
        /// <param name="actionName">Название выполняемого действия</param>
        /// <returns></returns>
        private bool confirm(string actionName)
        {
            var result = MessageBox.Show("Вы уверены?", actionName, MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            return result == DialogResult.Yes;
        }

        private void error(string message)
        {
            MessageBox.Show(message, "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
        }

        /// <summary>
        /// Метод, возвращающий таблицу, полученную курсором при помощи запроса
        /// </summary>
        /// <param name="dbDataReader">Курсор чтения</param>
        /// <returns>Таблица с данными</returns>
        private DataTable getTableFromDbReader(OleDbDataReader dbDataReader)
        {
            DataTable source = new DataTable();

            if (!dbDataReader.IsClosed)
            {
                for (int i = 0; i < dbDataReader.FieldCount; i++)
                {
                    string rowName = dbDataReader.GetName(i);
                    source.Columns.Add(rowName, dbDataReader.GetFieldType(i));
                }

                while (dbDataReader.Read())
                {
                    object[] row = new object[dbDataReader.FieldCount];

                    for (int i = 0; i < dbDataReader.FieldCount; i++)
                    {
                        row[i] = dbDataReader[i];
                    }
                    source.Rows.Add(row);
                }
            }

            return source;
        }

        /// <summary>
        /// Обновление данных в графической таблице
        /// </summary>
        /// <param name="tableName">Название таблицы в базе данных</param>
        private void updateGUI(string tableName)
        {
            clearData();

            string query = "SELECT * FROM " + tableName;
            OleDbDataReader dbDataReader = database.GetOleDbReader(query);

            if (!dbDataReader.IsClosed)
            {
                // Заполнение выпадающего списка сортировки
                for (int i = 0; i < dbDataReader.FieldCount; i++)
                {
                    string rowName = dbDataReader.GetName(i);
                    comboBoxSort.Items.Add(rowName);
                }

                dataGridView.DataSource = getTableFromDbReader(dbDataReader);

                // Отключение сортировки для столбцов
                foreach (DataGridViewColumn column in dataGridView.Columns)
                {
                    column.SortMode = DataGridViewColumnSortMode.NotSortable;
                }
                dbDataReader.Close();
            }

            history($"Обновлено отображение данных для таблицы {tableName}");
        }

        /// <summary>
        /// Очистка данных в графических элементах программы
        /// </summary>
        private void clearData()
        {
            dataGridView.DataSource = null;
            dataGridView.Columns.Clear();
            dataGridView.Rows.Clear();

            comboBoxSort.Items.Clear();
        }

        /// <summary>
        /// Обработчик нажатия на кнопку выбора файла
        /// </summary>
        private void buttonChoose_Click(object sender, EventArgs e)
        {
            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                textBoxFileName.Text = openFileDialog1.FileName;
                buttonOpen.Enabled = true;

                history($"Выбран файл {textBoxFileName.Text}");
            }
        }

        /// <summary>
        /// Обработчик нажатия на кнопку открытия соединения
        /// </summary>
        private void buttonOpen_Click(object sender, EventArgs e)
        {
            if (textBoxFileName.Text != "")
            {
                database = new Database(textBoxFileName.Text);

                history("Открыто соединение с файлом базы");

                // Заполнение списка таблиц
                var tables = database.GetTableList();
                for (int i = 0; i < tables.Rows.Count; i++)
                    treeViewTables.Nodes.Add(tables.Rows[i][2].ToString());

                history("Получен список таблиц");

                buttonClose.Enabled = true;
                buttonDelete.Enabled = true;
                buttonSort.Enabled = true;
                comboBoxSort.Enabled = true;
                buttonExecute.Enabled = true;
            }
        }

        /// <summary>
        /// Обработчик нажатия на кнопку закрыти подключения
        /// </summary>
        private void buttonClose_Click(object sender, EventArgs e)
        {
            database = null;

            clearData();
            treeViewTables.Nodes.Clear();
            buttonClose.Enabled = false;
            buttonDelete.Enabled = false;
            buttonSort.Enabled = false;
            comboBoxSort.Enabled = false;
            buttonExecute.Enabled = false;

            history("Закрыто соединение с файлом базы");
        }

        /// <summary>
        /// Обработчик нажатия на кнопку сортировки
        /// </summary>
        private void buttonSort_Click(object sender, EventArgs e)
        {
            string tableName = treeViewTables.SelectedNode.Text;
            OleDbDataReader dbDataReader = database.OrderBy(tableName, comboBoxSort.SelectedItem.ToString());
            dataGridView.DataSource = getTableFromDbReader(dbDataReader);
            dbDataReader.Close();

            history($"Записи в таблице {tableName} отсортированы по полю {comboBoxSort.SelectedItem}");
        }

        /// <summary>
        /// Обработчик нажатия на кнопку удаления
        /// </summary>
        private void buttonDelete_Click(object sender, EventArgs e)
        {
            if (confirm("Удаление записи(ей)"))
            {
                string tableName = treeViewTables.SelectedNode.Text;
                foreach (DataGridViewRow row in dataGridView.SelectedRows)
                {
                    database.DeleteRow(tableName, row);
                    history($"Удалена запись {row.Index}");
                }
                updateGUI(tableName);
            }
        }

        /// <summary>
        /// Событие, обрабаотывающее нажатие на кнопку "Выполнить" во вкладке "Запрос"
        /// </summary>
        private void buttonExecute_Click(object sender, EventArgs e)
        {
            try
            {
                OleDbDataReader dbDataReader = database.GetOleDbReader(textBoxScript.Text);

                if (!dbDataReader.IsClosed)
                {
                    dataGridViewQuery.DataSource = getTableFromDbReader(dbDataReader);

                    // Отключение сортировки для столбцов
                    foreach (DataGridViewColumn column in dataGridView.Columns)
                    {
                        column.SortMode = DataGridViewColumnSortMode.NotSortable;
                    }
                    dbDataReader.Close();
                }
                history($"Выполнен запрос {treeViewQueries.SelectedNode.Text}");
            }
            catch (System.Data.OleDb.OleDbException err)
            {
                error($"Произошла ошибка выполнения запроса:\n\r{err.Message}");
                history($"Произошла ошибка выполнения запроса {treeViewQueries.SelectedNode.Text}: {err.Message}");
            }
            ;
        }

        /// <summary>
        /// Обработчик события выбора таблицы из списка
        /// </summary>
        private void treeViewTables_AfterSelect(object sender, TreeViewEventArgs e)
        {
            updateGUI(e.Node.Text);
        }

        /// <summary>
        /// Обработчик события добавления в графическую таблицу пользователем новой строки.
        /// Просиходит переход в режим добавления записей
        /// </summary>
        bool addRowMode = false;
        private void dataGridView_UserAddedRow(object sender, DataGridViewRowEventArgs e)
        {
            addRowMode = true;
        }

        /// <summary>
        /// Обработчик события выхода из строки графиеской таблицы, содержащей запись. 
        /// Если был включен режим добавления записей - запись с которой был произведён будет 
        /// записана в базу, если режим добавления не включен, но значения были 
        /// изменены вызывается редактирование записи
        /// </summary>
        private void dataGridView_RowLeave(object sender, DataGridViewCellEventArgs e)
        {
            string tableName = treeViewTables.SelectedNode.Text;
            if (addRowMode)
            {
                try
                {
                    database.AddRow(tableName, dataGridView.Rows[e.RowIndex]);
                    addRowMode = false;
                    history($"Добавлена новая запись ({e.RowIndex})");
                }
                catch (Exception err)
                {
                    error($"Произошла ошибка добавления записи:\n\r{err.Message}");
                    history($"Произошла ошибка добавления записи: {err.Message}");
                }
            }
            else if (dataGridView.IsCurrentRowDirty)
            {
                try
                {
                    database.EditRow(tableName, dataGridView.Rows[e.RowIndex]);
                    history($"Изменена запись с номером {e.RowIndex}");
                }
                catch (Exception err)
                {
                    error($"Произошла ошибка изменения записи с номером {e.RowIndex}:\n\r{err.Message}");
                    history($"Произошла ошибка изменения записи с номером {e.RowIndex}: {err.Message}");
                }
            }
        }

        /// <summary>
        /// Метод, обрабатывающий выбор из списка запросов
        /// Пользовательский запрос сохраняется и восстанавливается при переключении
        /// </summary>
        string customQuery = "";
        bool custom = false;
        private void treeViewQueries_AfterSelect(object sender, TreeViewEventArgs e)
        {
            if (custom)
            {
                customQuery = textBoxScript.Text;
                custom = false;
            }

            switch (treeViewQueries.SelectedNode.Name)
            {
                case "NodeStudents":
                    {
                        textBoxScript.Text = Queries.SurnameDate();
                        break;
                    }

                case "NodeGoodOnesMath":
                    {
                        textBoxScript.Text = Queries.GoodOnesMath();
                        break;
                    }

                case "NodeGoodOnes":
                    {
                        textBoxScript.Text = Queries.GoodOnes();
                        break;
                    }

                case "NodeOldOnes":
                    {
                        textBoxScript.Text = Queries.OldOnes();
                        break;
                    }
                
                case "NodeCustom":
                    {
                        textBoxScript.Text = customQuery;
                        custom = true;
                        break;
                    }
            }
        }

        /// <summary>
        /// Обработчик события загрузки программы
        /// </summary>
        private void Form1_Load(object sender, EventArgs e)
        {
            history("Программа загружена");
        }
    }
}
