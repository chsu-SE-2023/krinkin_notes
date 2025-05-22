#include "GUI.h"
#include <chrono>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::IO;
using namespace System::Globalization;

std::string HashTable::GUI::getMode() {
	if (comboBoxMode->Text == "����� �����")
		return MODE_INT;
	if (comboBoxMode->Text == "�����")
		return MODE_SUM;
}

/**
* �����, ����������� ���� �� �����������
*/
System::Void HashTable::GUI::updateStats() {
	textBoxCollCount->Text = hashTable->getColCount().ToString();
	textBoxMostClass->Text = hashTable->getLongestClass().ToString();
	textBoxMostLenght->Text = hashTable->getClassLenght(hashTable->getLongestClass()).ToString();
	textBoxFillPercent->Text = hashTable->getFillPercent().ToString();
}

/**
* �����, ��������������� ���-������� � ������ �����������
*/
System::Void HashTable::GUI::rebuildTable() {
	if (hashTable) delete hashTable;
	hashTable = new MyHashTable(System::Decimal::ToInt32(numericUpDownCount->Value));
	hashTable->setA(System::Decimal::ToInt32(numericUpDownA->Value));
	hashTable->setC(System::Decimal::ToInt32(numericUpDownC->Value));
	for (int i = 0; i < data->Length; i++) {
		if (comboBoxFunc->Text == "h(x)=x%B")
			hashTable->add(MyHashTable::round(data[i], F_PRESITION), MyHashTable::hashA, getMode());
		if (comboBoxFunc->Text == "h(x)=(ax+c)%B")
			hashTable->add(MyHashTable::round(data[i], F_PRESITION), MyHashTable::hashB, getMode());
	}

	DataTable^ dt = ((DataTable^)dataGridViewHash->DataSource)->Copy();
	delete dataGridViewHash->DataSource;
	dt->Rows->Clear();
	hashTable->toTable(dt);
	dataGridViewHash->DataSource = dt;
	updateStats();
}

/**
* �����, ���������� ��� �������� �����. �������������� ���������������� �����
*/
System::Void HashTable::GUI::GUI_Load(System::Object^ sender, System::EventArgs^ e) {
	array<float>::Resize(data, 50);
	for (int i = 0; i < 50; i++)
		data[i] = rand() % 10 + ((float)rand()) / ((float)RAND_MAX);
	DataTable^ dt = gcnew DataTable();
	dt->Columns->Add(gcnew DataColumn("�����"));
	dt->Columns->Add(gcnew DataColumn("�����"));
	dt->Columns->Add(gcnew DataColumn("��������"));
	dataGridViewHash->DataSource = dt;
	rebuildTable();
}

/**
* �����, ���������� ��� ��������� ������ ������. ������������ ����� ������ � ���-�������.
*/
System::Void HashTable::GUI::textBoxSearch_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	try {
		int cls = -1;
		auto t1 = std::chrono::steady_clock::now();
		if (comboBoxFunc->Text == "h(x)=x%B")
			cls = hashTable->search(float::Parse(textBoxSearch->Text->Replace(",", "."), CultureInfo::InvariantCulture), MyHashTable::hashA, getMode());
		if (comboBoxFunc->Text == "h(x)=(ax+c)%B")
			cls = hashTable->search(float::Parse(textBoxSearch->Text->Replace(",", "."), CultureInfo::InvariantCulture), MyHashTable::hashB, getMode());
		auto t2 = std::chrono::steady_clock::now();
		
		std::chrono::duration<double, std::milli> dur = t2 - t1;
		if (cls != -1)
			textBoxSResult->Text = "�������� " + textBoxSearch->Text + " ������� � ������ " + cls + " �� " + dur.count() + "ms";
		else
			textBoxSResult->Text = "�������� " + textBoxSearch->Text + " �� ������� �� " + dur.count() + "ms";
	}
	catch (System::FormatException^) {
		textBoxSResult->Text = "";
	}
}

/**
* �����, ���������� ��� ������� ������ "�������". ��������� ��������������� ����� � ������ ������
*/
System::Void HashTable::GUI::buttonOpen_Click(System::Object^ sender, System::EventArgs^ e) {
	openFileDialog1->FileName = "";
	openFileDialog1->ShowDialog();
	if (openFileDialog1->FileName == "") return;
	textBoxFileName->Text = openFileDialog1->FileName;

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
* �����, ���������� ��� ��������� ���������� �������. �������� ����������� ���-�������.
*/
System::Void HashTable::GUI::numericUpDownCount_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	rebuildTable();
}

/**
* �����, ���������� ��� ��������� �������� a. �������� ����������� ���-�������.
*/
System::Void HashTable::GUI::numericUpDownA_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	rebuildTable();
}

/**
* �����, ���������� ��� ��������� �������� c. �������� ����������� ���-�������.
*/
System::Void HashTable::GUI::numericUpDownC_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	rebuildTable();
}

/**
* �����, ���������� ��� ������ ������ ���-�������. �������� ����������� ���-�������.
*/
System::Void HashTable::GUI::comboBoxFunc_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	rebuildTable();
}

/**
* �����, ���������� ��� ������ ������� ������ ������������� �������� x. �������� ����������� ���-�������.
*/
System::Void HashTable::GUI::comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
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