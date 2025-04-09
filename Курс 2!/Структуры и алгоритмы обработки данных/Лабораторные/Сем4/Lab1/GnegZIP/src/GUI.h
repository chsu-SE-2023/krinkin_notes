#pragma once
#include "include/archiver.h"
#include <msclr\marshal_cppstd.h>

namespace GnegZIP {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading::Tasks;

	/// <summary>
	/// Сводка для GUI
	/// </summary>
	public ref class GUI : public System::Windows::Forms::Form
	{
	public:
		GUI(void)
		{
			InitializeComponent();

			archiver = new Archiver();
			Timer^ tmr = gcnew Timer();
			tmr->Interval = 16;   // milliseconds
			tmr->Tick += gcnew EventHandler(this, &GUI::UpdateProgress);
			tmr->Start();
		}


	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~GUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::TextBox^ filenameBox;
	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::Button^ buttonSelect;
	private: System::Windows::Forms::Button^ buttonUnComp;
	private: System::Windows::Forms::Button^ buttonComp;
	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;
		Archiver* archiver;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->filenameBox = (gcnew System::Windows::Forms::TextBox());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->buttonSelect = (gcnew System::Windows::Forms::Button());
			this->buttonUnComp = (gcnew System::Windows::Forms::Button());
			this->buttonComp = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// filenameBox
			// 
			this->filenameBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->filenameBox->Location = System::Drawing::Point(15, 24);
			this->filenameBox->Margin = System::Windows::Forms::Padding(6);
			this->filenameBox->Name = L"filenameBox";
			this->filenameBox->Size = System::Drawing::Size(497, 31);
			this->filenameBox->TabIndex = 0;
			// 
			// progressBar1
			// 
			this->progressBar1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->progressBar1->BackColor = System::Drawing::SystemColors::Control;
			this->progressBar1->Enabled = false;
			this->progressBar1->Location = System::Drawing::Point(15, 123);
			this->progressBar1->Margin = System::Windows::Forms::Padding(6);
			this->progressBar1->MarqueeAnimationSpeed = 30;
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(497, 44);
			this->progressBar1->TabIndex = 1;
			// 
			// buttonSelect
			// 
			this->buttonSelect->Location = System::Drawing::Point(15, 67);
			this->buttonSelect->Margin = System::Windows::Forms::Padding(6);
			this->buttonSelect->Name = L"buttonSelect";
			this->buttonSelect->Size = System::Drawing::Size(181, 44);
			this->buttonSelect->TabIndex = 2;
			this->buttonSelect->Text = L"Выбрать файл";
			this->buttonSelect->UseVisualStyleBackColor = true;
			this->buttonSelect->Click += gcnew System::EventHandler(this, &GUI::buttonSelect_Click);
			// 
			// buttonUnComp
			// 
			this->buttonUnComp->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->buttonUnComp->Enabled = false;
			this->buttonUnComp->Location = System::Drawing::Point(362, 67);
			this->buttonUnComp->Margin = System::Windows::Forms::Padding(6);
			this->buttonUnComp->Name = L"buttonUnComp";
			this->buttonUnComp->Size = System::Drawing::Size(150, 44);
			this->buttonUnComp->TabIndex = 3;
			this->buttonUnComp->Text = L"Разжать";
			this->buttonUnComp->UseVisualStyleBackColor = true;
			this->buttonUnComp->Click += gcnew System::EventHandler(this, &GUI::buttonUnComp_Click);
			// 
			// buttonComp
			// 
			this->buttonComp->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->buttonComp->Enabled = false;
			this->buttonComp->Location = System::Drawing::Point(208, 67);
			this->buttonComp->Margin = System::Windows::Forms::Padding(6);
			this->buttonComp->Name = L"buttonComp";
			this->buttonComp->Size = System::Drawing::Size(142, 44);
			this->buttonComp->TabIndex = 4;
			this->buttonComp->Text = L"Сжать";
			this->buttonComp->UseVisualStyleBackColor = true;
			this->buttonComp->Click += gcnew System::EventHandler(this, &GUI::buttonComp_Click);
			// 
			// GUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(529, 169);
			this->Controls->Add(this->buttonComp);
			this->Controls->Add(this->buttonUnComp);
			this->Controls->Add(this->buttonSelect);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->filenameBox);
			this->Margin = System::Windows::Forms::Padding(6);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(555, 240);
			this->Name = L"GUI";
			this->Text = L"GnegZIP";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: 
	bool running = false;

	/*
	* Функция, преобразующая System::String^ в std::string
	*/
	std::string to_string(System::String^ ms_string) {
		return msclr::interop::marshal_as<std::string>(ms_string);
	}

	/*
	* Метод-обёртка для выполнения сжатия в отдельном потоке
	*/
	System::Void CompressTask() {
		archiver->compress(to_string(filenameBox->Text), to_string(filenameBox->Text + ".gzp"));
		running = false;
	}

	/*
	* Метод-обёртка для выполнения разжатия в отдельном потоке
	*/
	System::Void DecompressTask() {
		archiver->decompress(to_string(filenameBox->Text), to_string(filenameBox->Text->Replace(".gzp", "")));
		running = false;
	}

	/*
	* Метод, обновляющий прогрессбар
	*/
	System::Void UpdateProgress(System::Object^ sender, System::EventArgs^ e) {
		progressBar1->Value = archiver->getProgress();
		if (progressBar1->Value == 0 && running) progressBar1->Style = ProgressBarStyle::Marquee;
		else progressBar1->Style = ProgressBarStyle::Blocks;
	}

	System::Void buttonSelect_Click(System::Object^ sender, System::EventArgs^ e) {
		openFileDialog1->FileName = "";
		openFileDialog1->ShowDialog();
		filenameBox->Text = openFileDialog1->FileName;
		String^ ext = filenameBox->Text->Split('.')[filenameBox->Text->Split('.')->Length - 1];
		// Если .gzp - можно разжать, если нет - нельзя
		if (ext == "gzp") {
			buttonComp->Enabled = false;
			buttonUnComp->Enabled = true;
		}
		else {
			buttonComp->Enabled = true;
			buttonUnComp->Enabled = false;
		}
	}
	
	System::Void buttonComp_Click(System::Object^ sender, System::EventArgs^ e) {
		if (filenameBox->Text != "" && !running) {
			running = true;
			Task^ task = Task::Run(gcnew Action(this, &GUI::CompressTask));
		}
	}

	System::Void buttonUnComp_Click(System::Object^ sender, System::EventArgs^ e) {
		if (filenameBox->Text != "" && !running) {
			running = true;
			Task^ task = Task::Run(gcnew Action(this, &GUI::DecompressTask));
		}
	}
};
}
