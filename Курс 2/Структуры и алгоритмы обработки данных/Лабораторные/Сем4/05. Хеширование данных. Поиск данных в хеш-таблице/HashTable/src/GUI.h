#pragma once
#include "hash_table.h"

namespace HashTable {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for GUI
	/// </summary>
	public ref class GUI : public System::Windows::Forms::Form
	{
	public:
		GUI(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
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
	private: System::Windows::Forms::TextBox^ textBoxSResult;
	private: System::Windows::Forms::TextBox^ textBoxSearch;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::DataGridView^ dataGridViewHash;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownCount;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBoxFileName;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Button^ buttonOpen;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownA;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownC;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::TextBox^ textBoxCollCount;
	private: System::Windows::Forms::TextBox^ textBoxMostClass;
	private: System::Windows::Forms::TextBox^ textBox12;
	private: System::Windows::Forms::TextBox^ textBoxFillPercent;
	private: System::Windows::Forms::TextBox^ textBox14;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->textBoxSResult = (gcnew System::Windows::Forms::TextBox());
			this->textBoxSearch = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->dataGridViewHash = (gcnew System::Windows::Forms::DataGridView());
			this->numericUpDownCount = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxFileName = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->buttonOpen = (gcnew System::Windows::Forms::Button());
			this->numericUpDownA = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownC = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxCollCount = (gcnew System::Windows::Forms::TextBox());
			this->textBoxMostClass = (gcnew System::Windows::Forms::TextBox());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxFillPercent = (gcnew System::Windows::Forms::TextBox());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewHash))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownCount))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownA))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownC))->BeginInit();
			this->SuspendLayout();
			// 
			// textBoxSResult
			// 
			this->textBoxSResult->BackColor = System::Drawing::SystemColors::Control;
			this->textBoxSResult->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBoxSResult->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->textBoxSResult->Location = System::Drawing::Point(911, 97);
			this->textBoxSResult->Name = L"textBoxSResult";
			this->textBoxSResult->Size = System::Drawing::Size(772, 33);
			this->textBoxSResult->TabIndex = 7;
			// 
			// textBoxSearch
			// 
			this->textBoxSearch->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxSearch->Location = System::Drawing::Point(911, 51);
			this->textBoxSearch->Name = L"textBoxSearch";
			this->textBoxSearch->Size = System::Drawing::Size(772, 40);
			this->textBoxSearch->TabIndex = 6;
			this->textBoxSearch->TextChanged += gcnew System::EventHandler(this, &GUI::textBoxSearch_TextChanged);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::Control;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(911, 12);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 33);
			this->textBox1->TabIndex = 5;
			this->textBox1->Text = L"Поиск";
			// 
			// dataGridViewHash
			// 
			this->dataGridViewHash->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridViewHash->BackgroundColor = System::Drawing::SystemColors::Window;
			this->dataGridViewHash->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewHash->Dock = System::Windows::Forms::DockStyle::Left;
			this->dataGridViewHash->Location = System::Drawing::Point(0, 0);
			this->dataGridViewHash->Margin = System::Windows::Forms::Padding(6);
			this->dataGridViewHash->Name = L"dataGridViewHash";
			this->dataGridViewHash->ReadOnly = true;
			this->dataGridViewHash->RowHeadersVisible = false;
			this->dataGridViewHash->RowHeadersWidth = 82;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->dataGridViewHash->RowsDefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridViewHash->Size = System::Drawing::Size(902, 942);
			this->dataGridViewHash->TabIndex = 4;
			// 
			// numericUpDownCount
			// 
			this->numericUpDownCount->Enabled = false;
			this->numericUpDownCount->Location = System::Drawing::Point(917, 680);
			this->numericUpDownCount->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50000, 0, 0, 0 });
			this->numericUpDownCount->Name = L"numericUpDownCount";
			this->numericUpDownCount->Size = System::Drawing::Size(171, 31);
			this->numericUpDownCount->TabIndex = 9;
			this->numericUpDownCount->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 30, 0, 0, 0 });
			this->numericUpDownCount->ValueChanged += gcnew System::EventHandler(this, &GUI::numericUpDownCount_ValueChanged);
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::SystemColors::Control;
			this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox3->Location = System::Drawing::Point(1105, 680);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(297, 33);
			this->textBox3->TabIndex = 10;
			this->textBox3->Text = L"Количество классов";
			// 
			// textBoxFileName
			// 
			this->textBoxFileName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->textBoxFileName->Location = System::Drawing::Point(911, 890);
			this->textBoxFileName->Name = L"textBoxFileName";
			this->textBoxFileName->Size = System::Drawing::Size(596, 40);
			this->textBoxFileName->TabIndex = 11;
			this->textBoxFileName->Text = L"Случайные тестовые данные";
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::SystemColors::Control;
			this->textBox4->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox4->Location = System::Drawing::Point(911, 851);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(286, 33);
			this->textBox4->TabIndex = 12;
			this->textBox4->Text = L"Файл с данными";
			// 
			// buttonOpen
			// 
			this->buttonOpen->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonOpen->Location = System::Drawing::Point(1514, 890);
			this->buttonOpen->Name = L"buttonOpen";
			this->buttonOpen->Size = System::Drawing::Size(169, 40);
			this->buttonOpen->TabIndex = 13;
			this->buttonOpen->Text = L"Открыть";
			this->buttonOpen->UseVisualStyleBackColor = true;
			this->buttonOpen->Click += gcnew System::EventHandler(this, &GUI::buttonOpen_Click);
			// 
			// numericUpDownA
			// 
			this->numericUpDownA->Enabled = false;
			this->numericUpDownA->Location = System::Drawing::Point(917, 734);
			this->numericUpDownA->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50000, 0, 0, 0 });
			this->numericUpDownA->Name = L"numericUpDownA";
			this->numericUpDownA->Size = System::Drawing::Size(171, 31);
			this->numericUpDownA->TabIndex = 14;
			this->numericUpDownA->ValueChanged += gcnew System::EventHandler(this, &GUI::numericUpDownA_ValueChanged);
			// 
			// numericUpDownC
			// 
			this->numericUpDownC->Enabled = false;
			this->numericUpDownC->Location = System::Drawing::Point(917, 793);
			this->numericUpDownC->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50000, 0, 0, 0 });
			this->numericUpDownC->Name = L"numericUpDownC";
			this->numericUpDownC->Size = System::Drawing::Size(171, 31);
			this->numericUpDownC->TabIndex = 15;
			this->numericUpDownC->ValueChanged += gcnew System::EventHandler(this, &GUI::numericUpDownC_ValueChanged);
			// 
			// textBox5
			// 
			this->textBox5->BackColor = System::Drawing::SystemColors::Control;
			this->textBox5->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox5->Location = System::Drawing::Point(1105, 734);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(297, 33);
			this->textBox5->TabIndex = 16;
			this->textBox5->Text = L"Значение a";
			// 
			// textBox6
			// 
			this->textBox6->BackColor = System::Drawing::SystemColors::Control;
			this->textBox6->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox6->Location = System::Drawing::Point(1105, 791);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(297, 33);
			this->textBox6->TabIndex = 17;
			this->textBox6->Text = L"Значение c";
			// 
			// textBox7
			// 
			this->textBox7->BackColor = System::Drawing::SystemColors::Control;
			this->textBox7->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox7->Location = System::Drawing::Point(917, 625);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(171, 33);
			this->textBox7->TabIndex = 18;
			this->textBox7->Text = L"Параметры";
			// 
			// textBox8
			// 
			this->textBox8->BackColor = System::Drawing::SystemColors::Control;
			this->textBox8->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox8->Location = System::Drawing::Point(917, 259);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(171, 33);
			this->textBox8->TabIndex = 19;
			this->textBox8->Text = L"Статистика";
			// 
			// textBox9
			// 
			this->textBox9->BackColor = System::Drawing::SystemColors::Control;
			this->textBox9->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox9->Location = System::Drawing::Point(999, 316);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(343, 33);
			this->textBox9->TabIndex = 20;
			this->textBox9->Text = L"Общее число коллизий";
			// 
			// textBoxCollCount
			// 
			this->textBoxCollCount->BackColor = System::Drawing::SystemColors::Window;
			this->textBoxCollCount->Enabled = false;
			this->textBoxCollCount->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->textBoxCollCount->Location = System::Drawing::Point(911, 313);
			this->textBoxCollCount->Name = L"textBoxCollCount";
			this->textBoxCollCount->ReadOnly = true;
			this->textBoxCollCount->Size = System::Drawing::Size(73, 40);
			this->textBoxCollCount->TabIndex = 21;
			// 
			// textBoxMostClass
			// 
			this->textBoxMostClass->BackColor = System::Drawing::SystemColors::Window;
			this->textBoxMostClass->Enabled = false;
			this->textBoxMostClass->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->textBoxMostClass->Location = System::Drawing::Point(911, 368);
			this->textBoxMostClass->Name = L"textBoxMostClass";
			this->textBoxMostClass->ReadOnly = true;
			this->textBoxMostClass->Size = System::Drawing::Size(73, 40);
			this->textBoxMostClass->TabIndex = 23;
			// 
			// textBox12
			// 
			this->textBox12->BackColor = System::Drawing::SystemColors::Control;
			this->textBox12->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox12->Location = System::Drawing::Point(999, 371);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(343, 33);
			this->textBox12->TabIndex = 22;
			this->textBox12->Text = L"Самый длинный класс";
			// 
			// textBoxFillPercent
			// 
			this->textBoxFillPercent->BackColor = System::Drawing::SystemColors::Window;
			this->textBoxFillPercent->Enabled = false;
			this->textBoxFillPercent->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->textBoxFillPercent->Location = System::Drawing::Point(911, 424);
			this->textBoxFillPercent->Name = L"textBoxFillPercent";
			this->textBoxFillPercent->ReadOnly = true;
			this->textBoxFillPercent->Size = System::Drawing::Size(73, 40);
			this->textBoxFillPercent->TabIndex = 24;
			// 
			// textBox14
			// 
			this->textBox14->BackColor = System::Drawing::SystemColors::Control;
			this->textBox14->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox14->Location = System::Drawing::Point(999, 431);
			this->textBox14->Name = L"textBox14";
			this->textBox14->Size = System::Drawing::Size(343, 33);
			this->textBox14->TabIndex = 25;
			this->textBox14->Text = L"Процент заполняемости";
			// 
			// GUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(1695, 942);
			this->Controls->Add(this->textBox14);
			this->Controls->Add(this->textBoxFillPercent);
			this->Controls->Add(this->textBoxMostClass);
			this->Controls->Add(this->textBox12);
			this->Controls->Add(this->textBoxCollCount);
			this->Controls->Add(this->textBox9);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->numericUpDownC);
			this->Controls->Add(this->numericUpDownA);
			this->Controls->Add(this->buttonOpen);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBoxFileName);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->numericUpDownCount);
			this->Controls->Add(this->textBoxSResult);
			this->Controls->Add(this->textBoxSearch);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->dataGridViewHash);
			this->Margin = System::Windows::Forms::Padding(6);
			this->Name = L"GUI";
			this->Text = L"GUI";
			this->Load += gcnew System::EventHandler(this, &GUI::GUI_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewHash))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownCount))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownA))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownC))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: 

	MyHashTable* hashTable;
	array<float>^ data = {};

	System::Void updateStats();
	System::Void rebuildTable();
	System::Void GUI_Load(System::Object^ sender, System::EventArgs^ e);
	System::Void textBoxSearch_TextChanged(System::Object^ sender, System::EventArgs^ e);
	System::Void buttonOpen_Click(System::Object^ sender, System::EventArgs^ e);
	System::Void numericUpDownCount_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	System::Void numericUpDownA_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	System::Void numericUpDownC_ValueChanged(System::Object^ sender, System::EventArgs^ e);
};
}
