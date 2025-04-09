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
			this->SuspendLayout();
			// 
			// sourceBox
			// 
			this->sourceBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->sourceBox->BackColor = System::Drawing::SystemColors::Control;
			this->sourceBox->Font = (gcnew System::Drawing::Font(L"Courier New", 11));
			this->sourceBox->Location = System::Drawing::Point(12, 7);
			this->sourceBox->Multiline = true;
			this->sourceBox->Name = L"sourceBox";
			this->sourceBox->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->sourceBox->Size = System::Drawing::Size(471, 457);
			this->sourceBox->TabIndex = 0;
			this->sourceBox->WordWrap = false;
			// 
			// outBox
			// 
			this->outBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->outBox->BackColor = System::Drawing::SystemColors::Control;
			this->outBox->Font = (gcnew System::Drawing::Font(L"Courier New", 11));
			this->outBox->Location = System::Drawing::Point(490, 7);
			this->outBox->Multiline = true;
			this->outBox->Name = L"outBox";
			this->outBox->ReadOnly = true;
			this->outBox->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->outBox->Size = System::Drawing::Size(482, 457);
			this->outBox->TabIndex = 1;
			this->outBox->WordWrap = false;
			// 
			// textBox4
			// 
			this->textBox4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->textBox4->BackColor = System::Drawing::SystemColors::Menu;
			this->textBox4->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox4->Location = System::Drawing::Point(823, 473);
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
			this->openFileButton->Location = System::Drawing::Point(13, 499);
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
			this->processButton->Location = System::Drawing::Point(119, 499);
			this->processButton->Name = L"processButton";
			this->processButton->Size = System::Drawing::Size(108, 26);
			this->processButton->TabIndex = 5;
			this->processButton->Text = L"Обработать";
			this->processButton->UseVisualStyleBackColor = true;
			this->processButton->Click += gcnew System::EventHandler(this, &GUI::processButton_Click);
			// 
			// fileNameBox
			// 
			this->fileNameBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->fileNameBox->BackColor = System::Drawing::SystemColors::Window;
			this->fileNameBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->fileNameBox->Location = System::Drawing::Point(13, 470);
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
			this->linesNum->Location = System::Drawing::Point(490, 470);
			this->linesNum->Name = L"linesNum";
			this->linesNum->ReadOnly = true;
			this->linesNum->Size = System::Drawing::Size(33, 24);
			this->linesNum->TabIndex = 7;
			// 
			// textBox7
			// 
			this->textBox7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->textBox7->BackColor = System::Drawing::SystemColors::Menu;
			this->textBox7->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox7->Location = System::Drawing::Point(529, 473);
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
			// GUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(984, 532);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->linesNum);
			this->Controls->Add(this->fileNameBox);
			this->Controls->Add(this->processButton);
			this->Controls->Add(this->openFileButton);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->outBox);
			this->Controls->Add(this->sourceBox);
			this->MinimumSize = System::Drawing::Size(1000, 560);
			this->Name = L"GUI";
			this->Text = L"Анализатор";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
private: 

	// Функция возвращающая некоторое количество пробелов
	String^ spaces(int count) {
		String^ spaces = gcnew String("");
		for (int i = 0; i < count; i++)
			spaces += " ";
		return spaces;
	}

	// Функция-счётчик строк
	int line = 0;
	int getLine() {
		line++;
		return line;
	}

	// Функция добавляющая в ноер строки в исходный текст
	String^ addLineNum(String^ target, int count) {
		line = 0;
		count = (count+1).ToString()->Length;
		target = getLine() + spaces(count-1) + "  " + target;
		String^ out = gcnew String("");
		for (int i = 0; i < target->Length; i++) {
			if (target[i] == '\n') {
				int line = getLine();
				out += "\n" + line + spaces(count-(line.ToString()->Length)) + "  ";
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
		this->outBox->BackColor = System::Drawing::SystemColors::Window;
		this->outBox->Text = gcnew String(analyser->stripSource().c_str());
		this->outBox->Text = addLineNum(this->outBox->Text, analyser->getLineCount(analyser->stripped));
		this->outBox->Text = this->outBox->Text->Replace("\n", "\r\n");
		this->linesNum->Text = analyser->getLineCount(analyser->stripped).ToString();
	}
};
}
