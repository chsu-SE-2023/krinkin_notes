#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

/*
* �����, ��������� �� ������ �������� �������
*/
String^ SearchTree4::Searcher::strip(String^ word) {
	String^ delims = L" .,!?:;=+-&#%$[](){}/\\\0\n\r\"\'�����������_����	0123456789";
	for each (wchar_t d in delims)
		word = word->Replace(d.ToString(), "");
	return word;
}

/*
* �����, ������������� ��� System::String � std::wstring
*/
std::wstring SearchTree4::Searcher::to_string(String^ string) {
	return msclr::interop::marshal_as<std::wstring>(string);
}

/*
* �����, ������������ �������� ���������� � ����������� ���
*/
System::Void SearchTree4::Searcher::reset() {
	((DataTable^) dataGridViewAlphabet->DataSource)->Rows->Clear();
	((DataTable^)dataGridViewFreq->DataSource)->Rows->Clear();
	//((DataTable^)dataGridViewFilter->DataSource)->Rows->Clear();

	textBoxResult->Text = "";
	textBoxSearch->Text = "";
	textBoxLen->Text = "";
	delete s_tree;
	s_tree = new SearchTree<std::wstring>();
}

System::Void SearchTree4::Searcher::updateTables() {
	DataTable^ dt_a = ((DataTable^)dataGridViewAlphabet->DataSource)->Clone();
	delete dataGridViewAlphabet->DataSource;
	s_tree->to_datagrid(dt_a);
	dataGridViewAlphabet->DataSource = dt_a;

	std::vector<SearchTree<std::wstring>::Node*> words = std::vector<SearchTree<std::wstring>::Node*>();
	s_tree->to_vector(words);
	std::sort(words.begin(), words.end(), s_tree->sorter);

	DataTable^ dt_f = ((DataTable^)dataGridViewFreq->DataSource)->Clone();
	delete dataGridViewFreq->DataSource;
	for each (SearchTree<std::wstring>::Node * word in words) {
		System::Data::DataRow^ row = dt_f->NewRow();
		row[0] = gcnew System::String(word->data.c_str());
		row[1] = word->count;
		dt_f->Rows->Add(row);
	}
	dataGridViewFreq->DataSource = dt_f;
}

/**
* �����, ���������� �� ������� ������ �������� �����, ���������
* ������� ��������� ���� �� �����, �������� �� � ������ ������
*/
System::Void SearchTree4::Searcher::buttonOpen_Click(System::Object^ sender, System::EventArgs^ e) {
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
	updateTables();
}

/**
* �����, ���������� �� ������� ������ ������.
* �������� ������� � ������� reset()
*/
System::Void SearchTree4::Searcher::buttonReset_Click(System::Object^ sender, System::EventArgs^ e) {
	reset();
}

/**
* �����, ���������� �� ������� Enter � ������ ������
* � ���������� ����� ����� � ������ ������
*/
System::Void SearchTree4::Searcher::textBoxSearch_Enter(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
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

/**
* �����, ���������� �� ������� Enter � ������ ������� �
* ���������� ���������� ������� �� ������� ����� �����
*/
System::Void SearchTree4::Searcher::textBoxLen_Enter(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	
	if (e->KeyChar == (char)Keys::Return) {
		try {
			int len = Int32::Parse(textBoxLen->Text);
			SearchTree<std::wstring>* st = new SearchTree<std::wstring>(*s_tree, len);
			delete s_tree;
			s_tree = st;
			updateTables();
		}
		catch (FormatException^ fe) {
			/*textBoxLen->Text = "";
			int count = dataGridViewFilter->RowCount++;
			dataGridViewFilter->Rows[count]->Cells[0]->Value = fe->Message;*/
		}
	}
}

/**
* �����, ���������� ��� �������� �����. �������������� ������ � ��������
*/
System::Void SearchTree4::Searcher::Searcher_Load(System::Object^ sender, System::EventArgs^ e) {
	DataTable^ dt = gcnew DataTable("Frequency");
	dt->Columns->Add(gcnew DataColumn("�����"));
	dt->Columns->Add(gcnew DataColumn("����������"));
	dataGridViewAlphabet->DataSource = dt;
	dataGridViewFreq->DataSource = dt->Clone();
	//dataGridViewFilter->DataSource = dt->Clone();
	dataGridViewAlphabet->Columns[0]->SortMode = DataGridViewColumnSortMode::NotSortable;
	dataGridViewAlphabet->Columns[1]->SortMode = DataGridViewColumnSortMode::NotSortable;
	dataGridViewFreq->Columns[0]->SortMode = DataGridViewColumnSortMode::NotSortable;
	dataGridViewFreq->Columns[1]->SortMode = DataGridViewColumnSortMode::NotSortable;
	//dataGridViewFilter->Columns[0]->SortMode = DataGridViewColumnSortMode::NotSortable;
	//dataGridViewFilter->Columns[1]->SortMode = DataGridViewColumnSortMode::NotSortable;
}

[STAThread]
int main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    SearchTree4::Searcher form;
    Application::Run(% form);
}