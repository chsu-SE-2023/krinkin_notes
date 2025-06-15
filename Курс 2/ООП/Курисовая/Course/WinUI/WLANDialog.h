#pragma once
#include "GUI.h"

namespace WinUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for WLANDialog
	/// </summary>
	public ref class WLANDialog : public System::Windows::Forms::Form
	{
	public:
		WLANDialog(void)
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
		~WLANDialog()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBoxSSID;
	private: System::Windows::Forms::TextBox^ textBoxPasswd;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Button^ buttonConnect;
	private: System::Windows::Forms::TextBox^ textBox1;
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
			this->textBoxSSID = (gcnew System::Windows::Forms::TextBox());
			this->textBoxPasswd = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->buttonConnect = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// textBoxSSID
			// 
			this->textBoxSSID->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxSSID->Location = System::Drawing::Point(95, 43);
			this->textBoxSSID->Name = L"textBoxSSID";
			this->textBoxSSID->ReadOnly = true;
			this->textBoxSSID->Size = System::Drawing::Size(209, 22);
			this->textBoxSSID->TabIndex = 0;
			// 
			// textBoxPasswd
			// 
			this->textBoxPasswd->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxPasswd->Location = System::Drawing::Point(95, 71);
			this->textBoxPasswd->Name = L"textBoxPasswd";
			this->textBoxPasswd->PasswordChar = '*';
			this->textBoxPasswd->Size = System::Drawing::Size(209, 24);
			this->textBoxPasswd->TabIndex = 1;
			// 
			// textBox3
			// 
			this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox3->Location = System::Drawing::Point(12, 44);
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->Size = System::Drawing::Size(77, 17);
			this->textBox3->TabIndex = 2;
			this->textBox3->Text = L"Имя сети";
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::SystemColors::Control;
			this->textBox4->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox4->Location = System::Drawing::Point(12, 74);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(77, 17);
			this->textBox4->TabIndex = 3;
			this->textBox4->Text = L"Пароль";
			// 
			// buttonConnect
			// 
			this->buttonConnect->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonConnect->Location = System::Drawing::Point(116, 101);
			this->buttonConnect->Name = L"buttonConnect";
			this->buttonConnect->Size = System::Drawing::Size(96, 23);
			this->buttonConnect->TabIndex = 4;
			this->buttonConnect->Text = L"Подключить";
			this->buttonConnect->UseVisualStyleBackColor = true;
			this->buttonConnect->Click += gcnew System::EventHandler(this, &WLANDialog::buttonConnect_Click);
			// 
			// textBox1
			// 
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(12, 12);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(292, 17);
			this->textBox1->TabIndex = 5;
			this->textBox1->Text = L"Для подключения к сети введите пароль";
			// 
			// WLANDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(314, 131);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->buttonConnect);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBoxPasswd);
			this->Controls->Add(this->textBoxSSID);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(330, 170);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(330, 170);
			this->Name = L"WLANDialog";
			this->Text = L"Подключение к беспроводной сети";
			this->Load += gcnew System::EventHandler(this, &WLANDialog::WLANDialog_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private:
	WinUI::GUI^ ownerForm = (WinUI::GUI^)Application::OpenForms["GUI"];

	System::Void WLANDialog_Load(System::Object^ sender, System::EventArgs^ e) {
		textBoxSSID->Text = ownerForm->textBoxConnectText->Text;
	}

	System::Void buttonConnect_Click(System::Object^ sender, System::EventArgs^ e) {

	}
};
}
