#include "GUI.h"
#include <string>
#include <msclr\marshal_cppstd.h>

using namespace System;
using namespace System::Windows::Forms;
using namespace msclr::interop;

/*
* �����, ������������ ��������� ��������� � �������� ���������
*/
System::Void Analize::GUI::clear() {
	this->outBox->Text = "";
	this->textBoxPseudo->Text = "";
	this->textBoxDescript->Text = "";
	array<DataGridView^>^ grids = {
		this->dataGridViewConst,
		this->dataGridViewKeys,
		this->dataGridViewIDs,
		this->dataGridViewDelims,
		this->dataGridViewRelative,
		this->dataGridViewSigns
	};
	for each (DataGridView ^ table in grids) {
		table->RowCount = 1;
	}
} 

/*
* ����� ��������� �������, �������� � ����������� ��
* ������ ���������, ��������� ����������
*/
System::Void Analize::GUI::stripSource() {
	analyser->clearState();
	for (int i = 0; i < sourceBox->Text->Length; i++) {
		char out = analyser->space_filter(sourceBox->Text[i]);
		if (out != -1) outBox->Text += gcnew System::String(&out);
	}
}

/*
* ����� ������������ ����� ������� � ��������� ������� ������.
* ��� ����������� ������� � ������� ����� 0.
*/
int Analize::GUI::getFromTable(String^ value, DataGridView^ gridView) {
	for (int i = 0; i < gridView->RowCount; i++) {
		if (gridView->Rows[i]->Cells[1]->Value != nullptr)
			if (gridView->Rows[i]->Cells[1]->Value->ToString() == value)
				return Int32::Parse(gridView->Rows[i]->Cells[0]->Value->ToString());
	}
	return 0;
}

/*
* �����, ����������� ������� � ������� ������ � �� � ������
* ����������� ������� � ������������� � ������-���
*/
System::Void Analize::GUI::buildCodes(int state, String^ lexem, String^ code, DataGridView^ gridView) {
	if (!getFromTable(lexem, gridView)) {
		int k_count = gridView->RowCount++;
		gridView->Rows[k_count - 1]->Cells[0]->Value = k_count.ToString();
		gridView->Rows[k_count - 1]->Cells[1]->Value = lexem;
		gridView->Rows[k_count - 1]->Cells[2]->Value = code;
	}
	textBoxDescript->Text += "(" + state * 10 + "," + getFromTable(lexem, gridView) + ")";
	textBoxPseudo->Text += code;
}

/*
* ������� ����������� ������� �� ��������
*/
System::Void Analize::GUI::addToTable(int state, String^ lexem) {
	lexem = lexem->Replace("\n", "\\n")->Replace("\r", "\\r");
	switch (state) {
	case 1: { // �������� �����
		buildCodes(state, lexem, lexem, dataGridViewKeys); 
		break;
	}
	case 2: { // ���������
		buildCodes(state, lexem, "const", dataGridViewConst); 
		break;
	}
	case 3: { // �������� ���������
		buildCodes(state, lexem, lexem, dataGridViewRelative); 
		break;
	}
	case 4: { // ���� ��������
		buildCodes(state, lexem, lexem, dataGridViewSigns);
		break;
	}
	case 5: { // �����������
		buildCodes(state, lexem, lexem, dataGridViewDelims); 
		break;
	}
	case -1: { // �������������
		buildCodes(state, lexem, "id", dataGridViewIDs);
		break;
	}
	}
}
/*
* ��������� ������� �� ������ "������ ����"
*/
System::Void Analize::GUI::openFileButton_Click(System::Object^ sender, System::EventArgs^ e) {
	this->openFileDialog1->FileName = "";
	this->openFileDialog1->ShowDialog();
	this->fileNameBox->Text = openFileDialog1->FileName;
	this->sourceBox->Text = "";

	StreamReader^ reader = gcnew StreamReader(openFileDialog1->FileName, Encoding::GetEncoding("windows-1251"));
	do {
		this->sourceBox->Text += reader->ReadLine() + " \r\n";
	} while (reader->Peek() != -1);
	this->sourceBox->BackColor = System::Drawing::SystemColors::Window;
}

/*
* ��������� ������� �� ������ "����������"
*/ 
System::Void Analize::GUI::processButton_Click(System::Object^ sender, System::EventArgs^ e) {
	clear(); // ����� ���������

	// �������� �������� � ���������
	this->outBox->BackColor = System::Drawing::SystemColors::Window;
	stripSource();

	// ����������� ������
	analyser->clearState();
	char prev = this->outBox->Text[0];
	for (int i = 1; i < this->outBox->Text->Length; i++) {
		std::string lexem = analyser->lexem_filter(prev, this->outBox->Text[i]);
		if (!lexem.empty()) {
			this->addToTable(analyser->getState(), gcnew String(lexem.c_str()));
			analyser->clearState();
		}
		prev = this->outBox->Text[i];
	}
}

[STAThread]
int main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    Analize::GUI form;
    Application::Run(% form);
}