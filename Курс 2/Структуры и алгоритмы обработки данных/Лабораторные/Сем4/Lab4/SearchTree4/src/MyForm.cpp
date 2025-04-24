#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

String^ SearchTree4::Searcher::strip(String^ word) {
	/*
	* ����� ������� �� ������ �������� �������
	*/
	String^ delims = L" .,!?:;=+-&#%$[](){}/\\\0\n\r\"\'������������	";
	for each (wchar_t d in delims)
		word = word->Replace(d.ToString(), "");
	return word;
}

std::wstring SearchTree4::Searcher::to_string(String^ string) {
	/*
	* ����� ����������� ��� System::String � std::wstring
	*/
	return msclr::interop::marshal_as<std::wstring>(string);
}

System::Void SearchTree4::Searcher::reset() {
	/*
	* ����� ���������� �������� ���������� � ����������� ���
	*/
	dataGridViewAlphabet->RowCount = 0;
	dataGridViewFreq->RowCount = 0;
	dataGridViewFilter->RowCount = 0;
	textBoxResult->Text = "";
	textBoxSearch->Text = "";
	delete s_tree;
	s_tree = new SearchTree<std::wstring>();
}

System::Void SearchTree4::Searcher::buttonOpen_Click(System::Object^ sender, System::EventArgs^ e) {
	/*
	* �����, ������������ �� ������� ������ �������� �����, ���������
	* ������� ��������� ���� �� �����, �������� �� � ������ ������
	*/
	openFileDialog1->FileName = "";
	openFileDialog1->ShowDialog();
	if (openFileDialog1->FileName == "") return;

	reset();
	StreamReader^ reader = gcnew StreamReader(openFileDialog1->FileName, Encoding::GetEncoding("windows-1251"));
	do {
		String^ line = reader->ReadLine();
		array<wchar_t>^ delims = { ' ', '.', ',' , '!', '?', ':', ';', 
			'=', '+', '-', '&', '#', '%', '$', '[', ']', '(', ')', '{', 
			'}', '/', '\\', '\0', '\n', '\r', '\"', '\'', '�', '�', '�', 
			'�', '�', '�', '�', '	', '�' };

		for each (String ^ word in line->Split(delims)) {
			std::wstring s_word = to_string(strip(word->ToLower()));
			if (s_word != L"")
				s_tree->add(s_word);
		}

	} while (reader->Peek() != -1);
	reader->Close();
	s_tree->to_datagrid(dataGridViewAlphabet);
}

System::Void SearchTree4::Searcher::textBoxSearch_Enter(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	/*
	* �����, ������������ �� ������� Enter � ������ ������ 
	* � ���������� ����� ����� � ������ ������
	*/
	if (e->KeyChar == (char)Keys::Return) {
		auto t1 = std::chrono::steady_clock::now();
		const SearchTree<std::wstring>::Node* node = s_tree->search(to_string(strip(textBoxSearch->Text->ToLower())));
		auto t2 = std::chrono::steady_clock::now();
		std::chrono::duration<double, std::milli> dur = t2 - t1;
		textBoxResult->Text = "�������: ";
		if (node != nullptr)
			textBoxResult->Text += node->count;
		else
			textBoxResult->Text += "0";
		textBoxResult->Text += " �� " + dur.count() + "ms";
	}
}

System::Void SearchTree4::Searcher::textBoxLen_Enter(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	/*
	* �����, ������������ �� ������� Enter � ������ ������� �
	* ���������� ���������� ������� �� ������� ����� �����
	*/
	if (e->KeyChar == (char)Keys::Return) {
		dataGridViewFilter->RowCount = 0;
		try {
			int len = Int32::Parse(textBoxLen->Text);
			s_tree->to_datagrid(dataGridViewFilter, len);
		}
		catch (FormatException^ fe) {
			textBoxLen->Text = "";
			int count = dataGridViewFilter->RowCount++;
			dataGridViewFilter->Rows[count]->Cells[0]->Value = fe->Message;
		}
	}
}

[STAThread]
int main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    SearchTree4::Searcher form;
    Application::Run(% form);
}