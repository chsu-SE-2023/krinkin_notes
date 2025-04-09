#pragma once

namespace Lab1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Clock
	/// </summary>
	public ref class Clock : public System::Windows::Forms::Form
	{
	public:
		Clock(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Clock()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ buttonA;
	private: System::Windows::Forms::Button^ buttonC;
	protected:

	protected:

	private: System::Windows::Forms::Button^ buttonB;

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::DataGridView^ dataGridViewOut;
	private: System::Windows::Forms::TextBox^ stateBox;



	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ yBox;

	private: System::Windows::Forms::TextBox^ commandBox;

	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::DataGridView^ dataGridViewWays;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::DataGridView^ dataGridViewProtocol;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Button^ buttonReset;





	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->buttonA = (gcnew System::Windows::Forms::Button());
			this->buttonC = (gcnew System::Windows::Forms::Button());
			this->buttonB = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->dataGridViewOut = (gcnew System::Windows::Forms::DataGridView());
			this->stateBox = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->yBox = (gcnew System::Windows::Forms::TextBox());
			this->commandBox = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->dataGridViewWays = (gcnew System::Windows::Forms::DataGridView());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->dataGridViewProtocol = (gcnew System::Windows::Forms::DataGridView());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->buttonReset = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewOut))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewWays))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewProtocol))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// buttonA
			// 
			this->buttonA->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->buttonA->Location = System::Drawing::Point(12, 431);
			this->buttonA->Name = L"buttonA";
			this->buttonA->Size = System::Drawing::Size(75, 23);
			this->buttonA->TabIndex = 0;
			this->buttonA->Text = L"A";
			this->buttonA->UseVisualStyleBackColor = true;
			this->buttonA->Click += gcnew System::EventHandler(this, &Clock::buttonA_Click);
			// 
			// buttonC
			// 
			this->buttonC->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->buttonC->Location = System::Drawing::Point(174, 431);
			this->buttonC->Name = L"buttonC";
			this->buttonC->Size = System::Drawing::Size(75, 23);
			this->buttonC->TabIndex = 1;
			this->buttonC->Text = L"C";
			this->buttonC->UseVisualStyleBackColor = true;
			this->buttonC->Click += gcnew System::EventHandler(this, &Clock::buttonC_Click);
			// 
			// buttonB
			// 
			this->buttonB->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->buttonB->Location = System::Drawing::Point(93, 431);
			this->buttonB->Name = L"buttonB";
			this->buttonB->Size = System::Drawing::Size(75, 23);
			this->buttonB->TabIndex = 2;
			this->buttonB->Text = L"B";
			this->buttonB->UseVisualStyleBackColor = true;
			this->buttonB->Click += gcnew System::EventHandler(this, &Clock::buttonB_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1148, 413);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// dataGridViewOut
			// 
			this->dataGridViewOut->AllowUserToAddRows = false;
			this->dataGridViewOut->AllowUserToDeleteRows = false;
			this->dataGridViewOut->AllowUserToResizeRows = false;
			this->dataGridViewOut->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridViewOut->BackgroundColor = System::Drawing::SystemColors::Window;
			this->dataGridViewOut->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridViewOut->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewOut->Location = System::Drawing::Point(22, 189);
			this->dataGridViewOut->Name = L"dataGridViewOut";
			this->dataGridViewOut->RowHeadersWidth = 82;
			this->dataGridViewOut->Size = System::Drawing::Size(536, 90);
			this->dataGridViewOut->TabIndex = 4;
			// 
			// stateBox
			// 
			this->stateBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->stateBox->BackColor = System::Drawing::SystemColors::Window;
			this->stateBox->Location = System::Drawing::Point(528, 435);
			this->stateBox->Name = L"stateBox";
			this->stateBox->ReadOnly = true;
			this->stateBox->Size = System::Drawing::Size(35, 20);
			this->stateBox->TabIndex = 5;
			this->stateBox->Text = L"S0";
			// 
			// textBox2
			// 
			this->textBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->textBox2->BackColor = System::Drawing::SystemColors::Window;
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox2->Cursor = System::Windows::Forms::Cursors::Default;
			this->textBox2->Location = System::Drawing::Point(477, 437);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(45, 13);
			this->textBox2->TabIndex = 6;
			this->textBox2->Text = L"State";
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// textBox3
			// 
			this->textBox3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->textBox3->BackColor = System::Drawing::SystemColors::Window;
			this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox3->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->textBox3->Location = System::Drawing::Point(567, 437);
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->Size = System::Drawing::Size(59, 13);
			this->textBox3->TabIndex = 8;
			this->textBox3->Text = L"Reaction";
			this->textBox3->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// yBox
			// 
			this->yBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->yBox->BackColor = System::Drawing::SystemColors::Window;
			this->yBox->Location = System::Drawing::Point(632, 435);
			this->yBox->Name = L"yBox";
			this->yBox->ReadOnly = true;
			this->yBox->Size = System::Drawing::Size(35, 20);
			this->yBox->TabIndex = 7;
			this->yBox->Text = L"_";
			// 
			// commandBox
			// 
			this->commandBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->commandBox->Location = System::Drawing::Point(727, 433);
			this->commandBox->Name = L"commandBox";
			this->commandBox->Size = System::Drawing::Size(278, 20);
			this->commandBox->TabIndex = 9;
			this->commandBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Clock::commandBox_Enter);
			// 
			// textBox4
			// 
			this->textBox4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->textBox4->BackColor = System::Drawing::SystemColors::Window;
			this->textBox4->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox4->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->textBox4->Location = System::Drawing::Point(673, 437);
			this->textBox4->Margin = System::Windows::Forms::Padding(2);
			this->textBox4->Name = L"textBox4";
			this->textBox4->ReadOnly = true;
			this->textBox4->Size = System::Drawing::Size(50, 13);
			this->textBox4->TabIndex = 10;
			this->textBox4->Text = L"Command";
			this->textBox4->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// textBox5
			// 
			this->textBox5->BackColor = System::Drawing::SystemColors::Window;
			this->textBox5->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox5->Location = System::Drawing::Point(22, 160);
			this->textBox5->Margin = System::Windows::Forms::Padding(2);
			this->textBox5->Name = L"textBox5";
			this->textBox5->ReadOnly = true;
			this->textBox5->Size = System::Drawing::Size(74, 13);
			this->textBox5->TabIndex = 11;
			this->textBox5->Text = L"Outputs Table";
			// 
			// textBox6
			// 
			this->textBox6->BackColor = System::Drawing::SystemColors::Window;
			this->textBox6->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox6->Location = System::Drawing::Point(22, 27);
			this->textBox6->Margin = System::Windows::Forms::Padding(2);
			this->textBox6->Name = L"textBox6";
			this->textBox6->ReadOnly = true;
			this->textBox6->Size = System::Drawing::Size(74, 13);
			this->textBox6->TabIndex = 13;
			this->textBox6->Text = L"Ways Table";
			// 
			// dataGridViewWays
			// 
			this->dataGridViewWays->AllowUserToAddRows = false;
			this->dataGridViewWays->AllowUserToDeleteRows = false;
			this->dataGridViewWays->AllowUserToResizeRows = false;
			this->dataGridViewWays->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridViewWays->BackgroundColor = System::Drawing::SystemColors::Window;
			this->dataGridViewWays->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridViewWays->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewWays->Location = System::Drawing::Point(22, 53);
			this->dataGridViewWays->Name = L"dataGridViewWays";
			this->dataGridViewWays->RowHeadersWidth = 82;
			this->dataGridViewWays->Size = System::Drawing::Size(536, 90);
			this->dataGridViewWays->TabIndex = 12;
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::Window;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Location = System::Drawing::Point(22, 297);
			this->textBox1->Margin = System::Windows::Forms::Padding(2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(74, 13);
			this->textBox1->TabIndex = 15;
			this->textBox1->Text = L"Protocol Table";
			// 
			// dataGridViewProtocol
			// 
			this->dataGridViewProtocol->AllowUserToAddRows = false;
			this->dataGridViewProtocol->AllowUserToDeleteRows = false;
			this->dataGridViewProtocol->AllowUserToResizeRows = false;
			this->dataGridViewProtocol->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridViewProtocol->BackgroundColor = System::Drawing::SystemColors::Window;
			this->dataGridViewProtocol->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridViewProtocol->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewProtocol->ColumnHeadersVisible = false;
			this->dataGridViewProtocol->Location = System::Drawing::Point(22, 325);
			this->dataGridViewProtocol->Name = L"dataGridViewProtocol";
			this->dataGridViewProtocol->RowHeadersWidth = 82;
			this->dataGridViewProtocol->Size = System::Drawing::Size(983, 94);
			this->dataGridViewProtocol->TabIndex = 14;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox2->Location = System::Drawing::Point(574, 27);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(426, 274);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 16;
			this->pictureBox2->TabStop = false;
			// 
			// buttonReset
			// 
			this->buttonReset->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->buttonReset->Location = System::Drawing::Point(255, 431);
			this->buttonReset->Name = L"buttonReset";
			this->buttonReset->Size = System::Drawing::Size(75, 23);
			this->buttonReset->TabIndex = 17;
			this->buttonReset->Text = L"Reset";
			this->buttonReset->UseVisualStyleBackColor = true;
			this->buttonReset->Click += gcnew System::EventHandler(this, &Clock::buttonReset_Click);
			// 
			// Clock
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(1011, 466);
			this->Controls->Add(this->buttonReset);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->dataGridViewProtocol);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->dataGridViewWays);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->commandBox);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->yBox);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->stateBox);
			this->Controls->Add(this->dataGridViewOut);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->buttonB);
			this->Controls->Add(this->buttonC);
			this->Controls->Add(this->buttonA);
			this->MinimumSize = System::Drawing::Size(1027, 505);
			this->Name = L"Clock";
			this->Text = L"Clock";
			this->Load += gcnew System::EventHandler(this, &Clock::Clock_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewOut))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewWays))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewProtocol))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private:

int s = 0;
int y = 0;
int t = 0;

System::String^ get_y() {
	if (y != -1) {
		return "Y" + y;
	}
	return "_";
}

System::String^ get_s() {
	if (y != -1) {
		return "S" + s;
	}
	return "_";
}

System::Void add_cell(char command, int state, int proto_len) {
	/*
	* Функция, добавляющая новую ячейку в каждую таблицу по команде
	*/
	switch (command) {
	case 'a': { 
		this->dataGridViewWays->Rows[0]->Cells[state]->Value = get_s();
		this->dataGridViewOut->Rows[0]->Cells[state]->Value = get_y();
		this->dataGridViewProtocol->Rows[1]->Cells[proto_len-1]->Value = "X1 (a)";
		break;
	}
	case 'b': { 
		this->dataGridViewWays->Rows[1]->Cells[state]->Value = get_s();
		this->dataGridViewOut->Rows[1]->Cells[state]->Value = get_y();
		this->dataGridViewProtocol->Rows[1]->Cells[proto_len-1]->Value = "X2 (b)";
		break;
	}
	case 'c': { 
		this->dataGridViewWays->Rows[2]->Cells[state]->Value = get_s();
		this->dataGridViewOut->Rows[2]->Cells[state]->Value = get_y();
		this->dataGridViewProtocol->Rows[1]->Cells[proto_len-1]->Value = "X3 (c)";
		break;
	}
	}

	if (y != -1) {
		// Выполняется если символ допустимый
		this->dataGridViewProtocol->Rows[0]->Cells[proto_len - 1]->Value = "t" + t;
		this->dataGridViewProtocol->Rows[2]->Cells[proto_len - 1]->Value = "S" + state;
		this->dataGridViewProtocol->Rows[3]->Cells[proto_len - 1]->Value = get_y();

		this->dataGridViewProtocol->Rows[0]->Cells[proto_len]->Value = "t" + (t + 1);
		this->dataGridViewProtocol->Rows[2]->Cells[proto_len]->Value = get_s();
	}
	else {
		throw_error();
	}
}

System::Void make_table(DataGridView^ table) {
	/*
	* Функция инициализирующая пустую таблицу 
	*/
	table->ColumnCount = 10;
	table->Rows->Add(3);
	table->Rows[0]->HeaderCell->Value = "X1 (a)";
	table->Rows[1]->HeaderCell->Value = "X2 (b)";
	table->Rows[2]->HeaderCell->Value = "X3 (c)";
	for (int i = 0; i < table->ColumnCount; i++)
		table->Columns[i]->Name = "S" + i;
}

System::Void clear_table(DataGridView^ table) {
	/*
	* Функция, очищающая ячейки таблицы
	*/
	for (int i = 0; i < table->RowCount; i++)
		for (int j = 0; j < table->ColumnCount; j++)
			table->Rows[i]->Cells[j]->Value = "";
}

System::Void reset() {
	/*
	* Функция, возвращающая программу в первоначальное состояние
	*/
	s = 0;
	y = 0;
	t = 0;
	stateBox->Text = "S0";
	yBox->Text = "_";
	commandBox->Text = "";
	clear_table(this->dataGridViewProtocol);
	this->dataGridViewProtocol->ColumnCount = 1;
}

System::Void throw_error() {
	/*
	* Функция, открывающая окно с ошибкой и вызывающая reset()
	*/
	MessageBox::Show("Error: Wrong input character!");
	reset();
}

System::Void process_command(char command) {
	/*
	* Функция, обрабатывающая следующее состояние автомата по команде
	*/
	int prev_s = s;
	switch (s) {
	case 0: {
		switch (command) {
		case 'a': { s = 1; y = 1; break; };
		case 'b': { y = -1; break; };
		case 'c': { s = 2; y = 2; break; };
		}
		break;
	}
	case 1: {
		switch (command) {
		case 'a': { s = 0; y = 1; break; };
		case 'b': { s = 8; y = 5; break; };
		case 'c': { s = 9; y = 6; break; };
		}
		break;
	}
	case 2: {
		switch (command) {
		case 'a': { s = 3; y = 3; break; };
		case 'b': { s = 2; y = 4; break; };
		case 'c': { y = -1; break; };
		}
		break;
	}
	case 3: {
		switch (command) {
		case 'a': { s = 4; y = 3; break; };
		case 'b': { s = 3; y = 4; break; };
		case 'c': { y = -1; break; };
		}
		break;
	}
	case 4: {
		switch (command) {
		case 'a': { s = 5; y = 3; break; };
		case 'b': { s = 4; y = 4; break; };
		case 'c': { y = -1; break; };
		}
		break;
	}
	case 5: {
		switch (command) {
		case 'a': { s = 6; y = 3; break; };
		case 'b': { s = 5; y = 4; break; };
		case 'c': { y = -1; break; };
		}
		break;
	}
	case 6: {
		switch (command) {
		case 'a': { s = 7; y = 3; break; };
		case 'b': { s = 6; y = 4; break; };
		case 'c': { y = -1; break; };
		}
		break;
	}
	case 7: {
		switch (command) {
		case 'a': { s = 0; y = 1; break; };
		case 'b': { s = 7; y = 4; break; };
		case 'c': { y = -1; break; };
		}
		break;
	}
	case 8: {
		switch (command) {
		case 'a': { y = -1; break; };
		case 'b': { s = 1; y = 5; break; };
		case 'c': { s = 9; y = 6; break; };
		}
		break;
	}
	case 9: {
		switch (command) {
		case 'a': { y = -1; break; };
		case 'b': { s = 8; y = 5; break; };
		case 'c': { s = 1; y = 6; break; };
		}
		break;
	}
	}
	t++;
	int proto_len = this->dataGridViewProtocol->ColumnCount++;
	add_cell(command, prev_s, proto_len);
	stateBox->Text = "S" + s;
	yBox->Text = get_y();
}

System::Void Clock_Load(System::Object^ sender, System::EventArgs^ e) {
	/*
	* Функция, вызывающаяся при запуске программы
	*/
	this->pictureBox2->Image = Image::FromFile("scheme.png");

	make_table(this->dataGridViewWays);
	make_table(this->dataGridViewOut);

	this->dataGridViewProtocol->ColumnCount = 1;
	this->dataGridViewProtocol->Rows->Add(4);
	this->dataGridViewProtocol->Rows[0]->HeaderCell->Value = "t";
	this->dataGridViewProtocol->Rows[1]->HeaderCell->Value = "X";
	this->dataGridViewProtocol->Rows[2]->HeaderCell->Value = "S";
	this->dataGridViewProtocol->Rows[3]->HeaderCell->Value = "Y";
}

bool error = false;
System::Void commandBox_Enter(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	/*
	* Функция, вызывающаяся при нажатии клавиши Enter/Return на поле ввода.
	*/
	if (error) {
		error = false;
		this->commandBox->Text = "";
	}
	if (e->KeyChar == (char)Keys::Return) {
		for (int i = 0; i < this->commandBox->Text->Length; i++) {
			if (System::Char::ToLower(this->commandBox->Text[i]) == 'a' || 
				System::Char::ToLower(this->commandBox->Text[i]) == 'b' || 
				System::Char::ToLower(this->commandBox->Text[i]) == 'c') {
				// Вызов функции обработки каждого символа последовательности
				process_command(System::Char::ToLower(this->commandBox->Text[i]));
			}
			else
			{
				this->commandBox->Text = "ERROR";
				error = true;
				break;
			}
		}
	}
}

System::Void buttonReset_Click(System::Object^ sender, System::EventArgs^ e) {
	// Нажатие кнопки Reset
	reset();
}
System::Void buttonA_Click(System::Object^ sender, System::EventArgs^ e) {
	// Нажатие кнопки задания символа A
	process_command('a');
}
System::Void buttonB_Click(System::Object^ sender, System::EventArgs^ e) {
	// Нажатие кнопки задания символа B
	process_command('b');
}
System::Void buttonC_Click(System::Object^ sender, System::EventArgs^ e) {
	// Нажатие кнопки задания символа C
	process_command('c');
}
};
}
