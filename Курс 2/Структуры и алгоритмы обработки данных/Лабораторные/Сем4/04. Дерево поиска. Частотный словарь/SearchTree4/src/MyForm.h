#pragma once
#include "search_tree.h"
#include <msclr/marshal_cppstd.h>
#include <string>
#include <chrono>
#include <algorithm>

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
	private: System::Windows::Forms::Button^ buttonOpen;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::DataGridView^ dataGridViewFreq;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBoxLen;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::TextBox^ textBoxResult;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::Button^ buttonReset;


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
			this->buttonOpen = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->dataGridViewFreq = (gcnew System::Windows::Forms::DataGridView());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxLen = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->textBoxResult = (gcnew System::Windows::Forms::TextBox());
			this->buttonReset = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewAlphabet))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewFreq))->BeginInit();
			this->SuspendLayout();
			// 
			// textBoxSearch
			// 
			this->textBoxSearch->Location = System::Drawing::Point(143, 9);
			this->textBoxSearch->Name = L"textBoxSearch";
			this->textBoxSearch->Size = System::Drawing::Size(443, 20);
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
			this->dataGridViewAlphabet->Location = System::Drawing::Point(8, 81);
			this->dataGridViewAlphabet->Name = L"dataGridViewAlphabet";
			this->dataGridViewAlphabet->ReadOnly = true;
			this->dataGridViewAlphabet->RowHeadersVisible = false;
			this->dataGridViewAlphabet->RowHeadersWidth = 82;
			this->dataGridViewAlphabet->Size = System::Drawing::Size(286, 487);
			this->dataGridViewAlphabet->TabIndex = 2;
			// 
			// buttonOpen
			// 
			this->buttonOpen->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonOpen->Location = System::Drawing::Point(8, 6);
			this->buttonOpen->Name = L"buttonOpen";
			this->buttonOpen->Size = System::Drawing::Size(75, 23);
			this->buttonOpen->TabIndex = 3;
			this->buttonOpen->Text = L"Открыть";
			this->buttonOpen->UseVisualStyleBackColor = true;
			this->buttonOpen->Click += gcnew System::EventHandler(this, &Searcher::buttonOpen_Click);
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::SystemColors::Window;
			this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox3->Location = System::Drawing::Point(89, 9);
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->Size = System::Drawing::Size(49, 17);
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
			this->dataGridViewFreq->Location = System::Drawing::Point(300, 81);
			this->dataGridViewFreq->Name = L"dataGridViewFreq";
			this->dataGridViewFreq->ReadOnly = true;
			this->dataGridViewFreq->RowHeadersVisible = false;
			this->dataGridViewFreq->RowHeadersWidth = 82;
			this->dataGridViewFreq->Size = System::Drawing::Size(286, 487);
			this->dataGridViewFreq->TabIndex = 5;
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::SystemColors::Window;
			this->textBox4->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox4->Location = System::Drawing::Point(8, 58);
			this->textBox4->Name = L"textBox4";
			this->textBox4->ReadOnly = true;
			this->textBox4->Size = System::Drawing::Size(100, 17);
			this->textBox4->TabIndex = 6;
			this->textBox4->Text = L"По алфавиту";
			// 
			// textBox5
			// 
			this->textBox5->BackColor = System::Drawing::SystemColors::Window;
			this->textBox5->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox5->Location = System::Drawing::Point(300, 58);
			this->textBox5->Name = L"textBox5";
			this->textBox5->ReadOnly = true;
			this->textBox5->Size = System::Drawing::Size(100, 17);
			this->textBox5->TabIndex = 7;
			this->textBox5->Text = L"По частоте";
			// 
			// textBoxLen
			// 
			this->textBoxLen->Location = System::Drawing::Point(143, 33);
			this->textBoxLen->Name = L"textBoxLen";
			this->textBoxLen->Size = System::Drawing::Size(65, 20);
			this->textBoxLen->TabIndex = 10;
			this->textBoxLen->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Searcher::textBoxLen_Enter);
			// 
			// textBox8
			// 
			this->textBox8->BackColor = System::Drawing::SystemColors::Window;
			this->textBox8->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox8->Location = System::Drawing::Point(8, 33);
			this->textBox8->Name = L"textBox8";
			this->textBox8->ReadOnly = true;
			this->textBox8->Size = System::Drawing::Size(129, 17);
			this->textBox8->TabIndex = 11;
			this->textBox8->Text = L"Фильтр по длине";
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
			this->textBoxResult->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxResult->Location = System::Drawing::Point(300, 35);
			this->textBoxResult->Name = L"textBoxResult";
			this->textBoxResult->ReadOnly = true;
			this->textBoxResult->Size = System::Drawing::Size(215, 17);
			this->textBoxResult->TabIndex = 13;
			// 
			// buttonReset
			// 
			this->buttonReset->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonReset->Location = System::Drawing::Point(519, 33);
			this->buttonReset->Name = L"buttonReset";
			this->buttonReset->Size = System::Drawing::Size(67, 23);
			this->buttonReset->TabIndex = 14;
			this->buttonReset->Text = L"Сброс";
			this->buttonReset->UseVisualStyleBackColor = true;
			this->buttonReset->Click += gcnew System::EventHandler(this, &Searcher::buttonReset_Click);
			// 
			// Searcher
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(594, 576);
			this->Controls->Add(this->buttonReset);
			this->Controls->Add(this->textBoxResult);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->textBoxLen);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->dataGridViewFreq);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->buttonOpen);
			this->Controls->Add(this->dataGridViewAlphabet);
			this->Controls->Add(this->textBoxSearch);
			this->Margin = System::Windows::Forms::Padding(2);
			this->MaximumSize = System::Drawing::Size(610, 2000);
			this->MinimumSize = System::Drawing::Size(610, 169);
			this->Name = L"Searcher";
			this->Padding = System::Windows::Forms::Padding(5);
			this->Text = L"Searcher";
			this->Load += gcnew System::EventHandler(this, &Searcher::Searcher_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewAlphabet))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewFreq))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

public: 
	String^ strip(String^);
	std::wstring to_string(String^);
	System::Void reset();
	System::Void updateTables();

private:
	System::Void buttonOpen_Click(System::Object^, System::EventArgs^);
	System::Void textBoxSearch_Enter(System::Object^, System::Windows::Forms::KeyPressEventArgs^);
	System::Void textBoxLen_Enter(System::Object^, System::Windows::Forms::KeyPressEventArgs^);
	System::Void Searcher_Load(System::Object^ sender, System::EventArgs^ e);
	System::Void buttonReset_Click(System::Object^ sender, System::EventArgs^ e);
};
}