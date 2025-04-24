#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

String^ SearchTree4::Searcher::strip(String^ word) {
	/*
	* ћетод удал€ет из строки ненужные символы
	*/
	String^ delims = L" .,!?:;=+-&#%$[](){}/\\\0\n\r\"\'ЂїДУЕЧЦЦ††††	";
	for each (wchar_t d in delims)
		word = word->Replace(d.ToString(), "");
	return word;
}

std::wstring SearchTree4::Searcher::to_string(String^ string) {
	/*
	* ћетод преобразует тип System::String в std::wstring
	*/
	return msclr::interop::marshal_as<std::wstring>(string);
}

System::Void SearchTree4::Searcher::reset() {
	/*
	* ћетод сбрасывает элементы интерфейса в изначальный вид
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
	* ћетод, вызывающийс€ по нажатию кнопки открыти€ файла, построчно
	* дел€щий текстовый файл на слова, добавл€€ их в дерево поиска
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
			'}', '/', '\\', '\0', '\n', '\r', '\"', '\'', 'Ђ', 'ї', 'Д', 
			'У', 'Е', 'Ч', 'Ц', '	', '†' };

		for each (String ^ word in line->Split(delims)) {
			std::wstring s_word = to_string(strip(word->ToLower()));
			if (s_word != L"")
				s_tree->add(s_word);
		}

	} while (reader->Peek() != -1);
	reader->Close();
	s_tree->to_datagrid(dataGridViewAlphabet);

	std::vector<SearchTree<std::wstring>::Node*> words = std::vector<SearchTree<std::wstring>::Node*>();
	s_tree->to_vector(words);
	std::sort(words.begin(), words.end(), s_tree->sorter);

	for each (SearchTree<std::wstring>::Node * word in words) {
		int count = dataGridViewFreq->RowCount++;
		dataGridViewFreq->Rows[count]->Cells[0]->Value = gcnew System::String(word->data.c_str());
		dataGridViewFreq->Rows[count]->Cells[1]->Value = word->count;

	}
}

System::Void SearchTree4::Searcher::textBoxSearch_Enter(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	/*
	* ћетод, вызывающийс€ по нажатию Enter в строке поиска 
	* и вызывающий поиск слова в дереве поиска
	*/
	if (e->KeyChar == (char)Keys::Return) {
		auto t1 = std::chrono::steady_clock::now();
		const SearchTree<std::wstring>::Node* node = s_tree->search(to_string(strip(textBoxSearch->Text->ToLower())));
		auto t2 = std::chrono::steady_clock::now();
		std::chrono::duration<double, std::milli> dur = t2 - t1;
		textBoxResult->Text = "Ќайдено: ";
		if (node != nullptr)
			textBoxResult->Text += node->count;
		else
			textBoxResult->Text += "0";
		textBoxResult->Text += " за " + dur.count() + "ms";
	}
}

System::Void SearchTree4::Searcher::textBoxLen_Enter(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	/*
	* ћетод, вызывающийс€ по нажатию Enter в строке фильтра и
	* вызывающий построение таблицы по фильтру длины слова
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