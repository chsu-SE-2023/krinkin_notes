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
			this.components = new System.ComponentModel.Container();
			this.dataGridView1 = new System.Windows.Forms.DataGridView();
			this.dataSet1 = new DataBaseApp.DataSet1();
			this.dataSet1BindingSource = new System.Windows.Forms.BindingSource(this.components);
			this.таблица1BindingSource = new System.Windows.Forms.BindingSource(this.components);
			this.таблица1TableAdapter = new DataBaseApp.DataSet1TableAdapters.Таблица1TableAdapter();
			this.фамилияDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.датаРожденияDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.математикаDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.информатикаDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.иностранныйDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
			this.полDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
			((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.dataSet1)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.dataSet1BindingSource)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.таблица1BindingSource)).BeginInit();
			this.SuspendLayout();
			// 
			// dataGridView1
			// 
			this.dataGridView1.AutoGenerateColumns = false;
			this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
			this.dataGridView1.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.фамилияDataGridViewTextBoxColumn,
            this.датаРожденияDataGridViewTextBoxColumn,
            this.математикаDataGridViewTextBoxColumn,
            this.информатикаDataGridViewTextBoxColumn,
            this.иностранныйDataGridViewTextBoxColumn,
            this.полDataGridViewTextBoxColumn});
			this.dataGridView1.DataSource = this.таблица1BindingSource;
			this.dataGridView1.Location = new System.Drawing.Point(12, 12);
			this.dataGridView1.Name = "dataGridView1";
			this.dataGridView1.Size = new System.Drawing.Size(776, 150);
			this.dataGridView1.TabIndex = 0;
			// 
			// dataSet1
			// 
			this.dataSet1.DataSetName = "DataSet1";
			this.dataSet1.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
			// 
			// dataSet1BindingSource
			// 
			this.dataSet1BindingSource.DataSource = this.dataSet1;
			this.dataSet1BindingSource.Position = 0;
			// 
			// таблица1BindingSource
			// 
			this.таблица1BindingSource.DataMember = "Таблица1";
			this.таблица1BindingSource.DataSource = this.dataSet1;
			// 
			// таблица1TableAdapter
			// 
			this.таблица1TableAdapter.ClearBeforeFill = true;
			// 
			// фамилияDataGridViewTextBoxColumn
			// 
			this.фамилияDataGridViewTextBoxColumn.DataPropertyName = "Фамилия";
			this.фамилияDataGridViewTextBoxColumn.HeaderText = "Фамилия";
			this.фамилияDataGridViewTextBoxColumn.Name = "фамилияDataGridViewTextBoxColumn";
			// 
			// датаРожденияDataGridViewTextBoxColumn
			// 
			this.датаРожденияDataGridViewTextBoxColumn.DataPropertyName = "Дата рождения";
			this.датаРожденияDataGridViewTextBoxColumn.HeaderText = "Дата рождения";
			this.датаРожденияDataGridViewTextBoxColumn.Name = "датаРожденияDataGridViewTextBoxColumn";
			// 
			// математикаDataGridViewTextBoxColumn
			// 
			this.математикаDataGridViewTextBoxColumn.DataPropertyName = "Математика";
			this.математикаDataGridViewTextBoxColumn.HeaderText = "Математика";
			this.математикаDataGridViewTextBoxColumn.Name = "математикаDataGridViewTextBoxColumn";
			// 
			// информатикаDataGridViewTextBoxColumn
			// 
			this.информатикаDataGridViewTextBoxColumn.DataPropertyName = "Информатика";
			this.информатикаDataGridViewTextBoxColumn.HeaderText = "Информатика";
			this.информатикаDataGridViewTextBoxColumn.Name = "информатикаDataGridViewTextBoxColumn";
			// 
			// иностранныйDataGridViewTextBoxColumn
			// 
			this.иностранныйDataGridViewTextBoxColumn.DataPropertyName = "Иностранный";
			this.иностранныйDataGridViewTextBoxColumn.HeaderText = "Иностранный";
			this.иностранныйDataGridViewTextBoxColumn.Name = "иностранныйDataGridViewTextBoxColumn";
			// 
			// полDataGridViewTextBoxColumn
			// 
			this.полDataGridViewTextBoxColumn.DataPropertyName = "Пол";
			this.полDataGridViewTextBoxColumn.HeaderText = "Пол";
			this.полDataGridViewTextBoxColumn.Name = "полDataGridViewTextBoxColumn";
			// 
			// Form1
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(800, 450);
			this.Controls.Add(this.dataGridView1);
			this.Name = "Form1";
			this.Text = "Form1";
			this.Load += new System.EventHandler(this.Form1_Load);
			((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.dataSet1)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.dataSet1BindingSource)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.таблица1BindingSource)).EndInit();
			this.ResumeLayout(false);

		}

		#endregion

		private System.Windows.Forms.DataGridView dataGridView1;
		private System.Windows.Forms.BindingSource dataSet1BindingSource;
		private DataSet1 dataSet1;
		private System.Windows.Forms.BindingSource таблица1BindingSource;
		private DataSet1TableAdapters.Таблица1TableAdapter таблица1TableAdapter;
		private System.Windows.Forms.DataGridViewTextBoxColumn фамилияDataGridViewTextBoxColumn;
		private System.Windows.Forms.DataGridViewTextBoxColumn датаРожденияDataGridViewTextBoxColumn;
		private System.Windows.Forms.DataGridViewTextBoxColumn математикаDataGridViewTextBoxColumn;
		private System.Windows.Forms.DataGridViewTextBoxColumn информатикаDataGridViewTextBoxColumn;
		private System.Windows.Forms.DataGridViewTextBoxColumn иностранныйDataGridViewTextBoxColumn;
		private System.Windows.Forms.DataGridViewTextBoxColumn полDataGridViewTextBoxColumn;
	}
}

