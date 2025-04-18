#pragma once
#include "l_analyser.h"
#include <string>
#include <msclr\marshal_cppstd.h>

namespace Analize {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Text;
	using namespace msclr::interop;

	/// <summary>
	/// Summary for GUI
	/// </summary>
	public ref class GUI : public System::Windows::Forms::Form
	{
	public:
		GUI(void)
		{
			InitializeComponent();
			this->analyser = new Analyser();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ sourceBox;
	private: System::Windows::Forms::TextBox^ outBox;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Button^ openFileButton;
	private: System::Windows::Forms::Button^ processButton;
	private: System::Windows::Forms::TextBox^ fileNameBox;
	private: System::Windows::Forms::TextBox^ linesNum;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPageSpaces;
	private: System::Windows::Forms::TabPage^ tabPageLexems;
	private: System::Windows::Forms::TextBox^ outBoxL;
	private: System::Windows::Forms::DataGridView^ dataGridViewKeys;
	private: System::Windows::Forms::DataGridView^ dataGridViewConst;
	private: System::Windows::Forms::DataGridView^ dataGridViewIDs;
	private: System::Windows::Forms::DataGridView^ dataGridViewDelims;
	private: System::Windows::Forms::DataGridView^ dataGridViewSigns;
	private: System::Windows::Forms::DataGridView^ dataGridViewRelative;
	Analyser* analyser;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->sourceBox = (gcnew System::Windows::Forms::TextBox());
			this->outBox = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->openFileButton = (gcnew System::Windows::Forms::Button());
			this->processButton = (gcnew System::Windows::Forms::Button());
			this->fileNameBox = (gcnew System::Windows::Forms::TextBox());
			this->linesNum = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPageSpaces = (gcnew System::Windows::Forms::TabPage());
			this->tabPageLexems = (gcnew System::Windows::Forms::TabPage());
			this->dataGridViewDelims = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewSigns = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewRelative = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewIDs = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewConst = (gcnew System::Windows::Forms::DataGridView());
			this->outBoxL = (gcnew System::Windows::Forms::TextBox());
			this->dataGridViewKeys = (gcnew System::Windows::Forms::DataGridView());
			this->tabControl1->SuspendLayout();
			this->tabPageSpaces->SuspendLayout();
			this->tabPageLexems->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewDelims))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewSigns))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewRelative))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewIDs))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewConst))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewKeys))->BeginInit();
			this->SuspendLayout();
			// 
			// sourceBox
			// 
			this->sourceBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->sourceBox->BackColor = System::Drawing::SystemColors::Control;
			this->sourceBox->Font = (gcnew System::Drawing::Font(L"Courier New", 11));
			this->sourceBox->Location = System::Drawing::Point(7, 6);
			this->sourceBox->Multiline = true;
			this->sourceBox->Name = L"sourceBox";
			this->sourceBox->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->sourceBox->Size = System::Drawing::Size(471, 675);
			this->sourceBox->TabIndex = 0;
			this->sourceBox->WordWrap = false;
			// 
			// outBox
			// 
			this->outBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->outBox->BackColor = System::Drawing::SystemColors::Control;
			this->outBox->Font = (gcnew System::Drawing::Font(L"Courier New", 11));
			this->outBox->Location = System::Drawing::Point(485, 6);
			this->outBox->Multiline = true;
			this->outBox->Name = L"outBox";
			this->outBox->ReadOnly = true;
			this->outBox->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->outBox->Size = System::Drawing::Size(482, 675);
			this->outBox->TabIndex = 1;
			this->outBox->WordWrap = false;
			// 
			// textBox4
			// 
			this->textBox4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->textBox4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(249)), static_cast<System::Int32>(static_cast<System::Byte>(249)),
				static_cast<System::Int32>(static_cast<System::Byte>(249)));
			this->textBox4->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox4->Location = System::Drawing::Point(817, 690);
			this->textBox4->Name = L"textBox4";
			this->textBox4->ReadOnly = true;
			this->textBox4->Size = System::Drawing::Size(149, 17);
			this->textBox4->TabIndex = 3;
			this->textBox4->Text = L"Обработанный текст";
			this->textBox4->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// openFileButton
			// 
			this->openFileButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->openFileButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->openFileButton->Location = System::Drawing::Point(7, 716);
			this->openFileButton->Name = L"openFileButton";
			this->openFileButton->Size = System::Drawing::Size(100, 26);
			this->openFileButton->TabIndex = 4;
			this->openFileButton->Text = L"Открыть файл";
			this->openFileButton->UseVisualStyleBackColor = true;
			this->openFileButton->Click += gcnew System::EventHandler(this, &GUI::openFileButton_Click);
			// 
			// processButton
			// 
			this->processButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->processButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->processButton->Location = System::Drawing::Point(113, 716);
			this->processButton->Name = L"processButton";
			this->processButton->Size = System::Drawing::Size(108, 26);
			this->processButton->TabIndex = 5;
			this->processButton->Text = L"Обработать";
			this->processButton->UseVisualStyleBackColor = true;
			this->processButton->Click += gcnew System::EventHandler(this, &GUI::processButton_Click);
			// 
			// fileNameBox
			// 
			this->fileNameBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->fileNameBox->BackColor = System::Drawing::SystemColors::Window;
			this->fileNameBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->fileNameBox->Location = System::Drawing::Point(7, 687);
			this->fileNameBox->Name = L"fileNameBox";
			this->fileNameBox->ReadOnly = true;
			this->fileNameBox->Size = System::Drawing::Size(471, 24);
			this->fileNameBox->TabIndex = 6;
			this->fileNameBox->Text = L"Source.cpp";
			// 
			// linesNum
			// 
			this->linesNum->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->linesNum->BackColor = System::Drawing::SystemColors::Window;
			this->linesNum->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->linesNum->Location = System::Drawing::Point(484, 687);
			this->linesNum->Name = L"linesNum";
			this->linesNum->ReadOnly = true;
			this->linesNum->Size = System::Drawing::Size(33, 24);
			this->linesNum->TabIndex = 7;
			// 
			// textBox7
			// 
			this->textBox7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->textBox7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(249)), static_cast<System::Int32>(static_cast<System::Byte>(249)),
				static_cast<System::Int32>(static_cast<System::Byte>(249)));
			this->textBox7->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox7->Location = System::Drawing::Point(523, 690);
			this->textBox7->Name = L"textBox7";
			this->textBox7->ReadOnly = true;
			this->textBox7->Size = System::Drawing::Size(118, 17);
			this->textBox7->TabIndex = 8;
			this->textBox7->Text = L"Значащих строк";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// tabControl1
			// 
			this->tabControl1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tabControl1->Controls->Add(this->tabPageSpaces);
			this->tabControl1->Controls->Add(this->tabPageLexems);
			this->tabControl1->ItemSize = System::Drawing::Size(102, 31);
			this->tabControl1->Location = System::Drawing::Point(1, 0);
			this->tabControl1->Multiline = true;
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(981, 788);
			this->tabControl1->TabIndex = 9;
			// 
			// tabPageSpaces
			// 
			this->tabPageSpaces->Controls->Add(this->textBox7);
			this->tabPageSpaces->Controls->Add(this->linesNum);
			this->tabPageSpaces->Controls->Add(this->fileNameBox);
			this->tabPageSpaces->Controls->Add(this->processButton);
			this->tabPageSpaces->Controls->Add(this->openFileButton);
			this->tabPageSpaces->Controls->Add(this->textBox4);
			this->tabPageSpaces->Controls->Add(this->outBox);
			this->tabPageSpaces->Controls->Add(this->sourceBox);
			this->tabPageSpaces->Location = System::Drawing::Point(4, 35);
			this->tabPageSpaces->Name = L"tabPageSpaces";
			this->tabPageSpaces->Padding = System::Windows::Forms::Padding(3);
			this->tabPageSpaces->Size = System::Drawing::Size(973, 749);
			this->tabPageSpaces->TabIndex = 1;
			this->tabPageSpaces->Text = L"Пробелы";
			this->tabPageSpaces->UseVisualStyleBackColor = true;
			// 
			// tabPageLexems
			// 
			this->tabPageLexems->Controls->Add(this->dataGridViewDelims);
			this->tabPageLexems->Controls->Add(this->dataGridViewSigns);
			this->tabPageLexems->Controls->Add(this->dataGridViewRelative);
			this->tabPageLexems->Controls->Add(this->dataGridViewIDs);
			this->tabPageLexems->Controls->Add(this->dataGridViewConst);
			this->tabPageLexems->Controls->Add(this->outBoxL);
			this->tabPageLexems->Controls->Add(this->dataGridViewKeys);
			this->tabPageLexems->Location = System::Drawing::Point(4, 35);
			this->tabPageLexems->Name = L"tabPageLexems";
			this->tabPageLexems->Padding = System::Windows::Forms::Padding(3);
			this->tabPageLexems->Size = System::Drawing::Size(973, 749);
			this->tabPageLexems->TabIndex = 0;
			this->tabPageLexems->Text = L"Лексемы";
			this->tabPageLexems->UseVisualStyleBackColor = true;
			// 
			// dataGridViewDelims
			// 
			this->dataGridViewDelims->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->dataGridViewDelims->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridViewDelims->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(249)),
				static_cast<System::Int32>(static_cast<System::Byte>(249)), static_cast<System::Int32>(static_cast<System::Byte>(249)));
			this->dataGridViewDelims->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridViewDelims->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewDelims->Location = System::Drawing::Point(649, 511);
			this->dataGridViewDelims->Name = L"dataGridViewDelims";
			this->dataGridViewDelims->ReadOnly = true;
			this->dataGridViewDelims->RowHeadersVisible = false;
			this->dataGridViewDelims->RowHeadersWidth = 82;
			this->dataGridViewDelims->RowTemplate->ReadOnly = true;
			this->dataGridViewDelims->Size = System::Drawing::Size(315, 229);
			this->dataGridViewDelims->TabIndex = 8;
			// 
			// dataGridViewSigns
			// 
			this->dataGridViewSigns->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->dataGridViewSigns->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridViewSigns->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(249)),
				static_cast<System::Int32>(static_cast<System::Byte>(249)), static_cast<System::Int32>(static_cast<System::Byte>(249)));
			this->dataGridViewSigns->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridViewSigns->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewSigns->Location = System::Drawing::Point(328, 511);
			this->dataGridViewSigns->Name = L"dataGridViewSigns";
			this->dataGridViewSigns->ReadOnly = true;
			this->dataGridViewSigns->RowHeadersVisible = false;
			this->dataGridViewSigns->RowHeadersWidth = 82;
			this->dataGridViewSigns->RowTemplate->ReadOnly = true;
			this->dataGridViewSigns->Size = System::Drawing::Size(315, 229);
			this->dataGridViewSigns->TabIndex = 7;
			// 
			// dataGridViewRelative
			// 
			this->dataGridViewRelative->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->dataGridViewRelative->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridViewRelative->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(249)),
				static_cast<System::Int32>(static_cast<System::Byte>(249)), static_cast<System::Int32>(static_cast<System::Byte>(249)));
			this->dataGridViewRelative->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridViewRelative->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewRelative->Location = System::Drawing::Point(8, 512);
			this->dataGridViewRelative->Name = L"dataGridViewRelative";
			this->dataGridViewRelative->ReadOnly = true;
			this->dataGridViewRelative->RowHeadersVisible = false;
			this->dataGridViewRelative->RowHeadersWidth = 82;
			this->dataGridViewRelative->RowTemplate->ReadOnly = true;
			this->dataGridViewRelative->Size = System::Drawing::Size(315, 228);
			this->dataGridViewRelative->TabIndex = 6;
			// 
			// dataGridViewIDs
			// 
			this->dataGridViewIDs->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->dataGridViewIDs->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridViewIDs->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(249)),
				static_cast<System::Int32>(static_cast<System::Byte>(249)), static_cast<System::Int32>(static_cast<System::Byte>(249)));
			this->dataGridViewIDs->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridViewIDs->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewIDs->Location = System::Drawing::Point(649, 278);
			this->dataGridViewIDs->Name = L"dataGridViewIDs";
			this->dataGridViewIDs->ReadOnly = true;
			this->dataGridViewIDs->RowHeadersVisible = false;
			this->dataGridViewIDs->RowHeadersWidth = 82;
			this->dataGridViewIDs->RowTemplate->ReadOnly = true;
			this->dataGridViewIDs->Size = System::Drawing::Size(315, 229);
			this->dataGridViewIDs->TabIndex = 5;
			// 
			// dataGridViewConst
			// 
			this->dataGridViewConst->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->dataGridViewConst->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridViewConst->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(249)),
				static_cast<System::Int32>(static_cast<System::Byte>(249)), static_cast<System::Int32>(static_cast<System::Byte>(249)));
			this->dataGridViewConst->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridViewConst->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewConst->Location = System::Drawing::Point(328, 278);
			this->dataGridViewConst->Name = L"dataGridViewConst";
			this->dataGridViewConst->ReadOnly = true;
			this->dataGridViewConst->RowHeadersVisible = false;
			this->dataGridViewConst->RowHeadersWidth = 82;
			this->dataGridViewConst->RowTemplate->ReadOnly = true;
			this->dataGridViewConst->Size = System::Drawing::Size(315, 229);
			this->dataGridViewConst->TabIndex = 4;
			// 
			// outBoxL
			// 
			this->outBoxL->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->outBoxL->BackColor = System::Drawing::SystemColors::Control;
			this->outBoxL->Font = (gcnew System::Drawing::Font(L"Courier New", 11));
			this->outBoxL->Location = System::Drawing::Point(8, 6);
			this->outBoxL->Multiline = true;
			this->outBoxL->Name = L"outBoxL";
			this->outBoxL->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->outBoxL->Size = System::Drawing::Size(956, 266);
			this->outBoxL->TabIndex = 3;
			// 
			// dataGridViewKeys
			// 
			this->dataGridViewKeys->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->dataGridViewKeys->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridViewKeys->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(249)),
				static_cast<System::Int32>(static_cast<System::Byte>(249)), static_cast<System::Int32>(static_cast<System::Byte>(249)));
			this->dataGridViewKeys->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridViewKeys->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewKeys->Location = System::Drawing::Point(8, 278);
			this->dataGridViewKeys->Name = L"dataGridViewKeys";
			this->dataGridViewKeys->ReadOnly = true;
			this->dataGridViewKeys->RowHeadersVisible = false;
			this->dataGridViewKeys->RowHeadersWidth = 82;
			this->dataGridViewKeys->RowTemplate->ReadOnly = true;
			this->dataGridViewKeys->Size = System::Drawing::Size(315, 228);
			this->dataGridViewKeys->TabIndex = 1;
			// 
			// GUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(982, 787);
			this->Controls->Add(this->tabControl1);
			this->MinimumSize = System::Drawing::Size(998, 826);
			this->Name = L"GUI";
			this->Text = L"Анализатор";
			this->Load += gcnew System::EventHandler(this, &GUI::GUI_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPageSpaces->ResumeLayout(false);
			this->tabPageSpaces->PerformLayout();
			this->tabPageLexems->ResumeLayout(false);
			this->tabPageLexems->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewDelims))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewSigns))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewRelative))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewIDs))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewConst))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewKeys))->EndInit();
			this->ResumeLayout(false);

		}

#pragma endregion
private: 

	// Cчётчик строк
	int line = 0;

	// Функция добавляющая в ноер строки в исходный текст
	String^ addLineNum(String^ target, int count) {
		line = 0;
		count = (count + 1).ToString()->Length;
		target = ++line + spaces(count - 1) + "  " + target;
		String^ out = gcnew String("");
		for (int i = 0; i < target->Length; i++) {
			if (target[i] == '\n') {
				out += "\n" + ++line + spaces(count - (line.ToString()->Length)) + "  ";
				continue;
			}
			out += target[i];
		}
		target = out;
		return target;
	}

	// Функция преобразующая System::String в std::string
	std::string to_string(String^ string) {
		msclr::interop::marshal_context context;
		return context.marshal_as<std::string>(string);
	}

	// Функция возвращающая некоторое количество пробелов
	String^ spaces(int count) {
		String^ spaces = gcnew String("");
		for (int i = 0; i < count; i++)
			spaces += " ";
		return spaces;
	}

	// Функция возвращающая есть ли в таблице указанный элемент
	bool findInTable(String^ value, DataGridView^ gridView) {
		for (int i = 0; i < gridView->RowCount; i++) {
			if (gridView->Rows[i]->Cells[1]->Value != nullptr)
				if (gridView->Rows[i]->Cells[1]->Value->ToString() == value)
					return true;
		}
		return false;
	}

	// Функция разделяющая лексемы по таблицам
	System::Void addToTable(int state, String^ lexem) {
		lexem = lexem->Replace("\n", "\\n")->Replace("\r", "\\r");
		switch (state) {
		case 1: { // Ключевое слово
			if (!findInTable(lexem, dataGridViewKeys)) {
				int k_count = this->dataGridViewKeys->RowCount++;
				dataGridViewKeys->Rows[k_count - 1]->Cells[0]->Value = k_count.ToString();
				dataGridViewKeys->Rows[k_count - 1]->Cells[1]->Value = lexem;
				dataGridViewKeys->Rows[k_count - 1]->Cells[2]->Value = lexem;
			}
			break;
		}
		case 2: { // Константа
			if (!findInTable(lexem, dataGridViewConst)) {
				int c_count = this->dataGridViewConst->RowCount++;
				dataGridViewConst->Rows[c_count - 1]->Cells[0]->Value = c_count.ToString();
				dataGridViewConst->Rows[c_count - 1]->Cells[1]->Value = lexem;
				dataGridViewConst->Rows[c_count - 1]->Cells[2]->Value = "const";
			}
			break;
		}
		case 3: { // Идентификатор
			if (!findInTable(lexem, dataGridViewIDs)) {
				int id_count = this->dataGridViewIDs->RowCount++;
				dataGridViewIDs->Rows[id_count - 1]->Cells[0]->Value = id_count.ToString();
				dataGridViewIDs->Rows[id_count - 1]->Cells[1]->Value = lexem;
				dataGridViewIDs->Rows[id_count - 1]->Cells[2]->Value = "id";
			}
			break;
		}
		case 4: { // Оператор отношения
			if (!findInTable(lexem, dataGridViewRelative)) {
				int r_count = this->dataGridViewRelative->RowCount++;
				dataGridViewRelative->Rows[r_count - 1]->Cells[0]->Value = r_count.ToString();
				dataGridViewRelative->Rows[r_count - 1]->Cells[1]->Value = lexem;
				dataGridViewRelative->Rows[r_count - 1]->Cells[2]->Value = lexem;
			}
			break;
		}
		case 5: { // Знак операции
			if (!findInTable(lexem, dataGridViewSigns)) {
				int s_count = this->dataGridViewSigns->RowCount++;
				dataGridViewSigns->Rows[s_count - 1]->Cells[0]->Value = s_count.ToString();
				dataGridViewSigns->Rows[s_count - 1]->Cells[1]->Value = lexem;
				dataGridViewSigns->Rows[s_count - 1]->Cells[2]->Value = lexem;
			}
			break;
		}
		case 6: { // Разделитель
			if (!findInTable(lexem, dataGridViewDelims)) {
				int d_count = this->dataGridViewDelims->RowCount++;
				dataGridViewDelims->Rows[d_count - 1]->Cells[0]->Value = d_count.ToString();
				dataGridViewDelims->Rows[d_count - 1]->Cells[1]->Value = lexem;
				dataGridViewDelims->Rows[d_count - 1]->Cells[2]->Value = lexem;
			}
			break;
		}
		}
	}

	// Обработка нажатия на кнопку "Отрыть файл"
	System::Void openFileButton_Click(System::Object^ sender, System::EventArgs^ e) {
		this->openFileDialog1->FileName = "";
		this->openFileDialog1->ShowDialog();
		this->fileNameBox->Text = openFileDialog1->FileName;

		std::string& source = analyser->readSource(to_string(openFileDialog1->FileName));
		this->sourceBox->Text = gcnew String(source.c_str());
		this->sourceBox->Text = addLineNum(this->sourceBox->Text, analyser->getLineCount(source));
		this->sourceBox->Text = this->sourceBox->Text->Replace("\n", "\r\n");
		this->sourceBox->BackColor = System::Drawing::SystemColors::Window;
	}

	// Обработка нажатия на кнопку "Обработать"
	System::Void processButton_Click(System::Object^ sender, System::EventArgs^ e) {
		// Удаление пробелов и переносов
		this->outBox->BackColor = System::Drawing::SystemColors::Window;
		this->outBoxL->BackColor = System::Drawing::SystemColors::Window;

		const char* stripped = analyser->stripSource().c_str();
		this->outBox->Text = gcnew String(stripped);
		this->outBoxL->Text = this->outBox->Text->Replace("\n", " ");;
		this->outBox->Text = addLineNum(this->outBox->Text, analyser->getLineCount(stripped));
		this->outBox->Text = this->outBox->Text->Replace("\n", "\r\n");
		this->linesNum->Text = analyser->getLineCount(stripped).ToString();

		// Лексический анализ
		const std::string text = analyser->getStripped();
		analyser->clearState();
		char prev = text[0];
		for (int i = 1; i < text.size(); i++) {
			std::string lexem = analyser->lexem_filter(prev, text[i]);
			if (!lexem.empty()) {
#ifdef _DEBUG
				std::cout << "'" << lexem << "' - " << analyser->getState() << std::endl;
#endif
				this->addToTable(analyser->getState(), gcnew String(lexem.c_str()));
				analyser->clearState();
			}
			prev = text[i];
		}
	}

	System::Void GUI_Load(System::Object^ sender, System::EventArgs^ e) {
		// Инициализация таблиц
		array<DataGridView^>^ tables = {
			this->dataGridViewKeys,
			this->dataGridViewConst,
			this->dataGridViewIDs,
			this->dataGridViewRelative,
			this->dataGridViewSigns,
			this->dataGridViewDelims
		};
		for each (DataGridView^ table in tables) {
			table->ColumnCount = 3;
			table->Columns[1]->HeaderCell->Value = "Лексема";
			table->Columns[2]->HeaderCell->Value = "Код";
		}
		this->dataGridViewKeys->Columns[0]->HeaderCell->Value = "10 (Keys)";
		this->dataGridViewConst->Columns[0]->HeaderCell->Value = "20 (Const)";
		this->dataGridViewIDs->Columns[0]->HeaderCell->Value = "30 (IDs)";
		this->dataGridViewRelative->Columns[0]->HeaderCell->Value = "40 (Relative)";
		this->dataGridViewSigns->Columns[0]->HeaderCell->Value = "50 (Signs)";
		this->dataGridViewDelims->Columns[0]->HeaderCell->Value = "60 (Delims)";
	}
};
}
