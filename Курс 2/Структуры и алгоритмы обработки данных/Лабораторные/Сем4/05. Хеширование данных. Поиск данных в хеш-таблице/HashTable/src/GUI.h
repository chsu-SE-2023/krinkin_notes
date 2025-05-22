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
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::ComboBox^ comboBoxFunc;

	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBoxMostLenght;

	private: System::Windows::Forms::TextBox^ textBox11;
	private: System::Windows::Forms::TextBox^ textBox10;
	private: System::Windows::Forms::ComboBox^ comboBoxMode;


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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
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
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->comboBoxFunc = (gcnew System::Windows::Forms::ComboBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxMostLenght = (gcnew System::Windows::Forms::TextBox());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->comboBoxMode = (gcnew System::Windows::Forms::ComboBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewHash))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownCount))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownA))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownC))->BeginInit();
			this->SuspendLayout();
			// 
			// textBoxSResult
			// 
			this->textBoxSResult->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->textBoxSResult->BackColor = System::Drawing::SystemColors::Control;
			this->textBoxSResult->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBoxSResult->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->textBoxSResult->Location = System::Drawing::Point(451, 55);
			this->textBoxSResult->Margin = System::Windows::Forms::Padding(2);
			this->textBoxSResult->Name = L"textBoxSResult";
			this->textBoxSResult->ReadOnly = true;
			this->textBoxSResult->Size = System::Drawing::Size(386, 17);
			this->textBoxSResult->TabIndex = 7;
			// 
			// textBoxSearch
			// 
			this->textBoxSearch->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->textBoxSearch->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxSearch->Location = System::Drawing::Point(451, 32);
			this->textBoxSearch->Margin = System::Windows::Forms::Padding(2);
			this->textBoxSearch->Name = L"textBoxSearch";
			this->textBoxSearch->Size = System::Drawing::Size(390, 24);
			this->textBoxSearch->TabIndex = 6;
			this->textBoxSearch->TextChanged += gcnew System::EventHandler(this, &GUI::textBoxSearch_TextChanged);
			// 
			// textBox1
			// 
			this->textBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->textBox1->BackColor = System::Drawing::SystemColors::Control;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(453, 11);
			this->textBox1->Margin = System::Windows::Forms::Padding(2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(50, 17);
			this->textBox1->TabIndex = 5;
			this->textBox1->Text = L"Поиск";
			// 
			// dataGridViewHash
			// 
			this->dataGridViewHash->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridViewHash->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridViewHash->BackgroundColor = System::Drawing::SystemColors::Window;
			this->dataGridViewHash->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewHash->Location = System::Drawing::Point(5, 5);
			this->dataGridViewHash->Name = L"dataGridViewHash";
			this->dataGridViewHash->ReadOnly = true;
			this->dataGridViewHash->RowHeadersVisible = false;
			this->dataGridViewHash->RowHeadersWidth = 82;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->dataGridViewHash->RowsDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridViewHash->Size = System::Drawing::Size(441, 480);
			this->dataGridViewHash->TabIndex = 4;
			// 
			// numericUpDownCount
			// 
			this->numericUpDownCount->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->numericUpDownCount->Enabled = false;
			this->numericUpDownCount->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->numericUpDownCount->Location = System::Drawing::Point(453, 280);
			this->numericUpDownCount->Margin = System::Windows::Forms::Padding(2);
			this->numericUpDownCount->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50000, 0, 0, 0 });
			this->numericUpDownCount->Name = L"numericUpDownCount";
			this->numericUpDownCount->Size = System::Drawing::Size(86, 24);
			this->numericUpDownCount->TabIndex = 9;
			this->numericUpDownCount->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 30, 0, 0, 0 });
			this->numericUpDownCount->ValueChanged += gcnew System::EventHandler(this, &GUI::numericUpDownCount_ValueChanged);
			// 
			// textBox3
			// 
			this->textBox3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->textBox3->BackColor = System::Drawing::SystemColors::Control;
			this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox3->Location = System::Drawing::Point(547, 283);
			this->textBox3->Margin = System::Windows::Forms::Padding(2);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(148, 17);
			this->textBox3->TabIndex = 10;
			this->textBox3->Text = L"Количество классов";
			// 
			// textBoxFileName
			// 
			this->textBoxFileName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->textBoxFileName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->textBoxFileName->Location = System::Drawing::Point(451, 461);
			this->textBoxFileName->Margin = System::Windows::Forms::Padding(2);
			this->textBoxFileName->Name = L"textBoxFileName";
			this->textBoxFileName->ReadOnly = true;
			this->textBoxFileName->Size = System::Drawing::Size(302, 24);
			this->textBoxFileName->TabIndex = 11;
			this->textBoxFileName->Text = L"Случайные тестовые данные";
			// 
			// textBox4
			// 
			this->textBox4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->textBox4->BackColor = System::Drawing::SystemColors::Control;
			this->textBox4->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox4->Location = System::Drawing::Point(453, 440);
			this->textBox4->Margin = System::Windows::Forms::Padding(2);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(143, 17);
			this->textBox4->TabIndex = 12;
			this->textBox4->Text = L"Файл с данными";
			// 
			// buttonOpen
			// 
			this->buttonOpen->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->buttonOpen->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonOpen->Location = System::Drawing::Point(757, 461);
			this->buttonOpen->Margin = System::Windows::Forms::Padding(2);
			this->buttonOpen->Name = L"buttonOpen";
			this->buttonOpen->Size = System::Drawing::Size(84, 24);
			this->buttonOpen->TabIndex = 13;
			this->buttonOpen->Text = L"Открыть";
			this->buttonOpen->UseVisualStyleBackColor = true;
			this->buttonOpen->Click += gcnew System::EventHandler(this, &GUI::buttonOpen_Click);
			// 
			// numericUpDownA
			// 
			this->numericUpDownA->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->numericUpDownA->Enabled = false;
			this->numericUpDownA->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->numericUpDownA->Location = System::Drawing::Point(453, 308);
			this->numericUpDownA->Margin = System::Windows::Forms::Padding(2);
			this->numericUpDownA->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50000, 0, 0, 0 });
			this->numericUpDownA->Name = L"numericUpDownA";
			this->numericUpDownA->Size = System::Drawing::Size(86, 24);
			this->numericUpDownA->TabIndex = 14;
			this->numericUpDownA->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 7, 0, 0, 0 });
			this->numericUpDownA->ValueChanged += gcnew System::EventHandler(this, &GUI::numericUpDownA_ValueChanged);
			// 
			// numericUpDownC
			// 
			this->numericUpDownC->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->numericUpDownC->Enabled = false;
			this->numericUpDownC->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->numericUpDownC->Location = System::Drawing::Point(453, 338);
			this->numericUpDownC->Margin = System::Windows::Forms::Padding(2);
			this->numericUpDownC->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50000, 0, 0, 0 });
			this->numericUpDownC->Name = L"numericUpDownC";
			this->numericUpDownC->Size = System::Drawing::Size(86, 24);
			this->numericUpDownC->TabIndex = 15;
			this->numericUpDownC->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 15, 0, 0, 0 });
			this->numericUpDownC->ValueChanged += gcnew System::EventHandler(this, &GUI::numericUpDownC_ValueChanged);
			// 
			// textBox5
			// 
			this->textBox5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->textBox5->BackColor = System::Drawing::SystemColors::Control;
			this->textBox5->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox5->Location = System::Drawing::Point(547, 311);
			this->textBox5->Margin = System::Windows::Forms::Padding(2);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(148, 17);
			this->textBox5->TabIndex = 16;
			this->textBox5->Text = L"Значение a";
			// 
			// textBox6
			// 
			this->textBox6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->textBox6->BackColor = System::Drawing::SystemColors::Control;
			this->textBox6->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox6->Location = System::Drawing::Point(547, 341);
			this->textBox6->Margin = System::Windows::Forms::Padding(2);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(148, 17);
			this->textBox6->TabIndex = 17;
			this->textBox6->Text = L"Значение c";
			// 
			// textBox7
			// 
			this->textBox7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->textBox7->BackColor = System::Drawing::SystemColors::Control;
			this->textBox7->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox7->Location = System::Drawing::Point(453, 259);
			this->textBox7->Margin = System::Windows::Forms::Padding(2);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(86, 17);
			this->textBox7->TabIndex = 18;
			this->textBox7->Text = L"Параметры";
			// 
			// textBox8
			// 
			this->textBox8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->textBox8->BackColor = System::Drawing::SystemColors::Control;
			this->textBox8->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox8->Location = System::Drawing::Point(451, 92);
			this->textBox8->Margin = System::Windows::Forms::Padding(2);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(86, 17);
			this->textBox8->TabIndex = 19;
			this->textBox8->Text = L"Статистика";
			// 
			// textBox9
			// 
			this->textBox9->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->textBox9->BackColor = System::Drawing::SystemColors::Control;
			this->textBox9->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox9->Location = System::Drawing::Point(512, 116);
			this->textBox9->Margin = System::Windows::Forms::Padding(2);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(216, 17);
			this->textBox9->TabIndex = 20;
			this->textBox9->Text = L"Общее число коллизий";
			// 
			// textBoxCollCount
			// 
			this->textBoxCollCount->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->textBoxCollCount->BackColor = System::Drawing::SystemColors::Window;
			this->textBoxCollCount->Enabled = false;
			this->textBoxCollCount->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->textBoxCollCount->Location = System::Drawing::Point(451, 113);
			this->textBoxCollCount->Margin = System::Windows::Forms::Padding(2);
			this->textBoxCollCount->Name = L"textBoxCollCount";
			this->textBoxCollCount->ReadOnly = true;
			this->textBoxCollCount->Size = System::Drawing::Size(57, 24);
			this->textBoxCollCount->TabIndex = 21;
			// 
			// textBoxMostClass
			// 
			this->textBoxMostClass->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->textBoxMostClass->BackColor = System::Drawing::SystemColors::Window;
			this->textBoxMostClass->Enabled = false;
			this->textBoxMostClass->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->textBoxMostClass->Location = System::Drawing::Point(451, 141);
			this->textBoxMostClass->Margin = System::Windows::Forms::Padding(2);
			this->textBoxMostClass->Name = L"textBoxMostClass";
			this->textBoxMostClass->ReadOnly = true;
			this->textBoxMostClass->Size = System::Drawing::Size(57, 24);
			this->textBoxMostClass->TabIndex = 23;
			// 
			// textBox12
			// 
			this->textBox12->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->textBox12->BackColor = System::Drawing::SystemColors::Control;
			this->textBox12->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox12->Location = System::Drawing::Point(512, 144);
			this->textBox12->Margin = System::Windows::Forms::Padding(2);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(216, 17);
			this->textBox12->TabIndex = 22;
			this->textBox12->Text = L"Самый длинный класс";
			// 
			// textBoxFillPercent
			// 
			this->textBoxFillPercent->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->textBoxFillPercent->BackColor = System::Drawing::SystemColors::Window;
			this->textBoxFillPercent->Enabled = false;
			this->textBoxFillPercent->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->textBoxFillPercent->Location = System::Drawing::Point(451, 197);
			this->textBoxFillPercent->Margin = System::Windows::Forms::Padding(2);
			this->textBoxFillPercent->Name = L"textBoxFillPercent";
			this->textBoxFillPercent->ReadOnly = true;
			this->textBoxFillPercent->Size = System::Drawing::Size(57, 24);
			this->textBoxFillPercent->TabIndex = 24;
			// 
			// textBox14
			// 
			this->textBox14->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->textBox14->BackColor = System::Drawing::SystemColors::Control;
			this->textBox14->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox14->Location = System::Drawing::Point(512, 200);
			this->textBox14->Margin = System::Windows::Forms::Padding(2);
			this->textBox14->Name = L"textBox14";
			this->textBox14->Size = System::Drawing::Size(216, 17);
			this->textBox14->TabIndex = 25;
			this->textBox14->Text = L"Процент заполняемости";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// comboBoxFunc
			// 
			this->comboBoxFunc->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->comboBoxFunc->Enabled = false;
			this->comboBoxFunc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBoxFunc->FormattingEnabled = true;
			this->comboBoxFunc->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"h(x)=x%B", L"h(x)=(ax+c)%B" });
			this->comboBoxFunc->Location = System::Drawing::Point(453, 367);
			this->comboBoxFunc->Name = L"comboBoxFunc";
			this->comboBoxFunc->Size = System::Drawing::Size(121, 26);
			this->comboBoxFunc->TabIndex = 26;
			this->comboBoxFunc->Text = L"h(x)=x%B";
			this->comboBoxFunc->SelectedIndexChanged += gcnew System::EventHandler(this, &GUI::comboBoxFunc_SelectedIndexChanged);
			// 
			// textBox2
			// 
			this->textBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->textBox2->BackColor = System::Drawing::SystemColors::Control;
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(579, 371);
			this->textBox2->Margin = System::Windows::Forms::Padding(2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(148, 17);
			this->textBox2->TabIndex = 27;
			this->textBox2->Text = L"Хеш-функция";
			// 
			// textBoxMostLenght
			// 
			this->textBoxMostLenght->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->textBoxMostLenght->BackColor = System::Drawing::SystemColors::Window;
			this->textBoxMostLenght->Enabled = false;
			this->textBoxMostLenght->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->textBoxMostLenght->Location = System::Drawing::Point(451, 169);
			this->textBoxMostLenght->Margin = System::Windows::Forms::Padding(2);
			this->textBoxMostLenght->Name = L"textBoxMostLenght";
			this->textBoxMostLenght->ReadOnly = true;
			this->textBoxMostLenght->Size = System::Drawing::Size(57, 24);
			this->textBoxMostLenght->TabIndex = 29;
			// 
			// textBox11
			// 
			this->textBox11->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->textBox11->BackColor = System::Drawing::SystemColors::Control;
			this->textBox11->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox11->Location = System::Drawing::Point(512, 172);
			this->textBox11->Margin = System::Windows::Forms::Padding(2);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(216, 17);
			this->textBox11->TabIndex = 28;
			this->textBox11->Text = L"Длина самого длинного класса\r\n";
			// 
			// textBox10
			// 
			this->textBox10->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->textBox10->BackColor = System::Drawing::SystemColors::Control;
			this->textBox10->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox10->Location = System::Drawing::Point(580, 403);
			this->textBox10->Margin = System::Windows::Forms::Padding(2);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(148, 17);
			this->textBox10->TabIndex = 31;
			this->textBox10->Text = L"Режим x";
			// 
			// comboBoxMode
			// 
			this->comboBoxMode->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->comboBoxMode->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBoxMode->FormattingEnabled = true;
			this->comboBoxMode->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Целая часть", L"Сумма" });
			this->comboBoxMode->Location = System::Drawing::Point(453, 399);
			this->comboBoxMode->Name = L"comboBoxMode";
			this->comboBoxMode->Size = System::Drawing::Size(121, 26);
			this->comboBoxMode->TabIndex = 30;
			this->comboBoxMode->Text = L"Целая часть";
			this->comboBoxMode->SelectedIndexChanged += gcnew System::EventHandler(this, &GUI::comboBox1_SelectedIndexChanged);
			// 
			// GUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(848, 490);
			this->Controls->Add(this->textBox10);
			this->Controls->Add(this->comboBoxMode);
			this->Controls->Add(this->textBoxMostLenght);
			this->Controls->Add(this->textBox11);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->comboBoxFunc);
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
			this->MinimumSize = System::Drawing::Size(764, 479);
			this->Name = L"GUI";
			this->Padding = System::Windows::Forms::Padding(5);
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

	std::string getMode();
	System::Void updateStats();
	System::Void rebuildTable();
	System::Void GUI_Load(System::Object^ sender, System::EventArgs^ e);
	System::Void textBoxSearch_TextChanged(System::Object^ sender, System::EventArgs^ e);
	System::Void buttonOpen_Click(System::Object^ sender, System::EventArgs^ e);
	System::Void numericUpDownCount_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	System::Void numericUpDownA_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	System::Void numericUpDownC_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	System::Void comboBoxFunc_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
};
}
