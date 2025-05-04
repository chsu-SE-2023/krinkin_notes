#pragma once
#include "l_analyser.h"

namespace Analize {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Text;

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
	private: System::Windows::Forms::Button^ openFileButton;
	private: System::Windows::Forms::Button^ processButton;
	private: System::Windows::Forms::TextBox^ fileNameBox;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPageSource;
	private: System::Windows::Forms::TabPage^ tabPageLexems;
	private: System::Windows::Forms::TextBox^ outBox;
	private: System::Windows::Forms::DataGridView^ dataGridViewKeys;
	private: System::Windows::Forms::DataGridView^ dataGridViewConst;
	private: System::Windows::Forms::DataGridView^ dataGridViewIDs;
	private: System::Windows::Forms::DataGridView^ dataGridViewDelims;
	private: System::Windows::Forms::DataGridView^ dataGridViewSigns;
	private: System::Windows::Forms::DataGridView^ dataGridViewRelative;
	private: System::Windows::Forms::TabPage^ codesTab;
	private: System::Windows::Forms::TextBox^ textBoxPName;
	private: System::Windows::Forms::TextBox^ textBoxDName;
	private: System::Windows::Forms::TextBox^ textBoxPseudo;
	private: System::Windows::Forms::TextBox^ textBoxDescript;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ KeysNum;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ KeyLexem;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ KeyCode;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ DelimsNum;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ DelimsLexem;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ DelimsCode;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ SignsNum;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ SignsLexem;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ SignsCode;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ RelativeNum;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ RelativeLexem;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ RelativeCode;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ IDNum;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ IDLexem;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ IDCode;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ConstNum;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ConstLexem;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ConstCode;
		   Analyser* analyser;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->sourceBox = (gcnew System::Windows::Forms::TextBox());
			this->openFileButton = (gcnew System::Windows::Forms::Button());
			this->processButton = (gcnew System::Windows::Forms::Button());
			this->fileNameBox = (gcnew System::Windows::Forms::TextBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPageSource = (gcnew System::Windows::Forms::TabPage());
			this->tabPageLexems = (gcnew System::Windows::Forms::TabPage());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->dataGridViewDelims = (gcnew System::Windows::Forms::DataGridView());
			this->DelimsNum = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->DelimsLexem = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->DelimsCode = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewSigns = (gcnew System::Windows::Forms::DataGridView());
			this->SignsNum = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->SignsLexem = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->SignsCode = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewRelative = (gcnew System::Windows::Forms::DataGridView());
			this->RelativeNum = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->RelativeLexem = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->RelativeCode = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewIDs = (gcnew System::Windows::Forms::DataGridView());
			this->IDNum = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->IDLexem = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->IDCode = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewConst = (gcnew System::Windows::Forms::DataGridView());
			this->ConstNum = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ConstLexem = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ConstCode = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->outBox = (gcnew System::Windows::Forms::TextBox());
			this->dataGridViewKeys = (gcnew System::Windows::Forms::DataGridView());
			this->KeysNum = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->KeyLexem = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->KeyCode = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->codesTab = (gcnew System::Windows::Forms::TabPage());
			this->textBoxPName = (gcnew System::Windows::Forms::TextBox());
			this->textBoxDName = (gcnew System::Windows::Forms::TextBox());
			this->textBoxPseudo = (gcnew System::Windows::Forms::TextBox());
			this->textBoxDescript = (gcnew System::Windows::Forms::TextBox());
			this->tabControl1->SuspendLayout();
			this->tabPageSource->SuspendLayout();
			this->tabPageLexems->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewDelims))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewSigns))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewRelative))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewIDs))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewConst))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewKeys))->BeginInit();
			this->codesTab->SuspendLayout();
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
			this->sourceBox->Size = System::Drawing::Size(958, 675);
			this->sourceBox->TabIndex = 0;
			this->sourceBox->WordWrap = false;
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
			this->fileNameBox->Size = System::Drawing::Size(958, 24);
			this->fileNameBox->TabIndex = 6;
			this->fileNameBox->Text = L"Source.cpp";
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
			this->tabControl1->Controls->Add(this->tabPageSource);
			this->tabControl1->Controls->Add(this->tabPageLexems);
			this->tabControl1->Controls->Add(this->codesTab);
			this->tabControl1->ItemSize = System::Drawing::Size(102, 31);
			this->tabControl1->Location = System::Drawing::Point(1, 0);
			this->tabControl1->Multiline = true;
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(981, 788);
			this->tabControl1->TabIndex = 9;
			// 
			// tabPageSource
			// 
			this->tabPageSource->Controls->Add(this->fileNameBox);
			this->tabPageSource->Controls->Add(this->processButton);
			this->tabPageSource->Controls->Add(this->openFileButton);
			this->tabPageSource->Controls->Add(this->sourceBox);
			this->tabPageSource->Location = System::Drawing::Point(4, 35);
			this->tabPageSource->Name = L"tabPageSource";
			this->tabPageSource->Padding = System::Windows::Forms::Padding(3);
			this->tabPageSource->Size = System::Drawing::Size(973, 749);
			this->tabPageSource->TabIndex = 1;
			this->tabPageSource->Text = L"Исходник";
			this->tabPageSource->UseVisualStyleBackColor = true;
			// 
			// tabPageLexems
			// 
			this->tabPageLexems->Controls->Add(this->textBox1);
			this->tabPageLexems->Controls->Add(this->dataGridViewDelims);
			this->tabPageLexems->Controls->Add(this->dataGridViewSigns);
			this->tabPageLexems->Controls->Add(this->dataGridViewRelative);
			this->tabPageLexems->Controls->Add(this->dataGridViewIDs);
			this->tabPageLexems->Controls->Add(this->dataGridViewConst);
			this->tabPageLexems->Controls->Add(this->outBox);
			this->tabPageLexems->Controls->Add(this->dataGridViewKeys);
			this->tabPageLexems->Location = System::Drawing::Point(4, 35);
			this->tabPageLexems->Name = L"tabPageLexems";
			this->tabPageLexems->Padding = System::Windows::Forms::Padding(3);
			this->tabPageLexems->Size = System::Drawing::Size(973, 749);
			this->tabPageLexems->TabIndex = 0;
			this->tabPageLexems->Text = L"Лексемы";
			this->tabPageLexems->UseVisualStyleBackColor = true;
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(249)), static_cast<System::Int32>(static_cast<System::Byte>(249)),
				static_cast<System::Int32>(static_cast<System::Byte>(249)));
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(8, 7);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(149, 17);
			this->textBox1->TabIndex = 9;
			this->textBox1->Text = L"Обработанный текст";
			// 
			// dataGridViewDelims
			// 
			this->dataGridViewDelims->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->dataGridViewDelims->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridViewDelims->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(249)),
				static_cast<System::Int32>(static_cast<System::Byte>(249)), static_cast<System::Int32>(static_cast<System::Byte>(249)));
			this->dataGridViewDelims->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridViewDelims->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewDelims->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->DelimsNum,
					this->DelimsLexem, this->DelimsCode
			});
			this->dataGridViewDelims->Location = System::Drawing::Point(328, 514);
			this->dataGridViewDelims->Name = L"dataGridViewDelims";
			this->dataGridViewDelims->ReadOnly = true;
			this->dataGridViewDelims->RowHeadersVisible = false;
			this->dataGridViewDelims->RowHeadersWidth = 82;
			this->dataGridViewDelims->RowTemplate->ReadOnly = true;
			this->dataGridViewDelims->Size = System::Drawing::Size(315, 229);
			this->dataGridViewDelims->TabIndex = 8;
			// 
			// DelimsNum
			// 
			this->DelimsNum->HeaderText = L"50 (Delims)";
			this->DelimsNum->Name = L"DelimsNum";
			this->DelimsNum->ReadOnly = true;
			// 
			// DelimsLexem
			// 
			this->DelimsLexem->HeaderText = L"Лексема";
			this->DelimsLexem->Name = L"DelimsLexem";
			this->DelimsLexem->ReadOnly = true;
			// 
			// DelimsCode
			// 
			this->DelimsCode->HeaderText = L"Код";
			this->DelimsCode->Name = L"DelimsCode";
			this->DelimsCode->ReadOnly = true;
			// 
			// dataGridViewSigns
			// 
			this->dataGridViewSigns->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->dataGridViewSigns->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridViewSigns->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(249)),
				static_cast<System::Int32>(static_cast<System::Byte>(249)), static_cast<System::Int32>(static_cast<System::Byte>(249)));
			this->dataGridViewSigns->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridViewSigns->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewSigns->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->SignsNum,
					this->SignsLexem, this->SignsCode
			});
			this->dataGridViewSigns->Location = System::Drawing::Point(8, 514);
			this->dataGridViewSigns->Name = L"dataGridViewSigns";
			this->dataGridViewSigns->ReadOnly = true;
			this->dataGridViewSigns->RowHeadersVisible = false;
			this->dataGridViewSigns->RowHeadersWidth = 82;
			this->dataGridViewSigns->RowTemplate->ReadOnly = true;
			this->dataGridViewSigns->Size = System::Drawing::Size(315, 229);
			this->dataGridViewSigns->TabIndex = 7;
			// 
			// SignsNum
			// 
			this->SignsNum->HeaderText = L"40 (Signs)";
			this->SignsNum->Name = L"SignsNum";
			this->SignsNum->ReadOnly = true;
			// 
			// SignsLexem
			// 
			this->SignsLexem->HeaderText = L"Лексема";
			this->SignsLexem->Name = L"SignsLexem";
			this->SignsLexem->ReadOnly = true;
			// 
			// SignsCode
			// 
			this->SignsCode->HeaderText = L"Код";
			this->SignsCode->Name = L"SignsCode";
			this->SignsCode->ReadOnly = true;
			// 
			// dataGridViewRelative
			// 
			this->dataGridViewRelative->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->dataGridViewRelative->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridViewRelative->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(249)),
				static_cast<System::Int32>(static_cast<System::Byte>(249)), static_cast<System::Int32>(static_cast<System::Byte>(249)));
			this->dataGridViewRelative->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridViewRelative->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewRelative->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->RelativeNum,
					this->RelativeLexem, this->RelativeCode
			});
			this->dataGridViewRelative->Location = System::Drawing::Point(649, 279);
			this->dataGridViewRelative->Name = L"dataGridViewRelative";
			this->dataGridViewRelative->ReadOnly = true;
			this->dataGridViewRelative->RowHeadersVisible = false;
			this->dataGridViewRelative->RowHeadersWidth = 82;
			this->dataGridViewRelative->RowTemplate->ReadOnly = true;
			this->dataGridViewRelative->Size = System::Drawing::Size(315, 228);
			this->dataGridViewRelative->TabIndex = 6;
			// 
			// RelativeNum
			// 
			this->RelativeNum->HeaderText = L"30 (Relative)";
			this->RelativeNum->Name = L"RelativeNum";
			this->RelativeNum->ReadOnly = true;
			// 
			// RelativeLexem
			// 
			this->RelativeLexem->HeaderText = L"Лексема";
			this->RelativeLexem->Name = L"RelativeLexem";
			this->RelativeLexem->ReadOnly = true;
			// 
			// RelativeCode
			// 
			this->RelativeCode->HeaderText = L"Код";
			this->RelativeCode->Name = L"RelativeCode";
			this->RelativeCode->ReadOnly = true;
			// 
			// dataGridViewIDs
			// 
			this->dataGridViewIDs->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->dataGridViewIDs->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridViewIDs->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(249)),
				static_cast<System::Int32>(static_cast<System::Byte>(249)), static_cast<System::Int32>(static_cast<System::Byte>(249)));
			this->dataGridViewIDs->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridViewIDs->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewIDs->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->IDNum,
					this->IDLexem, this->IDCode
			});
			this->dataGridViewIDs->Location = System::Drawing::Point(649, 514);
			this->dataGridViewIDs->Name = L"dataGridViewIDs";
			this->dataGridViewIDs->ReadOnly = true;
			this->dataGridViewIDs->RowHeadersVisible = false;
			this->dataGridViewIDs->RowHeadersWidth = 82;
			this->dataGridViewIDs->RowTemplate->ReadOnly = true;
			this->dataGridViewIDs->Size = System::Drawing::Size(315, 229);
			this->dataGridViewIDs->TabIndex = 5;
			// 
			// IDNum
			// 
			this->IDNum->HeaderText = L"60 (ID)";
			this->IDNum->Name = L"IDNum";
			this->IDNum->ReadOnly = true;
			// 
			// IDLexem
			// 
			this->IDLexem->HeaderText = L"Лексема";
			this->IDLexem->Name = L"IDLexem";
			this->IDLexem->ReadOnly = true;
			// 
			// IDCode
			// 
			this->IDCode->HeaderText = L"Код";
			this->IDCode->Name = L"IDCode";
			this->IDCode->ReadOnly = true;
			// 
			// dataGridViewConst
			// 
			this->dataGridViewConst->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->dataGridViewConst->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridViewConst->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(249)),
				static_cast<System::Int32>(static_cast<System::Byte>(249)), static_cast<System::Int32>(static_cast<System::Byte>(249)));
			this->dataGridViewConst->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridViewConst->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewConst->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->ConstNum,
					this->ConstLexem, this->ConstCode
			});
			this->dataGridViewConst->Location = System::Drawing::Point(328, 278);
			this->dataGridViewConst->Name = L"dataGridViewConst";
			this->dataGridViewConst->ReadOnly = true;
			this->dataGridViewConst->RowHeadersVisible = false;
			this->dataGridViewConst->RowHeadersWidth = 82;
			this->dataGridViewConst->RowTemplate->ReadOnly = true;
			this->dataGridViewConst->Size = System::Drawing::Size(315, 229);
			this->dataGridViewConst->TabIndex = 4;
			// 
			// ConstNum
			// 
			this->ConstNum->HeaderText = L"20 (Const)";
			this->ConstNum->Name = L"ConstNum";
			this->ConstNum->ReadOnly = true;
			// 
			// ConstLexem
			// 
			this->ConstLexem->HeaderText = L"Лексема";
			this->ConstLexem->Name = L"ConstLexem";
			this->ConstLexem->ReadOnly = true;
			// 
			// ConstCode
			// 
			this->ConstCode->HeaderText = L"Код";
			this->ConstCode->Name = L"ConstCode";
			this->ConstCode->ReadOnly = true;
			// 
			// outBox
			// 
			this->outBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->outBox->BackColor = System::Drawing::SystemColors::Control;
			this->outBox->Font = (gcnew System::Drawing::Font(L"Courier New", 11));
			this->outBox->Location = System::Drawing::Point(8, 30);
			this->outBox->Multiline = true;
			this->outBox->Name = L"outBox";
			this->outBox->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->outBox->Size = System::Drawing::Size(956, 242);
			this->outBox->TabIndex = 3;
			// 
			// dataGridViewKeys
			// 
			this->dataGridViewKeys->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->dataGridViewKeys->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridViewKeys->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(249)),
				static_cast<System::Int32>(static_cast<System::Byte>(249)), static_cast<System::Int32>(static_cast<System::Byte>(249)));
			this->dataGridViewKeys->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridViewKeys->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewKeys->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->KeysNum,
					this->KeyLexem, this->KeyCode
			});
			this->dataGridViewKeys->Location = System::Drawing::Point(8, 278);
			this->dataGridViewKeys->Name = L"dataGridViewKeys";
			this->dataGridViewKeys->ReadOnly = true;
			this->dataGridViewKeys->RowHeadersVisible = false;
			this->dataGridViewKeys->RowHeadersWidth = 82;
			this->dataGridViewKeys->RowTemplate->ReadOnly = true;
			this->dataGridViewKeys->Size = System::Drawing::Size(315, 228);
			this->dataGridViewKeys->TabIndex = 1;
			// 
			// KeysNum
			// 
			this->KeysNum->HeaderText = L"10 (Keys)";
			this->KeysNum->Name = L"KeysNum";
			this->KeysNum->ReadOnly = true;
			// 
			// KeyLexem
			// 
			this->KeyLexem->HeaderText = L"Лексема";
			this->KeyLexem->Name = L"KeyLexem";
			this->KeyLexem->ReadOnly = true;
			// 
			// KeyCode
			// 
			this->KeyCode->HeaderText = L"Код";
			this->KeyCode->Name = L"KeyCode";
			this->KeyCode->ReadOnly = true;
			// 
			// codesTab
			// 
			this->codesTab->Controls->Add(this->textBoxPName);
			this->codesTab->Controls->Add(this->textBoxDName);
			this->codesTab->Controls->Add(this->textBoxPseudo);
			this->codesTab->Controls->Add(this->textBoxDescript);
			this->codesTab->Location = System::Drawing::Point(4, 35);
			this->codesTab->Name = L"codesTab";
			this->codesTab->Padding = System::Windows::Forms::Padding(3);
			this->codesTab->Size = System::Drawing::Size(973, 749);
			this->codesTab->TabIndex = 2;
			this->codesTab->Text = L"Коды";
			this->codesTab->UseVisualStyleBackColor = true;
			// 
			// textBoxPName
			// 
			this->textBoxPName->BackColor = System::Drawing::SystemColors::Window;
			this->textBoxPName->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBoxPName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxPName->Location = System::Drawing::Point(9, 301);
			this->textBoxPName->Name = L"textBoxPName";
			this->textBoxPName->ReadOnly = true;
			this->textBoxPName->Size = System::Drawing::Size(87, 17);
			this->textBoxPName->TabIndex = 7;
			this->textBoxPName->Text = L"Псевдо-код";
			// 
			// textBoxDName
			// 
			this->textBoxDName->BackColor = System::Drawing::SystemColors::Window;
			this->textBoxDName->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBoxDName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxDName->Location = System::Drawing::Point(9, 6);
			this->textBoxDName->Name = L"textBoxDName";
			this->textBoxDName->ReadOnly = true;
			this->textBoxDName->Size = System::Drawing::Size(114, 17);
			this->textBoxDName->TabIndex = 6;
			this->textBoxDName->Text = L"Дескрипторный код";
			// 
			// textBoxPseudo
			// 
			this->textBoxPseudo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBoxPseudo->BackColor = System::Drawing::SystemColors::Control;
			this->textBoxPseudo->Font = (gcnew System::Drawing::Font(L"Courier New", 11));
			this->textBoxPseudo->Location = System::Drawing::Point(9, 324);
			this->textBoxPseudo->Multiline = true;
			this->textBoxPseudo->Name = L"textBoxPseudo";
			this->textBoxPseudo->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBoxPseudo->Size = System::Drawing::Size(956, 266);
			this->textBoxPseudo->TabIndex = 5;
			// 
			// textBoxDescript
			// 
			this->textBoxDescript->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBoxDescript->BackColor = System::Drawing::SystemColors::Control;
			this->textBoxDescript->Font = (gcnew System::Drawing::Font(L"Courier New", 11));
			this->textBoxDescript->Location = System::Drawing::Point(9, 29);
			this->textBoxDescript->Multiline = true;
			this->textBoxDescript->Name = L"textBoxDescript";
			this->textBoxDescript->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBoxDescript->Size = System::Drawing::Size(956, 266);
			this->textBoxDescript->TabIndex = 4;
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
			this->tabControl1->ResumeLayout(false);
			this->tabPageSource->ResumeLayout(false);
			this->tabPageSource->PerformLayout();
			this->tabPageLexems->ResumeLayout(false);
			this->tabPageLexems->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewDelims))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewSigns))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewRelative))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewIDs))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewConst))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewKeys))->EndInit();
			this->codesTab->ResumeLayout(false);
			this->codesTab->PerformLayout();
			this->ResumeLayout(false);

		}

#pragma endregion
private: 
	System::Void clear();
	System::Void stripSource();
	int getFromTable(String^, DataGridView^);
	System::Void buildCodes(int, String^, String^, DataGridView^);
	System::Void addToTable(int, String^);
	System::Void openFileButton_Click(System::Object^, System::EventArgs^ e);
	System::Void processButton_Click(System::Object^, System::EventArgs^ e);
};
}
