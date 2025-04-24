#pragma once
#include <algorithm>
#include <iostream>

namespace Lab4 {

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

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::TextBox^ stateBox;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ commandBox;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::DataGridView^ dataGridViewProtocol;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Button^ buttonReset;
	private: System::Windows::Forms::TextBox^ combTextBox;
	private: System::Windows::Forms::DataGridView^ dataGridViewSequence;
	private: System::Windows::Forms::DataGridView^ dataGridViewTrans;


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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->stateBox = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->commandBox = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->dataGridViewProtocol = (gcnew System::Windows::Forms::DataGridView());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->buttonReset = (gcnew System::Windows::Forms::Button());
			this->combTextBox = (gcnew System::Windows::Forms::TextBox());
			this->dataGridViewSequence = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTrans = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewProtocol))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewSequence))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewTrans))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(10, 12);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1734, 790);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// stateBox
			// 
			this->stateBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->stateBox->BackColor = System::Drawing::SystemColors::Window;
			this->stateBox->Location = System::Drawing::Point(892, 823);
			this->stateBox->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->stateBox->Name = L"stateBox";
			this->stateBox->ReadOnly = true;
			this->stateBox->Size = System::Drawing::Size(66, 31);
			this->stateBox->TabIndex = 5;
			this->stateBox->Text = L"S0";
			// 
			// textBox2
			// 
			this->textBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->textBox2->BackColor = System::Drawing::SystemColors::Window;
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox2->Cursor = System::Windows::Forms::Cursors::Default;
			this->textBox2->Location = System::Drawing::Point(772, 831);
			this->textBox2->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(108, 24);
			this->textBox2->TabIndex = 6;
			this->textBox2->Text = L"Состояние";
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// commandBox
			// 
			this->commandBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->commandBox->Location = System::Drawing::Point(1190, 823);
			this->commandBox->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->commandBox->Name = L"commandBox";
			this->commandBox->Size = System::Drawing::Size(552, 31);
			this->commandBox->TabIndex = 9;
			this->commandBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Clock::commandBox_Enter);
			// 
			// textBox4
			// 
			this->textBox4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->textBox4->BackColor = System::Drawing::SystemColors::Window;
			this->textBox4->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox4->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->textBox4->Location = System::Drawing::Point(964, 830);
			this->textBox4->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox4->Name = L"textBox4";
			this->textBox4->ReadOnly = true;
			this->textBox4->Size = System::Drawing::Size(216, 24);
			this->textBox4->TabIndex = 10;
			this->textBox4->Text = L"Последовательность";
			this->textBox4->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::Window;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Location = System::Drawing::Point(22, 573);
			this->textBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(202, 24);
			this->textBox1->TabIndex = 15;
			this->textBox1->Text = L"Таблица протокола";
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
			this->dataGridViewProtocol->Location = System::Drawing::Point(24, 625);
			this->dataGridViewProtocol->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->dataGridViewProtocol->MinimumSize = System::Drawing::Size(1708, 131);
			this->dataGridViewProtocol->Name = L"dataGridViewProtocol";
			this->dataGridViewProtocol->RowHeadersWidth = 82;
			this->dataGridViewProtocol->Size = System::Drawing::Size(1708, 169);
			this->dataGridViewProtocol->TabIndex = 14;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox2->Location = System::Drawing::Point(22, 21);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(852, 527);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 16;
			this->pictureBox2->TabStop = false;
			// 
			// buttonReset
			// 
			this->buttonReset->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->buttonReset->Location = System::Drawing::Point(10, 823);
			this->buttonReset->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->buttonReset->Name = L"buttonReset";
			this->buttonReset->Size = System::Drawing::Size(150, 44);
			this->buttonReset->TabIndex = 17;
			this->buttonReset->Text = L"Сброс";
			this->buttonReset->UseVisualStyleBackColor = true;
			this->buttonReset->Click += gcnew System::EventHandler(this, &Clock::buttonReset_Click);
			// 
			// combTextBox
			// 
			this->combTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->combTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->combTextBox->Location = System::Drawing::Point(530, 831);
			this->combTextBox->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->combTextBox->Name = L"combTextBox";
			this->combTextBox->Size = System::Drawing::Size(230, 24);
			this->combTextBox->TabIndex = 18;
			// 
			// dataGridViewSequence
			// 
			this->dataGridViewSequence->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->dataGridViewSequence->BackgroundColor = System::Drawing::SystemColors::Window;
			this->dataGridViewSequence->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridViewSequence->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewSequence->Location = System::Drawing::Point(884, 21);
			this->dataGridViewSequence->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->dataGridViewSequence->Name = L"dataGridViewSequence";
			this->dataGridViewSequence->ReadOnly = true;
			this->dataGridViewSequence->RowHeadersVisible = false;
			this->dataGridViewSequence->RowHeadersWidth = 82;
			this->dataGridViewSequence->RowTemplate->Height = 20;
			this->dataGridViewSequence->Size = System::Drawing::Size(444, 527);
			this->dataGridViewSequence->TabIndex = 19;
			// 
			// dataGridViewTrans
			// 
			this->dataGridViewTrans->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->dataGridViewTrans->BackgroundColor = System::Drawing::SystemColors::Window;
			this->dataGridViewTrans->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridViewTrans->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewTrans->Location = System::Drawing::Point(1336, 21);
			this->dataGridViewTrans->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->dataGridViewTrans->Name = L"dataGridViewTrans";
			this->dataGridViewTrans->ReadOnly = true;
			this->dataGridViewTrans->RowHeadersVisible = false;
			this->dataGridViewTrans->RowHeadersWidth = 82;
			this->dataGridViewTrans->RowTemplate->Height = 20;
			this->dataGridViewTrans->Size = System::Drawing::Size(396, 527);
			this->dataGridViewTrans->TabIndex = 20;
			// 
			// Clock
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(1760, 879);
			this->Controls->Add(this->dataGridViewTrans);
			this->Controls->Add(this->dataGridViewSequence);
			this->Controls->Add(this->combTextBox);
			this->Controls->Add(this->buttonReset);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->dataGridViewProtocol);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->commandBox);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->stateBox);
			this->Controls->Add(this->pictureBox1);
			this->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->Name = L"Clock";
			this->Text = L"Clock";
			this->Load += gcnew System::EventHandler(this, &Clock::Clock_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewProtocol))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewSequence))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewTrans))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private:

	int s = 0;
	int t = 0;
	int right = 0;
	int n_right = 0;
	bool manual = false;

	System::String^ GetS() {
		return "S" + s;
	}

	System::Void Reset() {
		/*
		* Функция, возвращающая программу в первоначальное состояние
		*/
		s = 0; t = 0; right = 0; n_right = 0;
		stateBox->Text = "S0";
		commandBox->Text = "";
		combTextBox->Text = "";
		ClearTable(this->dataGridViewProtocol);
		ClearTable(this->dataGridViewSequence);
		this->dataGridViewProtocol->ColumnCount = 1;
		this->dataGridViewSequence->RowCount = 1;
	}

	System::Void ClearTable(DataGridView^ table) {
		/*
		* Функция, очищающая ячейки таблицы
		*/
		for (int i = 0; i < table->RowCount; i++)
			for (int j = 0; j < table->ColumnCount; j++)
				table->Rows[i]->Cells[j]->Value = "";
	}

	System::Void AddCell(char command, int state, int proto_len) {
		/*
		* Функция, добавляющая новую ячейку в каждую таблицу по команде
		*/
		switch (command) {
		case '0': { this->dataGridViewProtocol->Rows[1]->Cells[proto_len - 1]->Value = "X1 (0)"; break; }
		case '1': { this->dataGridViewProtocol->Rows[1]->Cells[proto_len - 1]->Value = "X2 (1)"; break; }
		}

		// Выполняется если символ допустимый
		this->dataGridViewProtocol->Rows[0]->Cells[proto_len - 1]->Value = "t" + t;
		this->dataGridViewProtocol->Rows[2]->Cells[proto_len - 1]->Value = "S" + state;

		this->dataGridViewProtocol->Rows[0]->Cells[proto_len]->Value = "t" + (t + 1);
		this->dataGridViewProtocol->Rows[2]->Cells[proto_len]->Value = GetS();

		if (manual) {
			int count = this->dataGridViewTrans->RowCount++;
			this->dataGridViewTrans->Rows[count - 1]->Cells[0]->Value = "(" + state + ", " + command + ") -> " + GetS();
		}
	}

	System::Void ProcessCommand(char command) {
		/*
		* Функция, обрабатывающая следующее состояние автомата по команде
		*/
		int prev_s = s;
		switch (s) {
		case 0: {
			switch (command) {
			case '0': { s = 1; break; };
			case '1': { s = 2; break; };
			}
			break;
		}
		case 1: {
			switch (command) {
			case '0': { s = 1; break; };
			case '1': { s = 3; break; };
			}
			break;
		}
		case 2: {
			switch (command) {
			case '0': { s = 3; break; };
			case '1': { s = 2; break; };
			}
			break;
		}
		case 3: {
			switch (command) {
			case '0': { s = 3; break; };
			case '1': { s = 3;  break; };
			}
			break;
		}
		}
		t++;
		int proto_len = this->dataGridViewProtocol->ColumnCount++;
		AddCell(command, prev_s, proto_len);
		stateBox->Text = "S" + s;
	}

	System::Void ProcessLexem(String^ lexem) {
		for (int i = 0; i < lexem->Length; i++) {
			if (System::Char::ToLower(lexem[i]) == '0' ||
				System::Char::ToLower(lexem[i]) == '1') {
				// Вызов функции обработки каждого символа последовательности
				ProcessCommand(System::Char::ToLower(lexem[i]));
			}
		}
		if (s == 3) {
			right++;
			dataGridViewSequence->RowCount = std::max({ right, n_right })+1;
			dataGridViewSequence->Rows[right-1]->Cells[0]->Value = lexem;
		}
		else {
			n_right++;
			dataGridViewSequence->RowCount = std::max({ right, n_right })+1;
			dataGridViewSequence->Rows[n_right-1]->Cells[1]->Value = lexem;
		}
	}

	System::Void Clock_Load(System::Object^ sender, System::EventArgs^ e) {
		/*
		* Функция, вызывающаяся при запуске программы
		*/
		this->pictureBox2->Image = Image::FromFile("scheme.png");
		this->dataGridViewProtocol->ColumnCount = 1;
		this->dataGridViewProtocol->Rows->Add(3);
		this->dataGridViewProtocol->Rows[0]->HeaderCell->Value = "t";
		this->dataGridViewProtocol->Rows[1]->HeaderCell->Value = "X";
		this->dataGridViewProtocol->Rows[2]->HeaderCell->Value = "S";

		this->dataGridViewSequence->ColumnCount = 2;
		this->dataGridViewSequence->Columns[0]->Name = "Правильные";
		this->dataGridViewSequence->Columns[1]->Name = "Неправильные";

		this->dataGridViewTrans->ColumnCount = 1;
		this->dataGridViewTrans->Columns[0]->Name = "Переходы";
	}

	bool error = false;
	System::Void commandBox_Enter(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		/*
		* Функция, вызывающаяся при нажатии клавиши Enter/Return на поле ввода.
		*/
		if (e->KeyChar == (char)Keys::Return) {
			ClearTable(this->dataGridViewTrans);
			this->dataGridViewTrans->RowCount = 1;
			if (this->commandBox->Text->Split(' ')->Length > 1) {
				manual = false;
				for each (String ^ lexem in this->commandBox->Text->Split(' ')) {
					ProcessLexem(lexem);
					s = 0;
				}
			}
			else {
				s = 0; t = 0; manual = true;
				ClearTable(this->dataGridViewProtocol);
				this->dataGridViewProtocol->ColumnCount = 1;

				ProcessLexem(this->commandBox->Text);
				if (s == 3) {
					this->combTextBox->Text = "Комбинация верна!";
					this->combTextBox->ForeColor = Color::Green;
				}
				else {
					this->combTextBox->Text = "Комбинация не верна!";
					this->combTextBox->ForeColor = Color::Red;
				}
			}
			this->commandBox->Text = "";
		}
	}

	System::Void buttonReset_Click(System::Object^ sender, System::EventArgs^ e) {
		// Нажатие кнопки Reset
		Reset();
	}
};
}
