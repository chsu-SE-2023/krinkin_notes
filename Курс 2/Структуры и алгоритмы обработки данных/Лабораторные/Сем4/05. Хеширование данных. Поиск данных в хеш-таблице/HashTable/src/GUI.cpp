#include "GUI.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::IO;
using namespace System::Globalization;

/**
* Метод, обновляющий поля со статистикой
*/
System::Void HashTable::GUI::updateStats() {
	textBoxCollCount->Text = hashTable->getColCount().ToString();
	textBoxMostClass->Text = hashTable->getLongestClass().ToString();
	textBoxMostLenght->Text = hashTable->getClassLenght(hashTable->getLongestClass()).ToString();
	textBoxFillPercent->Text = hashTable->getFillPercent().ToString();
}

/**
* Метод, перестраивающий хеш-таблицу с новыми параметрами
*/
System::Void HashTable::GUI::rebuildTable() {
	if (hashTable) delete hashTable;
	hashTable = new MyHashTable(System::Decimal::ToInt32(numericUpDownCount->Value));
	hashTable->setA(System::Decimal::ToInt32(numericUpDownA->Value));
	hashTable->setC(System::Decimal::ToInt32(numericUpDownC->Value));
	for (int i = 0; i < data->Length; i++) {
		if (comboBoxFunc->Text == "h(x)=x%B")
			hashTable->add(data[i], MyHashTable::hashA);
		if (comboBoxFunc->Text == "h(x)=(ax+c)%B")
			hashTable->add(data[i], MyHashTable::hashB);
	}
		

	DataTable^ dt = ((DataTable^)dataGridViewHash->DataSource)->Copy();
	delete dataGridViewHash->DataSource;
	dt->Rows->Clear();
	hashTable->toTable(dt);
	dataGridViewHash->DataSource = dt;
	updateStats();
}

/**
* Метод, вызываемый при загрузке формы. Инициализирует демонстрационный режим
*/
System::Void HashTable::GUI::GUI_Load(System::Object^ sender, System::EventArgs^ e) {
	array<float>::Resize(data, 50);
	for (int i = 0; i < 50; i++)
		data[i] = rand() % 10 + ((float)rand()) / ((float)RAND_MAX);
	DataTable^ dt = gcnew DataTable();
	dt->Columns->Add(gcnew DataColumn("Класс"));
	dt->Columns->Add(gcnew DataColumn("Значения"));
	dataGridViewHash->DataSource = dt;
	rebuildTable();
}

/**
* Метод, вызываемый при изменении строки поиска. Осуществляет вызов поиска в хеш-таблице.
*/
System::Void HashTable::GUI::textBoxSearch_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	try {
		int cls = -1;
		if (comboBoxFunc->Text == "h(x)=x%B")
			cls = hashTable->search(float::Parse(textBoxSearch->Text), MyHashTable::hashA);
		if (comboBoxFunc->Text == "h(x)=(ax+c)%B")
			cls = hashTable->search(float::Parse(textBoxSearch->Text), MyHashTable::hashB);
		
		if (cls != -1)
			textBoxSResult->Text = "Значение " + textBoxSearch->Text + " найдено и имеет класс " + cls;
		else
			textBoxSResult->Text = "Значение " + textBoxSearch->Text + " не найдено";
	}
	catch (System::FormatException^) {
		textBoxSResult->Text = "";
	}
}

/**
* Метод, вызываемый при нажатии кнопки "Открыть". Отключает демонстрацонный режим и читает данные
*/
System::Void HashTable::GUI::buttonOpen_Click(System::Object^ sender, System::EventArgs^ e) {
	openFileDialog1->FileName = "";
	openFileDialog1->ShowDialog();
	if (openFileDialog1->FileName == "") return;

	int line_count = 0;
	StreamReader^ reader = gcnew StreamReader(openFileDialog1->FileName);
	do {
		String^ line = reader->ReadLine();
		float f_value = float::Parse(line, CultureInfo::InvariantCulture);
		line_count++;
		array<float>::Resize(data, line_count);
		data[line_count - 1] = f_value;
	} while (reader->Peek() != -1);

	comboBoxFunc->Text = "h(x)=(ax+c)%B";
	comboBoxFunc->Enabled = true;
	textBoxCollCount->Enabled = true;
	textBoxMostClass->Enabled = true;
	textBoxMostLenght->Enabled = true;
	textBoxFillPercent->Enabled = true;
	numericUpDownCount->Enabled = true;
	numericUpDownA->Enabled = true;
	numericUpDownC->Enabled = true;
	rebuildTable();
}

/**
* Метод, вызываемый при изменении количества классов. Вызывает перестройку хеш-таблицы.
*/
System::Void HashTable::GUI::numericUpDownCount_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	rebuildTable();
}

/**
* Метод, вызываемый при изменении значения a. Вызывает перестройку хеш-таблицы.
*/
System::Void HashTable::GUI::numericUpDownA_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	rebuildTable();
}

/**
* Метод, вызываемый при изменении значения c. Вызывает перестройку хеш-таблицы.
*/
System::Void HashTable::GUI::numericUpDownC_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	rebuildTable();
}
/**
* Метод, вызываемый при выборе другой хеш-функции. Вызывает перестройку хеш-таблицы.
*/
System::Void HashTable::GUI::comboBoxFunc_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	rebuildTable();
}

[STAThread]
int main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    HashTable::GUI form;
    Application::Run(% form);
}