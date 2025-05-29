#pragma once
#include <msclr\marshal_cppstd.h>
#include "../NetDevices/src/misc/address.h"
#include "../NetDevices/src/misc/client.h"
#include "../NetDevices/src/devices/router.h"
#include "../NetDevices/src/containers/data_center.h"
#include "../NetDevices/src/containers/server_room.h"

namespace WinUI {

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
			cont_B = new ServerRoom();
			cont_C = new DataCenter<ServerRoom>();
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
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPageContainerB;
	private: System::Windows::Forms::TabPage^ tabPageContainerC;


	private: System::Windows::Forms::DataGridView^ dataGridViewContainerB;

	private: System::Windows::Forms::Button^ buttonAdd;
	private: System::Windows::Forms::ComboBox^ comboBoxClass;
	private: System::Windows::Forms::Button^ buttonSort;
	private: System::Windows::Forms::ComboBox^ comboBoxCriteria;
	private: System::Windows::Forms::Button^ buttonSearch;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox11;
	private: System::Windows::Forms::TextBox^ textBoxProtocol;
	private: System::Windows::Forms::TextBox^ textBox10;
	private: System::Windows::Forms::TextBox^ textBoxCapacity;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::TextBox^ textBoxPackets;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::TextBox^ textBoxMAC;
	private: System::Windows::Forms::TextBox^ textBox13;
	private: System::Windows::Forms::TextBox^ textBoxSSID;
	private: System::Windows::Forms::CheckBox^ checkBoxWPS;
	private: System::Windows::Forms::TabControl^ tabControl2;
	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::TabPage^ tabPageContainers;
	private: System::Windows::Forms::TextBox^ textBox15;
	private: System::Windows::Forms::TextBox^ textBoxValue;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::TextBox^ textBox12;
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
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPageContainerB = (gcnew System::Windows::Forms::TabPage());
			this->dataGridViewContainerB = (gcnew System::Windows::Forms::DataGridView());
			this->tabPageContainerC = (gcnew System::Windows::Forms::TabPage());
			this->buttonSort = (gcnew System::Windows::Forms::Button());
			this->buttonAdd = (gcnew System::Windows::Forms::Button());
			this->comboBoxClass = (gcnew System::Windows::Forms::ComboBox());
			this->buttonSearch = (gcnew System::Windows::Forms::Button());
			this->comboBoxCriteria = (gcnew System::Windows::Forms::ComboBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxMAC = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxPackets = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxCapacity = (gcnew System::Windows::Forms::TextBox());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxProtocol = (gcnew System::Windows::Forms::TextBox());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxSSID = (gcnew System::Windows::Forms::TextBox());
			this->checkBoxWPS = (gcnew System::Windows::Forms::CheckBox());
			this->tabControl2 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			this->tabPageContainers = (gcnew System::Windows::Forms::TabPage());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox15 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxValue = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->tabControl1->SuspendLayout();
			this->tabPageContainerB->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewContainerB))->BeginInit();
			this->tabControl2->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->tabPageContainers->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tabControl1->Controls->Add(this->tabPageContainerB);
			this->tabControl1->Controls->Add(this->tabPageContainerC);
			this->tabControl1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tabControl1->Location = System::Drawing::Point(602, 2);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(446, 588);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPageContainerB
			// 
			this->tabPageContainerB->Controls->Add(this->dataGridViewContainerB);
			this->tabPageContainerB->Location = System::Drawing::Point(4, 27);
			this->tabPageContainerB->Name = L"tabPageContainerB";
			this->tabPageContainerB->Padding = System::Windows::Forms::Padding(3);
			this->tabPageContainerB->Size = System::Drawing::Size(438, 557);
			this->tabPageContainerB->TabIndex = 0;
			this->tabPageContainerB->Text = L"Контейнер B";
			this->tabPageContainerB->UseVisualStyleBackColor = true;
			// 
			// dataGridViewContainerB
			// 
			this->dataGridViewContainerB->AllowUserToDeleteRows = false;
			this->dataGridViewContainerB->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewContainerB->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridViewContainerB->Location = System::Drawing::Point(3, 3);
			this->dataGridViewContainerB->Name = L"dataGridViewContainerB";
			this->dataGridViewContainerB->ReadOnly = true;
			this->dataGridViewContainerB->Size = System::Drawing::Size(432, 551);
			this->dataGridViewContainerB->TabIndex = 0;
			// 
			// tabPageContainerC
			// 
			this->tabPageContainerC->Location = System::Drawing::Point(4, 27);
			this->tabPageContainerC->Name = L"tabPageContainerC";
			this->tabPageContainerC->Padding = System::Windows::Forms::Padding(3);
			this->tabPageContainerC->Size = System::Drawing::Size(438, 557);
			this->tabPageContainerC->TabIndex = 1;
			this->tabPageContainerC->Text = L"Контейнер C";
			this->tabPageContainerC->UseVisualStyleBackColor = true;
			// 
			// buttonSort
			// 
			this->buttonSort->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonSort->Location = System::Drawing::Point(6, 184);
			this->buttonSort->Name = L"buttonSort";
			this->buttonSort->Size = System::Drawing::Size(109, 23);
			this->buttonSort->TabIndex = 5;
			this->buttonSort->Text = L"Сортировать";
			this->buttonSort->UseVisualStyleBackColor = true;
			// 
			// buttonAdd
			// 
			this->buttonAdd->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonAdd->Location = System::Drawing::Point(8, 321);
			this->buttonAdd->Name = L"buttonAdd";
			this->buttonAdd->Size = System::Drawing::Size(80, 23);
			this->buttonAdd->TabIndex = 3;
			this->buttonAdd->Text = L"Добавить";
			this->buttonAdd->UseVisualStyleBackColor = true;
			// 
			// comboBoxClass
			// 
			this->comboBoxClass->FormattingEnabled = true;
			this->comboBoxClass->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Repeater", L"WLRepeater", L"Switch", L"Gateway",
					L"Router"
			});
			this->comboBoxClass->Location = System::Drawing::Point(6, 88);
			this->comboBoxClass->Name = L"comboBoxClass";
			this->comboBoxClass->Size = System::Drawing::Size(175, 26);
			this->comboBoxClass->TabIndex = 1;
			// 
			// buttonSearch
			// 
			this->buttonSearch->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonSearch->Location = System::Drawing::Point(7, 213);
			this->buttonSearch->Name = L"buttonSearch";
			this->buttonSearch->Size = System::Drawing::Size(109, 23);
			this->buttonSearch->TabIndex = 7;
			this->buttonSearch->Text = L"Поиск";
			this->buttonSearch->UseVisualStyleBackColor = true;
			// 
			// comboBoxCriteria
			// 
			this->comboBoxCriteria->FormattingEnabled = true;
			this->comboBoxCriteria->Location = System::Drawing::Point(6, 121);
			this->comboBoxCriteria->Name = L"comboBoxCriteria";
			this->comboBoxCriteria->Size = System::Drawing::Size(175, 26);
			this->comboBoxCriteria->TabIndex = 8;
			// 
			// textBox3
			// 
			this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox3->Location = System::Drawing::Point(7, 68);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(50, 17);
			this->textBox3->TabIndex = 9;
			this->textBox3->Text = L"Класс";
			// 
			// textBox4
			// 
			this->textBox4->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox4->Location = System::Drawing::Point(8, 124);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(50, 17);
			this->textBox4->TabIndex = 10;
			this->textBox4->Text = L"Поля";
			// 
			// textBoxMAC
			// 
			this->textBoxMAC->Location = System::Drawing::Point(8, 177);
			this->textBoxMAC->Name = L"textBoxMAC";
			this->textBoxMAC->Size = System::Drawing::Size(163, 24);
			this->textBoxMAC->TabIndex = 11;
			// 
			// textBox6
			// 
			this->textBox6->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox6->Location = System::Drawing::Point(177, 180);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(87, 17);
			this->textBox6->TabIndex = 12;
			this->textBox6->Text = L"MAC-Адрес";
			// 
			// textBoxPackets
			// 
			this->textBoxPackets->Location = System::Drawing::Point(6, 147);
			this->textBoxPackets->Name = L"textBoxPackets";
			this->textBoxPackets->Size = System::Drawing::Size(343, 24);
			this->textBoxPackets->TabIndex = 13;
			// 
			// textBox8
			// 
			this->textBox8->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox8->Location = System::Drawing::Point(355, 150);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(87, 17);
			this->textBox8->TabIndex = 14;
			this->textBox8->Text = L"Пакеты";
			// 
			// textBoxCapacity
			// 
			this->textBoxCapacity->Location = System::Drawing::Point(8, 267);
			this->textBoxCapacity->Name = L"textBoxCapacity";
			this->textBoxCapacity->Size = System::Drawing::Size(50, 24);
			this->textBoxCapacity->TabIndex = 15;
			// 
			// textBox10
			// 
			this->textBox10->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox10->Location = System::Drawing::Point(64, 270);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(105, 17);
			this->textBox10->TabIndex = 16;
			this->textBox10->Text = L"Вместимость";
			// 
			// textBox11
			// 
			this->textBox11->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox11->Location = System::Drawing::Point(133, 210);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(105, 17);
			this->textBox11->TabIndex = 18;
			this->textBox11->Text = L"Протокол";
			// 
			// textBoxProtocol
			// 
			this->textBoxProtocol->Location = System::Drawing::Point(7, 207);
			this->textBoxProtocol->Name = L"textBoxProtocol";
			this->textBoxProtocol->Size = System::Drawing::Size(120, 24);
			this->textBoxProtocol->TabIndex = 17;
			// 
			// textBox13
			// 
			this->textBox13->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox13->Location = System::Drawing::Point(133, 240);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(105, 17);
			this->textBox13->TabIndex = 20;
			this->textBox13->Text = L"SSID";
			// 
			// textBoxSSID
			// 
			this->textBoxSSID->Location = System::Drawing::Point(8, 237);
			this->textBoxSSID->Name = L"textBoxSSID";
			this->textBoxSSID->Size = System::Drawing::Size(119, 24);
			this->textBoxSSID->TabIndex = 19;
			// 
			// checkBoxWPS
			// 
			this->checkBoxWPS->AutoSize = true;
			this->checkBoxWPS->Location = System::Drawing::Point(8, 293);
			this->checkBoxWPS->Name = L"checkBoxWPS";
			this->checkBoxWPS->Size = System::Drawing::Size(104, 22);
			this->checkBoxWPS->TabIndex = 21;
			this->checkBoxWPS->Text = L"WPS Mode";
			this->checkBoxWPS->UseVisualStyleBackColor = true;
			// 
			// tabControl2
			// 
			this->tabControl2->Controls->Add(this->tabPage3);
			this->tabControl2->Controls->Add(this->tabPageContainers);
			this->tabControl2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tabControl2->Location = System::Drawing::Point(2, 2);
			this->tabControl2->Name = L"tabControl2";
			this->tabControl2->SelectedIndex = 0;
			this->tabControl2->Size = System::Drawing::Size(598, 588);
			this->tabControl2->TabIndex = 22;
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->button3);
			this->tabPage3->Controls->Add(this->textBox12);
			this->tabPage3->Controls->Add(this->textBox14);
			this->tabPage3->Controls->Add(this->buttonAdd);
			this->tabPage3->Controls->Add(this->checkBoxWPS);
			this->tabPage3->Controls->Add(this->textBoxMAC);
			this->tabPage3->Controls->Add(this->textBox4);
			this->tabPage3->Controls->Add(this->textBox13);
			this->tabPage3->Controls->Add(this->textBox6);
			this->tabPage3->Controls->Add(this->textBox3);
			this->tabPage3->Controls->Add(this->textBoxSSID);
			this->tabPage3->Controls->Add(this->textBoxPackets);
			this->tabPage3->Controls->Add(this->comboBoxClass);
			this->tabPage3->Controls->Add(this->textBox8);
			this->tabPage3->Controls->Add(this->textBox11);
			this->tabPage3->Controls->Add(this->textBoxCapacity);
			this->tabPage3->Controls->Add(this->textBox10);
			this->tabPage3->Controls->Add(this->textBoxProtocol);
			this->tabPage3->Location = System::Drawing::Point(4, 27);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(590, 557);
			this->tabPage3->TabIndex = 0;
			this->tabPage3->Text = L"Объект";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(6, 36);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(109, 23);
			this->button3->TabIndex = 25;
			this->button3->Text = L"Получить";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// textBox12
			// 
			this->textBox12->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox12->Location = System::Drawing::Point(55, 9);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(76, 17);
			this->textBox12->TabIndex = 24;
			this->textBox12->Text = L"Индекс";
			// 
			// textBox14
			// 
			this->textBox14->Location = System::Drawing::Point(6, 6);
			this->textBox14->Name = L"textBox14";
			this->textBox14->Size = System::Drawing::Size(43, 24);
			this->textBox14->TabIndex = 23;
			// 
			// tabPageContainers
			// 
			this->tabPageContainers->Controls->Add(this->textBox9);
			this->tabPageContainers->Controls->Add(this->button2);
			this->tabPageContainers->Controls->Add(this->textBox5);
			this->tabPageContainers->Controls->Add(this->textBox7);
			this->tabPageContainers->Controls->Add(this->textBox2);
			this->tabPageContainers->Controls->Add(this->button1);
			this->tabPageContainers->Controls->Add(this->textBox15);
			this->tabPageContainers->Controls->Add(this->textBoxValue);
			this->tabPageContainers->Controls->Add(this->textBox1);
			this->tabPageContainers->Controls->Add(this->buttonSort);
			this->tabPageContainers->Controls->Add(this->buttonSearch);
			this->tabPageContainers->Controls->Add(this->comboBoxCriteria);
			this->tabPageContainers->Location = System::Drawing::Point(4, 27);
			this->tabPageContainers->Name = L"tabPageContainers";
			this->tabPageContainers->Padding = System::Windows::Forms::Padding(3);
			this->tabPageContainers->Size = System::Drawing::Size(590, 557);
			this->tabPageContainers->TabIndex = 1;
			this->tabPageContainers->Text = L"Контейнер";
			this->tabPageContainers->UseVisualStyleBackColor = true;
			// 
			// textBox9
			// 
			this->textBox9->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox9->Location = System::Drawing::Point(7, 95);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(160, 17);
			this->textBox9->TabIndex = 23;
			this->textBox9->Text = L"Обработка объектов";
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(6, 59);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(109, 23);
			this->button2->TabIndex = 22;
			this->button2->Text = L"Получить";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// textBox5
			// 
			this->textBox5->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox5->Location = System::Drawing::Point(55, 32);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(76, 17);
			this->textBox5->TabIndex = 21;
			this->textBox5->Text = L"Индекс";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(6, 29);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(43, 24);
			this->textBox7->TabIndex = 20;
			// 
			// textBox2
			// 
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(6, 6);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(87, 17);
			this->textBox2->TabIndex = 19;
			this->textBox2->Text = L"Контейнер";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(6, 242);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(175, 23);
			this->button1->TabIndex = 18;
			this->button1->Text = L"Добавить в контейнер 2";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// textBox15
			// 
			this->textBox15->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox15->Location = System::Drawing::Point(280, 157);
			this->textBox15->Name = L"textBox15";
			this->textBox15->Size = System::Drawing::Size(87, 17);
			this->textBox15->TabIndex = 17;
			this->textBox15->Text = L"Значение";
			// 
			// textBoxValue
			// 
			this->textBoxValue->Location = System::Drawing::Point(7, 154);
			this->textBoxValue->Name = L"textBoxValue";
			this->textBoxValue->Size = System::Drawing::Size(267, 24);
			this->textBoxValue->TabIndex = 16;
			// 
			// textBox1
			// 
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(187, 124);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(121, 17);
			this->textBox1->TabIndex = 15;
			this->textBox1->Text = L"Критерий (поле)";
			// 
			// GUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1047, 590);
			this->Controls->Add(this->tabControl2);
			this->Controls->Add(this->tabControl1);
			this->Name = L"GUI";
			this->Text = L"GUI";
			this->Load += gcnew System::EventHandler(this, &GUI::GUI_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPageContainerB->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewContainerB))->EndInit();
			this->tabControl2->ResumeLayout(false);
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			this->tabPageContainers->ResumeLayout(false);
			this->tabPageContainers->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
private: 
	ServerRoom* cont_B;
	DataCenter<ServerRoom>* cont_C;

	std::string to_string(String^ string) {
		msclr::interop::marshal_context context;
		return context.marshal_as<std::string>(string);
	}

	NetDevice* createObject(System::String^ cls) {
		const double* packets = { 0 };
		MAC_Address address = textBoxMAC->Text == "" ? MAC_Address() : MAC_Address();
		std::string protocol = textBoxProtocol->Text == "" ? "" : to_string(textBoxProtocol->Text);
		std::string ssid = textBoxSSID->Text == "" ? "" : to_string(textBoxSSID->Text);
		int capacity = textBoxCapacity->Text == "" ? 32 : 32;
		bool wps = checkBoxWPS->Checked;
		if (cls == "Repeater") {
			return new Repeater(packets, address);
		}
		if (cls == "WLRepeater") {
			return new WLRepeater(packets, address, ssid, ""); // TODO: заполнение поля passwd
		}
		if (cls == "Switch") {
			//return new Switch(packets, clients, address); 
			return new Switch(); // TODO: заполнение поля clients
		}
		if (cls == "Gateway") {
			// return new Gateway(packets, clients, address, protocol); 
			return new Gateway(); // TODO: заполнение поля clients
		}
		if (cls == "Router") {
			// TODO: неопределённый базовый класс
			//return new Router(); 
		}
		return nullptr;
	}

	System::Void buttonAdd_Click(System::Object^ sender, System::EventArgs^ e) {
		cont_B->add(createObject(comboBoxClass->Text));
		
	}

	System::Void GUI_Load(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
