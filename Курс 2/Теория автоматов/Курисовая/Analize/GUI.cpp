#include "GUI.h"
#include <string>
#include <msclr\marshal_cppstd.h>

using namespace System;
using namespace System::Windows::Forms;
using namespace msclr::interop;

/**
* Метод определяющий лексемы, и добавляющий их в таблицу,
* используя лексический анализатор
*/
System::Void Analize::GUI::addLineCounts() {
	this->linesNum->Text = analyser->get_lines_count(this->outBoxL->Text).ToString();
	this->sourceBox->Text = addLineNum(this->sourceBox->Text);
	this->outBoxL->Text = addLineNum(this->outBoxL->Text);
}

/**
* Метод, добавляющий к тексту программы номер строки
*
* @param входной текст
* @return выходной текст
*/
String^ Analize::GUI::addLineNum(String^ target) {
	line = 0;
	// Количество разрядов длины
	int count = (analyser->get_lines_count(target) + 1).ToString()->Length;
	target = ++line + spaces(count - 1) + "  " + target; // Добавление номера к первой строке
	String^ out = gcnew String("");
	for (int i = 0; i < target->Length; i++) {
		if (target[i] == '\n') {
			line++;
			out += "\n" + line + spaces(count - (line.ToString()->Length)) + "  ";
			continue;
		}
		out += target[i];
	}
	target = out;
	return target;
}

/**
* Метод разделяющий лексемы по таблицам
*
* @param состояние для определения класса
* @param лексема
*/
System::Void Analize::GUI::addToTable(int state, String^ lexem) {
	lexem = lexem->Replace("\n", "\\n")->Replace("\r", "\\r");
	if (state == 3 && System::Char::IsDigit(lexem[0])) {
		error("Лексический анализ", "Неверный идентификатор (начался с цифры): " + lexem);
		return;
	}
	if (state == 3 && (analyser->check_special(lexem) || analyser->is_sign(lexem[0]))) {
		error("Лексический анализ", "Неверный идентификатор (содержит спецсимвол): " + lexem);
		return;
	}
	switch (state) {
	case 1: { // Ключевое слово
		buildCodes(state, lexem, lexem, dataGridViewKeys);
		break;
	}
	case 2: { // Константа
		buildCodes(state, lexem, "const", dataGridViewConst);
		break;
	}
	case 3: { // Идентификатор
		buildCodes(state, lexem, "id", dataGridViewIDs);
		break;
	}
	case 4: { // Оператор отношения
		buildCodes(state, lexem, lexem, dataGridViewRelative);
		break;
	}
	case 5: { // Знак операции
		buildCodes(state, lexem, lexem, dataGridViewSigns);
		break;
	}
	case 6: { // Разделитель
		buildCodes(state, lexem, lexem, dataGridViewDelims);
		break;
	}
	default: {
		error("Лексический анализатор", "Неизвесная лексема: " + lexem);
	}
	}
}

/**
* Метод, добавляющий лексему в таблицу лексем и на её основе
* добавляющий лексему в дескрипторный и псевдо-код
*
* @param состояние автомата
* @param лексема
* @param код лексемы
* @param целевая таблица
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

/**
* Метод, сбрасывающий интерфейс программы в исходное состояние
*/
System::Void Analize::GUI::clear() {
	this->outBox->Text = "";
	this->outBoxL->Text = "";
	this->textBoxPseudo->Text = "";
	this->textBoxDescript->Text = "";
	this->textBoxErrors->Text = "";
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

/**
* Метод определяющий лексемы, и добавляющий их в таблицу,
* используя лексический анализатор
*/
System::Void Analize::GUI::determineLexems() {
	int literalLine = 1;
	currentLine = 1;
	outBox->Text = outBoxL->Text->Replace("\r", "");
	analyser->clear_state();
	char prev = this->outBox->Text[0];
	for (int i = 1; i < this->outBox->Text->Length; i++) {
		// Локализация ошибок
		if (this->outBox->Text[i] == '\n') { currentLine++; continue; }
		if ((analyser->get_state() == 8 || analyser->get_state() == 7) && literalLine == 1) literalLine = currentLine;
		if (analyser->get_state() != 8 && analyser->get_state() != 7) literalLine = 1;

		std::string lexem = analyser->lexem_filter(prev, this->outBox->Text[i]);
		if (!lexem.empty()) {
			if (lexem == "error") error("Лексический анализ", gcnew String(analyser->get_error().c_str()));
			else this->addToTable(analyser->get_state(), gcnew String(lexem.c_str()));
			analyser->clear_state();
		}
		prev = this->outBox->Text[i];
	}

	// Обработка ошибок
	switch (analyser->get_state()) {
	case 7:
	case 8: {
		currentLine = literalLine;
		error("Лексический анализ", "В тексте программы обнаружена незакрытая строка");
		break;
	}
	}
}

/**
* Метод возвращающий номер лексемы в указанной таблице лексем.
* При отстутствии лексемы в таблице вернёт 0 (номер в таблице начинается с 1).
*
* @param искомое значение
* @param искомая таблица
* @return номер элемента из левого столбца
*/
int Analize::GUI::getFromTable(String^ value, DataGridView^ gridView) {
	for (int i = 0; i < gridView->RowCount; i++) {
		if (gridView->Rows[i]->Cells[1]->Value != nullptr)
			if (gridView->Rows[i]->Cells[1]->Value->ToString() == value)
				return Int32::Parse(gridView->Rows[i]->Cells[0]->Value->ToString());
	}
	return 0;
}

/**
* Метод добавляющий в текстбокс сообщение об ошибке
*
* @param искомое значение
*/
System::Void Analize::GUI::error(String^ where, String^ what) {
	textBoxErrors->Text += "[Строка " + currentLine + "] [" + where + "] " + what + "\r\n";
}

/**
* Метод, возвращающий строку из указанного количества пробелов
* 
* @param количество пробелов
* @return строка из указанного количества пробелов
*/
String^ Analize::GUI::spaces(int count) {
	String^ spaces = gcnew String("");
	for (int i = 0; i < count; i++)
		spaces += " ";
	return spaces;
}

/**
* Метод удаляющий пробелы, переносы и комментарии из
* текста программы, используя анализатор
*/
System::Void Analize::GUI::stripSource() {
	currentLine = 1;
	int commentLine = 1;
	analyser->clear_state();
	sourceBox->Text = sourceBox->Text + " \r\n";
	sourceBox->Text = sourceBox->Text->Replace(" \r\n", "\n");
	char prev = sourceBox->Text[0];
	for (int i = 1; i < sourceBox->Text->Length; i++) {
		// Локализация ошибок
		if (this->sourceBox->Text[i] == '\n') { currentLine++; }
		if (analyser->get_state() == 2 && commentLine == 1) commentLine = currentLine;
		if (analyser->get_state() != 2) commentLine = 1;

		char out = analyser->space_filter(prev, sourceBox->Text[i]);
		if (out != -1) outBoxL->Text += gcnew System::String(&out);
		prev = sourceBox->Text[i];
	}
	sourceBox->Text = sourceBox->Text->Replace("\n", " \r\n");
	outBoxL->Text = outBoxL->Text->Replace("\n", " \r\n");

	// Обработка ошибок
	if (analyser->get_state() >= 1 && analyser->get_state() <= 3)
		currentLine = commentLine;
		error("Удаление пробелов", "Обнаружен незакрытый многострочный комментарий");
}

/**
* Обработка нажатия на кнопку "Открыть файл"
*/
System::Void Analize::GUI::openFileButton_Click(System::Object^ sender, System::EventArgs^ e) {
	this->openFileDialog1->FileName = "";
	this->openFileDialog1->ShowDialog();
	if (this->openFileDialog1->FileName != "") {
		this->fileNameBox->Text = openFileDialog1->FileName;
		this->sourceBox->Text = "";

		StreamReader^ reader = gcnew StreamReader(openFileDialog1->FileName, Encoding::GetEncoding("windows-1251"));
		do {
			this->sourceBox->Text += reader->ReadLine() + " \r\n";
		} while (reader->Peek() != -1);
		reader->Close();
	}
}

/**
* Обработка нажатия на кнопку "Обработать"
*/ 
System::Void Analize::GUI::processButton_Click(System::Object^ sender, System::EventArgs^ e) {
	clear(); // Сброс программы

	this->outBox->BackColor = System::Drawing::SystemColors::Window;

	// Удаление пробелов и переносов
	stripSource();

	// Лексический анализ
	determineLexems();

	// Добавление числа строк
	addLineCounts();
}

[STAThread]
int main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    Analize::GUI form;
    Application::Run(% form);
}