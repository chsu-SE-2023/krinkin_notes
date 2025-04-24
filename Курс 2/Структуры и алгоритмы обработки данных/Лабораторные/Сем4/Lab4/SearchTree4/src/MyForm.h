#pragma once
#include "search_tree.h"
#include <msclr/marshal_cppstd.h>
#include <string>
#include <chrono>

namespace SearchTree4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Text;

	/// <summary>
	/// Summary for Searcher
	/// </summary>
	public ref class Searcher : public System::Windows::Forms::Form
	{
	public:
		Searcher(void)
		{
			InitializeComponent();
			s_tree = new SearchTree<std::wstring>();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Searcher()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBoxSearch;
	private: System::Windows::Forms::DataGridView^ dataGridViewAlphabet;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Word;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Count;
	private: System::Windows::Forms::Button^ buttonOpen;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::DataGridView^ dataGridViewFreq;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::DataGridView^ dataGridViewFilter;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::TextBox^ textBoxLen;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn3;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::TextBox^ textBoxResult;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		SearchTree<std::wstring>* s_tree;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBoxSearch = (gcnew System::Windows::Forms::TextBox());
			this->dataGridViewAlphabet = (gcnew System::Windows::Forms::DataGridView());
			this->Word = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Count = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->buttonOpen = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->dataGridViewFreq = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->dataGridViewFilter = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxLen = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->textBoxResult = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewAlphabet))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewFreq))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewFilter))->BeginInit();
			this->SuspendLayout();
			// 
			// textBoxSearch
			// 
			this->textBoxSearch->Location = System::Drawing::Point(278, 22);
			this->textBoxSearch->Margin = System::Windows::Forms::Padding(6);
			this->textBoxSearch->Name = L"textBoxSearch";
			this->textBoxSearch->Size = System::Drawing::Size(975, 31);
			this->textBoxSearch->TabIndex = 0;
			this->textBoxSearch->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Searcher::textBoxSearch_Enter);
			// 
			// dataGridViewAlphabet
			// 
			this->dataGridViewAlphabet->AllowUserToAddRows = false;
			this->dataGridViewAlphabet->AllowUserToDeleteRows = false;
			this->dataGridViewAlphabet->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->dataGridViewAlphabet->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridViewAlphabet->BackgroundColor = System::Drawing::SystemColors::Window;
			this->dataGridViewAlphabet->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewAlphabet->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->Word,
					this->Count
			});
			this->dataGridViewAlphabet->Location = System::Drawing::Point(26, 112);
			this->dataGridViewAlphabet->Margin = System::Windows::Forms::Padding(6);
			this->dataGridViewAlphabet->Name = L"dataGridViewAlphabet";
			this->dataGridViewAlphabet->ReadOnly = true;
			this->dataGridViewAlphabet->RowHeadersVisible = false;
			this->dataGridViewAlphabet->RowHeadersWidth = 82;
			this->dataGridViewAlphabet->Size = System::Drawing::Size(538, 806);
			this->dataGridViewAlphabet->TabIndex = 2;
			// 
			// Word
			// 
			this->Word->HeaderText = L"Слово";
			this->Word->MinimumWidth = 10;
			this->Word->Name = L"Word";
			this->Word->ReadOnly = true;
			// 
			// Count
			// 
			this->Count->HeaderText = L"Количество";
			this->Count->MinimumWidth = 10;
			this->Count->Name = L"Count";
			this->Count->ReadOnly = true;
			// 
			// buttonOpen
			// 
			this->buttonOpen->Location = System::Drawing::Point(26, 15);
			this->buttonOpen->Margin = System::Windows::Forms::Padding(6);
			this->buttonOpen->Name = L"buttonOpen";
			this->buttonOpen->Size = System::Drawing::Size(150, 44);
			this->buttonOpen->TabIndex = 3;
			this->buttonOpen->Text = L"Открыть";
			this->buttonOpen->UseVisualStyleBackColor = true;
			this->buttonOpen->Click += gcnew System::EventHandler(this, &Searcher::buttonOpen_Click);
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::SystemColors::Window;
			this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox3->Location = System::Drawing::Point(190, 25);
			this->textBox3->Margin = System::Windows::Forms::Padding(6);
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->Size = System::Drawing::Size(76, 24);
			this->textBox3->TabIndex = 4;
			this->textBox3->Text = L"Поиск";
			// 
			// dataGridViewFreq
			// 
			this->dataGridViewFreq->AllowUserToAddRows = false;
			this->dataGridViewFreq->AllowUserToDeleteRows = false;
			this->dataGridViewFreq->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->dataGridViewFreq->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridViewFreq->BackgroundColor = System::Drawing::SystemColors::Window;
			this->dataGridViewFreq->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewFreq->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->dataGridViewTextBoxColumn2,
					this->dataGridViewTextBoxColumn1
			});
			this->dataGridViewFreq->Location = System::Drawing::Point(578, 112);
			this->dataGridViewFreq->Margin = System::Windows::Forms::Padding(6);
			this->dataGridViewFreq->Name = L"dataGridViewFreq";
			this->dataGridViewFreq->ReadOnly = true;
			this->dataGridViewFreq->RowHeadersVisible = false;
			this->dataGridViewFreq->RowHeadersWidth = 82;
			this->dataGridViewFreq->Size = System::Drawing::Size(538, 806);
			this->dataGridViewFreq->TabIndex = 5;
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->HeaderText = L"Количество";
			this->dataGridViewTextBoxColumn2->MinimumWidth = 10;
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			this->dataGridViewTextBoxColumn2->ReadOnly = true;
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->HeaderText = L"Слово";
			this->dataGridViewTextBoxColumn1->MinimumWidth = 10;
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->ReadOnly = true;
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::SystemColors::Window;
			this->textBox4->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox4->Location = System::Drawing::Point(26, 71);
			this->textBox4->Margin = System::Windows::Forms::Padding(6);
			this->textBox4->Name = L"textBox4";
			this->textBox4->ReadOnly = true;
			this->textBox4->Size = System::Drawing::Size(200, 24);
			this->textBox4->TabIndex = 6;
			this->textBox4->Text = L"По алфавиту";
			// 
			// textBox5
			// 
			this->textBox5->BackColor = System::Drawing::SystemColors::Window;
			this->textBox5->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox5->Location = System::Drawing::Point(578, 75);
			this->textBox5->Margin = System::Windows::Forms::Padding(6);
			this->textBox5->Name = L"textBox5";
			this->textBox5->ReadOnly = true;
			this->textBox5->Size = System::Drawing::Size(200, 24);
			this->textBox5->TabIndex = 7;
			this->textBox5->Text = L"По частоте";
			// 
			// dataGridViewFilter
			// 
			this->dataGridViewFilter->AllowUserToAddRows = false;
			this->dataGridViewFilter->AllowUserToDeleteRows = false;
			this->dataGridViewFilter->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->dataGridViewFilter->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridViewFilter->BackgroundColor = System::Drawing::SystemColors::Window;
			this->dataGridViewFilter->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewFilter->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->dataGridViewTextBoxColumn4,
					this->dataGridViewTextBoxColumn3
			});
			this->dataGridViewFilter->Location = System::Drawing::Point(1128, 112);
			this->dataGridViewFilter->Margin = System::Windows::Forms::Padding(6);
			this->dataGridViewFilter->Name = L"dataGridViewFilter";
			this->dataGridViewFilter->ReadOnly = true;
			this->dataGridViewFilter->RowHeadersVisible = false;
			this->dataGridViewFilter->RowHeadersWidth = 82;
			this->dataGridViewFilter->Size = System::Drawing::Size(538, 806);
			this->dataGridViewFilter->TabIndex = 8;
			// 
			// dataGridViewTextBoxColumn4
			// 
			this->dataGridViewTextBoxColumn4->HeaderText = L"Слово";
			this->dataGridViewTextBoxColumn4->MinimumWidth = 10;
			this->dataGridViewTextBoxColumn4->Name = L"dataGridViewTextBoxColumn4";
			this->dataGridViewTextBoxColumn4->ReadOnly = true;
			// 
			// dataGridViewTextBoxColumn3
			// 
			this->dataGridViewTextBoxColumn3->HeaderText = L"Количество";
			this->dataGridViewTextBoxColumn3->MinimumWidth = 10;
			this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
			this->dataGridViewTextBoxColumn3->ReadOnly = true;
			// 
			// textBox6
			// 
			this->textBox6->BackColor = System::Drawing::SystemColors::Window;
			this->textBox6->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox6->Location = System::Drawing::Point(1128, 75);
			this->textBox6->Margin = System::Windows::Forms::Padding(6);
			this->textBox6->Name = L"textBox6";
			this->textBox6->ReadOnly = true;
			this->textBox6->Size = System::Drawing::Size(200, 24);
			this->textBox6->TabIndex = 9;
			this->textBox6->Text = L"Фильтр (по длине)";
			// 
			// textBoxLen
			// 
			this->textBoxLen->Location = System::Drawing::Point(1536, 65);
			this->textBoxLen->Margin = System::Windows::Forms::Padding(6);
			this->textBoxLen->Name = L"textBoxLen";
			this->textBoxLen->Size = System::Drawing::Size(126, 31);
			this->textBoxLen->TabIndex = 10;
			this->textBoxLen->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Searcher::textBoxLen_Enter);
			// 
			// textBox8
			// 
			this->textBox8->BackColor = System::Drawing::SystemColors::Window;
			this->textBox8->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox8->Location = System::Drawing::Point(1436, 71);
			this->textBox8->Margin = System::Windows::Forms::Padding(6);
			this->textBox8->Name = L"textBox8";
			this->textBox8->ReadOnly = true;
			this->textBox8->Size = System::Drawing::Size(88, 24);
			this->textBox8->TabIndex = 11;
			this->textBox8->Text = L"Длина";
			this->textBox8->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// textBoxResult
			// 
			this->textBoxResult->BackColor = System::Drawing::SystemColors::Window;
			this->textBoxResult->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBoxResult->Location = System::Drawing::Point(1265, 25);
			this->textBoxResult->Margin = System::Windows::Forms::Padding(6);
			this->textBoxResult->Name = L"textBoxResult";
			this->textBoxResult->ReadOnly = true;
			this->textBoxResult->Size = System::Drawing::Size(401, 24);
			this->textBoxResult->TabIndex = 13;
			// 
			// Searcher
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(1694, 940);
			this->Controls->Add(this->textBoxResult);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->textBoxLen);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->dataGridViewFilter);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->dataGridViewFreq);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->buttonOpen);
			this->Controls->Add(this->dataGridViewAlphabet);
			this->Controls->Add(this->textBoxSearch);
			this->Margin = System::Windows::Forms::Padding(4);
			this->MinimumSize = System::Drawing::Size(1700, 223);
			this->Name = L"Searcher";
			this->Text = L"Searcher";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewAlphabet))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewFreq))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewFilter))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

public: 
	String^ strip(String^);
	std::wstring to_string(String^);
	System::Void reset();

private:
	System::Void buttonOpen_Click(System::Object^, System::EventArgs^);
	System::Void textBoxSearch_Enter(System::Object^, System::Windows::Forms::KeyPressEventArgs^);
	System::Void textBoxLen_Enter(System::Object^, System::Windows::Forms::KeyPressEventArgs^);
};
}