namespace DataBaseApp
{
    partial class Form1
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.toolStrip1 = new System.Windows.Forms.ToolStrip();
            this.buttonChoose = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.buttonOpen = new System.Windows.Forms.ToolStripButton();
            this.buttonClose = new System.Windows.Forms.ToolStripButton();
            this.textBox3 = new System.Windows.Forms.TextBox();
            this.comboBoxSort = new System.Windows.Forms.ComboBox();
            this.buttonSort = new System.Windows.Forms.Button();
            this.buttonDelete = new System.Windows.Forms.Button();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.treeViewTables = new System.Windows.Forms.TreeView();
            this.dataGridView = new System.Windows.Forms.DataGridView();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.dataGridViewQuery = new System.Windows.Forms.DataGridView();
            this.treeViewQueries = new System.Windows.Forms.TreeView();
            this.tabHistory = new System.Windows.Forms.TabPage();
            this.toolStrip3 = new System.Windows.Forms.ToolStrip();
            this.buttonHistorySave = new System.Windows.Forms.ToolStripButton();
            this.buttonHistoryClear = new System.Windows.Forms.ToolStripButton();
            this.textBoxHistory = new System.Windows.Forms.TextBox();
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
            this.directorySearcher1 = new System.DirectoryServices.DirectorySearcher();
            this.splitContainer1 = new System.Windows.Forms.SplitContainer();
            this.splitContainer2 = new System.Windows.Forms.SplitContainer();
            this.buttonQueryLoad = new System.Windows.Forms.ToolStripButton();
            this.buttonQuerySave = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
            this.buttonExecute = new System.Windows.Forms.ToolStripButton();
            this.toolStrip2 = new System.Windows.Forms.ToolStrip();
            this.tabControl1.SuspendLayout();
            this.tabPage1.SuspendLayout();
            this.toolStrip1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView)).BeginInit();
            this.tabPage2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewQuery)).BeginInit();
            this.tabHistory.SuspendLayout();
            this.toolStrip3.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).BeginInit();
            this.splitContainer1.Panel1.SuspendLayout();
            this.splitContainer1.Panel2.SuspendLayout();
            this.splitContainer1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer2)).BeginInit();
            this.splitContainer2.Panel1.SuspendLayout();
            this.splitContainer2.Panel2.SuspendLayout();
            this.splitContainer2.SuspendLayout();
            this.toolStrip2.SuspendLayout();
            this.SuspendLayout();
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add(this.tabPage1);
            this.tabControl1.Controls.Add(this.tabPage2);
            this.tabControl1.Controls.Add(this.tabHistory);
            this.tabControl1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tabControl1.Location = new System.Drawing.Point(0, 0);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(800, 450);
            this.tabControl1.TabIndex = 0;
            // 
            // tabPage1
            // 
            this.tabPage1.Controls.Add(this.splitContainer1);
            this.tabPage1.Controls.Add(this.toolStrip1);
            this.tabPage1.Location = new System.Drawing.Point(4, 22);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(792, 424);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "Таблица";
            // 
            // toolStrip1
            // 
            this.toolStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.buttonChoose,
            this.toolStripSeparator1,
            this.buttonOpen,
            this.buttonClose});
            this.toolStrip1.Location = new System.Drawing.Point(3, 3);
            this.toolStrip1.Name = "toolStrip1";
            this.toolStrip1.Size = new System.Drawing.Size(786, 25);
            this.toolStrip1.TabIndex = 13;
            this.toolStrip1.Text = "toolStrip1";
            // 
            // buttonChoose
            // 
            this.buttonChoose.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.buttonChoose.Image = ((System.Drawing.Image)(resources.GetObject("buttonChoose.Image")));
            this.buttonChoose.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.buttonChoose.Name = "buttonChoose";
            this.buttonChoose.Size = new System.Drawing.Size(23, 22);
            this.buttonChoose.Text = "Выбрать файл";
            this.buttonChoose.Click += new System.EventHandler(this.buttonChoose_Click);
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(6, 25);
            // 
            // buttonOpen
            // 
            this.buttonOpen.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.buttonOpen.Enabled = false;
            this.buttonOpen.Image = ((System.Drawing.Image)(resources.GetObject("buttonOpen.Image")));
            this.buttonOpen.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.buttonOpen.Name = "buttonOpen";
            this.buttonOpen.Size = new System.Drawing.Size(23, 22);
            this.buttonOpen.Text = "Открыть соединение";
            this.buttonOpen.Click += new System.EventHandler(this.buttonOpen_Click);
            // 
            // buttonClose
            // 
            this.buttonClose.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.buttonClose.Enabled = false;
            this.buttonClose.Image = ((System.Drawing.Image)(resources.GetObject("buttonClose.Image")));
            this.buttonClose.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.buttonClose.Name = "buttonClose";
            this.buttonClose.Size = new System.Drawing.Size(23, 22);
            this.buttonClose.Text = "Закрыть соединение";
            this.buttonClose.Click += new System.EventHandler(this.buttonClose_Click);
            // 
            // textBox3
            // 
            this.textBox3.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.textBox3.BackColor = System.Drawing.SystemColors.Control;
            this.textBox3.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.textBox3.Location = new System.Drawing.Point(8, 287);
            this.textBox3.Name = "textBox3";
            this.textBox3.ReadOnly = true;
            this.textBox3.Size = new System.Drawing.Size(91, 13);
            this.textBox3.TabIndex = 11;
            this.textBox3.Text = "Записи";
            // 
            // comboBoxSort
            // 
            this.comboBoxSort.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.comboBoxSort.Enabled = false;
            this.comboBoxSort.FormattingEnabled = true;
            this.comboBoxSort.Location = new System.Drawing.Point(8, 306);
            this.comboBoxSort.Name = "comboBoxSort";
            this.comboBoxSort.Size = new System.Drawing.Size(113, 21);
            this.comboBoxSort.TabIndex = 10;
            // 
            // buttonSort
            // 
            this.buttonSort.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.buttonSort.Enabled = false;
            this.buttonSort.Location = new System.Drawing.Point(8, 333);
            this.buttonSort.Name = "buttonSort";
            this.buttonSort.Size = new System.Drawing.Size(113, 23);
            this.buttonSort.TabIndex = 9;
            this.buttonSort.Text = "Сортировать";
            this.buttonSort.UseVisualStyleBackColor = true;
            this.buttonSort.Click += new System.EventHandler(this.buttonSort_Click);
            // 
            // buttonDelete
            // 
            this.buttonDelete.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.buttonDelete.Enabled = false;
            this.buttonDelete.Location = new System.Drawing.Point(6, 362);
            this.buttonDelete.Name = "buttonDelete";
            this.buttonDelete.Size = new System.Drawing.Size(115, 23);
            this.buttonDelete.TabIndex = 7;
            this.buttonDelete.Text = "Удалить";
            this.buttonDelete.UseVisualStyleBackColor = true;
            this.buttonDelete.Click += new System.EventHandler(this.buttonDelete_Click);
            // 
            // textBox1
            // 
            this.textBox1.BackColor = System.Drawing.SystemColors.Control;
            this.textBox1.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.textBox1.Location = new System.Drawing.Point(6, 3);
            this.textBox1.Name = "textBox1";
            this.textBox1.ReadOnly = true;
            this.textBox1.Size = new System.Drawing.Size(91, 13);
            this.textBox1.TabIndex = 6;
            this.textBox1.Text = "Таблицы";
            // 
            // treeViewTables
            // 
            this.treeViewTables.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.treeViewTables.Location = new System.Drawing.Point(6, 22);
            this.treeViewTables.Name = "treeViewTables";
            this.treeViewTables.Size = new System.Drawing.Size(115, 259);
            this.treeViewTables.TabIndex = 5;
            this.treeViewTables.AfterSelect += new System.Windows.Forms.TreeViewEventHandler(this.treeViewTables_AfterSelect);
            // 
            // dataGridView
            // 
            this.dataGridView.BackgroundColor = System.Drawing.SystemColors.Window;
            this.dataGridView.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView.Dock = System.Windows.Forms.DockStyle.Fill;
            this.dataGridView.EditMode = System.Windows.Forms.DataGridViewEditMode.EditOnEnter;
            this.dataGridView.Location = new System.Drawing.Point(0, 0);
            this.dataGridView.Name = "dataGridView";
            this.dataGridView.RowHeadersWidth = 82;
            this.dataGridView.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.dataGridView.Size = new System.Drawing.Size(664, 393);
            this.dataGridView.TabIndex = 0;
            this.dataGridView.RowLeave += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView_RowLeave);
            this.dataGridView.UserAddedRow += new System.Windows.Forms.DataGridViewRowEventHandler(this.dataGridView_UserAddedRow);
            // 
            // tabPage2
            // 
            this.tabPage2.Controls.Add(this.splitContainer2);
            this.tabPage2.Controls.Add(this.toolStrip2);
            this.tabPage2.Location = new System.Drawing.Point(4, 22);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.Size = new System.Drawing.Size(792, 424);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "Запросы";
            // 
            // dataGridViewQuery
            // 
            this.dataGridViewQuery.BackgroundColor = System.Drawing.SystemColors.Window;
            this.dataGridViewQuery.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewQuery.Dock = System.Windows.Forms.DockStyle.Fill;
            this.dataGridViewQuery.Location = new System.Drawing.Point(0, 0);
            this.dataGridViewQuery.Name = "dataGridViewQuery";
            this.dataGridViewQuery.RowHeadersVisible = false;
            this.dataGridViewQuery.RowHeadersWidth = 12;
            this.dataGridViewQuery.Size = new System.Drawing.Size(648, 387);
            this.dataGridViewQuery.TabIndex = 1;
            // 
            // treeViewQueries
            // 
            this.treeViewQueries.Dock = System.Windows.Forms.DockStyle.Fill;
            this.treeViewQueries.Location = new System.Drawing.Point(0, 0);
            this.treeViewQueries.Name = "treeViewQueries";
            this.treeViewQueries.Size = new System.Drawing.Size(131, 387);
            this.treeViewQueries.TabIndex = 1;
            this.treeViewQueries.AfterSelect += new System.Windows.Forms.TreeViewEventHandler(this.treeViewQueries_AfterSelect);
            // 
            // tabHistory
            // 
            this.tabHistory.Controls.Add(this.toolStrip3);
            this.tabHistory.Controls.Add(this.textBoxHistory);
            this.tabHistory.Location = new System.Drawing.Point(4, 22);
            this.tabHistory.Name = "tabHistory";
            this.tabHistory.Padding = new System.Windows.Forms.Padding(3);
            this.tabHistory.Size = new System.Drawing.Size(792, 424);
            this.tabHistory.TabIndex = 2;
            this.tabHistory.Text = "История";
            // 
            // toolStrip3
            // 
            this.toolStrip3.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.buttonHistorySave,
            this.buttonHistoryClear});
            this.toolStrip3.Location = new System.Drawing.Point(3, 3);
            this.toolStrip3.Name = "toolStrip3";
            this.toolStrip3.Size = new System.Drawing.Size(786, 25);
            this.toolStrip3.TabIndex = 1;
            this.toolStrip3.Text = "toolStrip3";
            // 
            // buttonHistorySave
            // 
            this.buttonHistorySave.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.buttonHistorySave.Enabled = false;
            this.buttonHistorySave.Image = ((System.Drawing.Image)(resources.GetObject("buttonHistorySave.Image")));
            this.buttonHistorySave.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.buttonHistorySave.Name = "buttonHistorySave";
            this.buttonHistorySave.Size = new System.Drawing.Size(23, 22);
            this.buttonHistorySave.Text = "Сохранить";
            // 
            // buttonHistoryClear
            // 
            this.buttonHistoryClear.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.buttonHistoryClear.Enabled = false;
            this.buttonHistoryClear.Image = ((System.Drawing.Image)(resources.GetObject("buttonHistoryClear.Image")));
            this.buttonHistoryClear.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.buttonHistoryClear.Name = "buttonHistoryClear";
            this.buttonHistoryClear.Size = new System.Drawing.Size(23, 22);
            this.buttonHistoryClear.Text = "Очистить";
            // 
            // textBoxHistory
            // 
            this.textBoxHistory.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.textBoxHistory.Location = new System.Drawing.Point(3, 31);
            this.textBoxHistory.Multiline = true;
            this.textBoxHistory.Name = "textBoxHistory";
            this.textBoxHistory.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.textBoxHistory.Size = new System.Drawing.Size(786, 390);
            this.textBoxHistory.TabIndex = 0;
            // 
            // openFileDialog1
            // 
            this.openFileDialog1.Filter = "Access Files|*.mdb;*.accdb|All files|*.*";
            // 
            // directorySearcher1
            // 
            this.directorySearcher1.ClientTimeout = System.TimeSpan.Parse("-00:00:01");
            this.directorySearcher1.ServerPageTimeLimit = System.TimeSpan.Parse("-00:00:01");
            this.directorySearcher1.ServerTimeLimit = System.TimeSpan.Parse("-00:00:01");
            // 
            // splitContainer1
            // 
            this.splitContainer1.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.splitContainer1.Location = new System.Drawing.Point(0, 31);
            this.splitContainer1.Name = "splitContainer1";
            // 
            // splitContainer1.Panel1
            // 
            this.splitContainer1.Panel1.Controls.Add(this.textBox1);
            this.splitContainer1.Panel1.Controls.Add(this.treeViewTables);
            this.splitContainer1.Panel1.Controls.Add(this.buttonDelete);
            this.splitContainer1.Panel1.Controls.Add(this.buttonSort);
            this.splitContainer1.Panel1.Controls.Add(this.comboBoxSort);
            this.splitContainer1.Panel1.Controls.Add(this.textBox3);
            // 
            // splitContainer1.Panel2
            // 
            this.splitContainer1.Panel2.Controls.Add(this.dataGridView);
            this.splitContainer1.Size = new System.Drawing.Size(792, 393);
            this.splitContainer1.SplitterDistance = 124;
            this.splitContainer1.TabIndex = 14;
            // 
            // splitContainer2
            // 
            this.splitContainer2.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.splitContainer2.Location = new System.Drawing.Point(6, 31);
            this.splitContainer2.Name = "splitContainer2";
            // 
            // splitContainer2.Panel1
            // 
            this.splitContainer2.Panel1.Controls.Add(this.treeViewQueries);
            // 
            // splitContainer2.Panel2
            // 
            this.splitContainer2.Panel2.Controls.Add(this.dataGridViewQuery);
            this.splitContainer2.Size = new System.Drawing.Size(783, 387);
            this.splitContainer2.SplitterDistance = 131;
            this.splitContainer2.TabIndex = 4;
            // 
            // buttonQueryLoad
            // 
            this.buttonQueryLoad.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.buttonQueryLoad.Enabled = false;
            this.buttonQueryLoad.Image = ((System.Drawing.Image)(resources.GetObject("buttonQueryLoad.Image")));
            this.buttonQueryLoad.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.buttonQueryLoad.Name = "buttonQueryLoad";
            this.buttonQueryLoad.Size = new System.Drawing.Size(23, 22);
            this.buttonQueryLoad.Text = "Загрузить запрос";
            // 
            // buttonQuerySave
            // 
            this.buttonQuerySave.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.buttonQuerySave.Enabled = false;
            this.buttonQuerySave.Image = ((System.Drawing.Image)(resources.GetObject("buttonQuerySave.Image")));
            this.buttonQuerySave.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.buttonQuerySave.Name = "buttonQuerySave";
            this.buttonQuerySave.Size = new System.Drawing.Size(23, 22);
            this.buttonQuerySave.Text = "Сохранить запрос";
            // 
            // toolStripSeparator2
            // 
            this.toolStripSeparator2.Name = "toolStripSeparator2";
            this.toolStripSeparator2.Size = new System.Drawing.Size(6, 25);
            // 
            // buttonExecute
            // 
            this.buttonExecute.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.buttonExecute.Enabled = false;
            this.buttonExecute.Image = ((System.Drawing.Image)(resources.GetObject("buttonExecute.Image")));
            this.buttonExecute.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.buttonExecute.Name = "buttonExecute";
            this.buttonExecute.Size = new System.Drawing.Size(23, 22);
            this.buttonExecute.Text = "Выполнить";
            this.buttonExecute.Click += new System.EventHandler(this.buttonExecute_Click);
            // 
            // toolStrip2
            // 
            this.toolStrip2.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.buttonQueryLoad,
            this.buttonQuerySave,
            this.toolStripSeparator2,
            this.buttonExecute});
            this.toolStrip2.Location = new System.Drawing.Point(3, 3);
            this.toolStrip2.Name = "toolStrip2";
            this.toolStrip2.Size = new System.Drawing.Size(786, 25);
            this.toolStrip2.TabIndex = 3;
            this.toolStrip2.Text = "toolStrip2";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.tabControl1);
            this.MinimumSize = new System.Drawing.Size(211, 295);
            this.Name = "Form1";
            this.Text = "Access Editor";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.tabControl1.ResumeLayout(false);
            this.tabPage1.ResumeLayout(false);
            this.tabPage1.PerformLayout();
            this.toolStrip1.ResumeLayout(false);
            this.toolStrip1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView)).EndInit();
            this.tabPage2.ResumeLayout(false);
            this.tabPage2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewQuery)).EndInit();
            this.tabHistory.ResumeLayout(false);
            this.tabHistory.PerformLayout();
            this.toolStrip3.ResumeLayout(false);
            this.toolStrip3.PerformLayout();
            this.splitContainer1.Panel1.ResumeLayout(false);
            this.splitContainer1.Panel1.PerformLayout();
            this.splitContainer1.Panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer1)).EndInit();
            this.splitContainer1.ResumeLayout(false);
            this.splitContainer2.Panel1.ResumeLayout(false);
            this.splitContainer2.Panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.splitContainer2)).EndInit();
            this.splitContainer2.ResumeLayout(false);
            this.toolStrip2.ResumeLayout(false);
            this.toolStrip2.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion
        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.DataGridView dataGridView;
        private System.Windows.Forms.TabPage tabPage2;
        private System.Windows.Forms.OpenFileDialog openFileDialog1;
        private System.Windows.Forms.TreeView treeViewTables;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.TabPage tabHistory;
        private System.Windows.Forms.TextBox textBoxHistory;
        private System.Windows.Forms.Button buttonDelete;
        private System.Windows.Forms.ComboBox comboBoxSort;
        private System.Windows.Forms.Button buttonSort;
        private System.Windows.Forms.DataGridView dataGridViewQuery;
        private System.DirectoryServices.DirectorySearcher directorySearcher1;
        private System.Windows.Forms.TreeView treeViewQueries;
        private System.Windows.Forms.TextBox textBox3;
        private System.Windows.Forms.ToolStrip toolStrip1;
        private System.Windows.Forms.ToolStripButton buttonChoose;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
        private System.Windows.Forms.ToolStripButton buttonOpen;
        private System.Windows.Forms.ToolStripButton buttonClose;
        private System.Windows.Forms.ToolStrip toolStrip3;
        private System.Windows.Forms.ToolStripButton buttonHistoryClear;
        private System.Windows.Forms.ToolStripButton buttonHistorySave;
        private System.Windows.Forms.SplitContainer splitContainer1;
        private System.Windows.Forms.SplitContainer splitContainer2;
        private System.Windows.Forms.ToolStrip toolStrip2;
        private System.Windows.Forms.ToolStripButton buttonQueryLoad;
        private System.Windows.Forms.ToolStripButton buttonQuerySave;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator2;
        private System.Windows.Forms.ToolStripButton buttonExecute;
    }
}
