#include "GUI.h"

using namespace System;
using namespace System::Windows::Forms;

/**
* Метод, обновляющий поля со статистикой
*/
System::Void HashTable::GUI::updateStats() {
	textBoxCollCount->Text = hashTable->getColCount().ToString();
	textBoxMostClass->Text = hashTable->getLongestClass().ToString();
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
	for (int i = 0; i < data->Length; i++)
		hashTable->add(data[i], MyHashTable::hashA);

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
		int cls = hashTable->search(float::Parse(textBoxSearch->Text), MyHashTable::hashA);
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
	textBoxCollCount->Enabled = true;
	textBoxMostClass->Enabled = true;
	textBoxFillPercent->Enabled = true;
	numericUpDownCount->Enabled = true;
	numericUpDownA->Enabled = true;
	numericUpDownC->Enabled = true;
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

[STAThread]
int main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    HashTable::GUI form;
    Application::Run(% form);
}