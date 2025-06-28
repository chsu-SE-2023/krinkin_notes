#include "GUI.h"
#include "WLANDialog.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<String^>^ args)
{
	srand(std::time(0));
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	WinUI::GUI form;
	Application::Run(% form);
}

/**
* Функция, открывающая диалог подключения к беспроводной сети
* 
* @return введённый пароль к сети
*/
std::string ShowWLANDialog()
{
	WinUI::WLANDialog^ form = gcnew WinUI::WLANDialog();
	form->ShowDialog();
	if (form->result == Windows::Forms::DialogResult::OK)
		return WinUI::GUI::to_string(form->passwd);
	else return "";
}

/**
* Метод, преобразующий System::String в std::string
*
* @param System::String строка
* @return std::string строка
*/
std::string WinUI::GUI::to_string(String^ string) {
	msclr::interop::marshal_context context;
	return context.marshal_as<std::string>(string);
}

/**
* Метод, создающий строку в таблице B
*
* @param контейнер, на основе которого будет построена строка
*/
template <typename T>
System::Void WinUI::GUI::addBTableRow(ServerRoom<T>* container) {
	int count = dataGridViewB->RowCount++;
	dataGridViewB->Rows[count - 1]->Cells[0]->Value = gcnew String(typeid(T).name());
	dataGridViewB->Rows[count - 1]->Cells[1]->Value = container->size();
	dataGridViewB->Rows[count - 1]->Cells[2]->Value = container->cli_total();
}

/**
* Метод, перестраивающий таблицу B
*/
System::Void WinUI::GUI::updateBTable() {
	dataGridViewB->RowCount = 1;
	std::vector<void*> vec = contB->get_vector();
	addBTableRow(static_cast<ServerRoom<Repeater>*>(vec[0]));
	addBTableRow(static_cast<ServerRoom<WLRepeater>*>(vec[1]));
	addBTableRow(static_cast<ServerRoom<Switch>*>(vec[2]));
	addBTableRow(static_cast<ServerRoom<Gateway>*>(vec[3]));
	addBTableRow(static_cast<ServerRoom<Router>*>(vec[4]));
}

/**
* Метод, перестраивающий таблицу C
* 
* @param вектор объектов из контейнера
* @param перестраиваемая таблица
*/
template <typename T>
System::Void WinUI::GUI::updateTable(std::vector<T*> vec, DataGridView^ table) {
	table->RowCount = 1;
	for (int i = 0; i < vec.size(); i++) {
		int count = table->RowCount++;
		const void* address = static_cast<const void*>(vec[i]);
		std::stringstream ss;
		ss << address;
		table->Rows[count - 1]->Cells[0]->Value = count - 1;
		table->Rows[count - 1]->Cells[1]->Value = "0x" + gcnew String(ss.str().c_str());
		table->Rows[count - 1]->Cells[2]->Value = "{" + gcnew String(vec[i]->get_info().c_str()) + "}";
	}
	updateBTable();
}

/**
* Метод, перестраивающий все таблицы С
*/
System::Void WinUI::GUI::updateAllTables() {
	updateTable(contRepeater->get_vector(), dataGridViewRepeater);
	updateTable(contWLRepeater->get_vector(), dataGridViewWLRepeater);
	updateTable(contSwitch->get_vector(), dataGridViewSwitch);
	updateTable(contGateway->get_vector(), dataGridViewGateway);
	updateTable(contRouter->get_vector(), dataGridViewRouter);
}

/**
* Метод, сбрасывающй все поля интерфейса создания объекта
*/
System::Void WinUI::GUI::resetFields() {
	textBoxBytes->Enabled = false;
	textBoxMAC->Enabled = false;
	buttonMACGen->Enabled = false;
	numericUpDownCapacity->Enabled = false;
	textBoxProtocol->Enabled = false;
	textBoxSSID->Enabled = false;
	textBoxPasswd->Enabled = false;
	checkBoxWPS->Enabled = false;
}

/**
* Метод, вызывающий окно с ошибкой
* 
* @param сообщение об ошибке
*/
System::Void WinUI::GUI::error(System::String^ message) {
	MessageBox::Show(message, "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
}

/**
* Метод, вызывающий окно с предупреждением
*
* @param сообщение с предупреждением
*/
System::Void WinUI::GUI::warning(System::String^ message) {
	MessageBox::Show(message, "Предупреждение", MessageBoxButtons::OK, MessageBoxIcon::Warning);
}

/**
* Метод, генерирующий случайный MAC-адрес
*/
System::Void WinUI::GUI::buttonMACGen_Click(System::Object^ sender, System::EventArgs^ e) {
	textBoxMAC->Text = gcnew String(MAC_Address().as_string().c_str());
}

/**
* Метод, генерирующий случайный MAC-адрес
*/
System::Void WinUI::GUI::buttonMACGenC_Click(System::Object^ sender, System::EventArgs^ e) {
	textBoxMACC->Text = gcnew String(MAC_Address().as_string().c_str());
}

/**
* Метод, меняющий критерий поиска для нужного типа устройства в интерфейсе подключения клиента
*/
System::Void WinUI::GUI::comboBoxCType_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	if (comboBoxCType->Text == "Проводной")
		textBoxConCriteria->Text = "MAC-Адрес";
	if (comboBoxCType->Text == "Беспроводной")
		textBoxConCriteria->Text = "Имя сети";
}

/**
* Метод, активирующий поля доступные для определённого класса
* в интерфейсе создания объекта
*/
System::Void WinUI::GUI::comboBoxClass_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	if (comboBoxClass->Text == "Repeater") {
		textBoxBytes->Enabled = true;
		textBoxMAC->Enabled = true;
		buttonMACGen->Enabled = true;
	}
	else if (comboBoxClass->Text == "WLRepeater") {
		textBoxBytes->Enabled = true;
		textBoxMAC->Enabled = true;
		buttonMACGen->Enabled = true;
		textBoxSSID->Enabled = true;
		textBoxPasswd->Enabled = true;
	}
	else if (comboBoxClass->Text == "Switch") {
		textBoxBytes->Enabled = true;
		textBoxMAC->Enabled = true;
		buttonMACGen->Enabled = true;
		numericUpDownCapacity->Enabled = true;
	}
	else if (comboBoxClass->Text == "Gateway") {
		textBoxBytes->Enabled = true;
		textBoxMAC->Enabled = true;
		buttonMACGen->Enabled = true;
		numericUpDownCapacity->Enabled = true;
		textBoxProtocol->Enabled = true;
	}
	else if (comboBoxClass->Text == "Router") {
		textBoxBytes->Enabled = true;
		textBoxMAC->Enabled = true;
		buttonMACGen->Enabled = true;
		numericUpDownCapacity->Enabled = true;
		textBoxProtocol->Enabled = true;
		textBoxSSID->Enabled = true;
		textBoxPasswd->Enabled = true;
		checkBoxWPS->Enabled = true;
	}
}

/**
* Метод, вызывающийся при добавлении нового объекта через интерфейс
* по нажатию соответствующей кнопки
*/
System::Void WinUI::GUI::buttonAdd_Click(System::Object^ sender, System::EventArgs^ e) {
	const unsigned char* bytes = {};
	std::vector<Client> clients = {};
	try {
		MAC_Address address = textBoxMAC->Text == "" ? MAC_Address() : MAC_Address(to_string(textBoxMAC->Text));
		std::string protocol = to_string(textBoxProtocol->Text);
		std::string ssid = to_string(textBoxSSID->Text);
		std::string passwd = to_string(textBoxPasswd->Text);
		Switch::set_capacity(Int32::Parse(numericUpDownCapacity->Text));
		bool wps = checkBoxWPS->Checked;

		if (comboBoxClass->Text == "Repeater") {
			contRepeater->add(*(new Repeater(bytes, address)));
			updateTable(contRepeater->get_vector(), dataGridViewRepeater);
		}
		else if (comboBoxClass->Text == "WLRepeater") {
			contWLRepeater->add(*(new WLRepeater(bytes, address, ssid, passwd)));
			updateTable(contWLRepeater->get_vector(), dataGridViewWLRepeater);
		}
		else if (comboBoxClass->Text == "Switch") {
			contSwitch->add(*(new Switch(bytes, clients, address)));
			updateTable(contSwitch->get_vector(), dataGridViewSwitch);
		}
		else if (comboBoxClass->Text == "Gateway") {
			contGateway->add(*(new Gateway(bytes, clients, address, protocol)));
			updateTable(contGateway->get_vector(), dataGridViewGateway);
		}
		else if (comboBoxClass->Text == "Router") {
			contRouter->add(*(new Router(bytes, clients, address, protocol, ssid, passwd)));
			updateTable(contRouter->get_vector(), dataGridViewRouter);
		}
	}
	catch (std::length_error) {
		error("Введён невалидный MAC-Адрес (неполная строка)");
	}
	catch (std::overflow_error) {
		error("Введён невалидный MAC-Адрес (переполнение)");
	}
	catch (std::invalid_argument) {
		error("Введён невалидный MAC-Адрес (неверный символ)");
	}
}

/**
* Метод, заполняющий поля интерфейса создания объекта данными из некоторого объекта по индексу.
* Вызывается по нажатию на соотвествующую кнопку
*/
System::Void WinUI::GUI::buttonGet_Click(System::Object^ sender, System::EventArgs^ e) {
	int index = Decimal::ToInt32(numericUpDownIndex->Value);
	if (comboBoxClass->Text == "Repeater") {
		Repeater* rep = (*contRepeater)[index];
		textBoxBytes->Enabled = true; // TODO: bytes
		textBoxMAC->Text = gcnew String(rep->get_address().as_string().c_str());
	}
	else if (comboBoxClass->Text == "WLRepeater") {
		WLRepeater* wlrep = (*contWLRepeater)[index];
		textBoxBytes->Enabled = true;  // TODO: bytes
		textBoxMAC->Text = gcnew String(wlrep->get_address().as_string().c_str());
		textBoxSSID->Text = gcnew String(wlrep->get_ssid().c_str());
	}
	else if (comboBoxClass->Text == "Switch") {
		Switch* sw = (*contSwitch)[index];
		textBoxBytes->Enabled = true;  // TODO: bytes
		textBoxMAC->Text = gcnew String(sw->get_address().as_string().c_str());
		numericUpDownCapacity->Enabled = true;
	}
	else if (comboBoxClass->Text == "Gateway") {
		Gateway* gw = (*contGateway)[index];
		textBoxBytes->Enabled = true;  // TODO: bytes
		textBoxMAC->Text = gcnew String(gw->get_address().as_string().c_str());
		numericUpDownCapacity->Enabled = true;
		textBoxProtocol->Text = gcnew String(gw->get_protocol().c_str());
	}
	else if (comboBoxClass->Text == "Router") {
		Router* ro = (*contRouter)[index];
		textBoxBytes->Enabled = true;  // TODO: bytes
		textBoxMAC->Text = gcnew String(ro->get_address().as_string().c_str());
		numericUpDownCapacity->Enabled = true;
		textBoxProtocol->Text = gcnew String(ro->get_protocol().c_str());
		textBoxSSID->Text = gcnew String(ro->get_ssid().c_str());
		checkBoxWPS->Checked = ro->is_wps();
	}
	else {
		error("Не указан тип получаемого объекта");
	}
}

/**
* Метод, выполняющий полиморфный поиск объектов по некоорому критерию во всех контейнерах
*/
System::Void WinUI::GUI::buttonSearch_Click(System::Object^ sender, System::EventArgs^ e) {
	std::vector<void*> vec = contB->get_vector();
	std::vector<void*> founded = {};
	int count = 0;

	if (comboBoxCriteria->Text == "address") {
		try {
			for (int i = 0; i < vec.size(); i++) {
				count += static_cast<ServerRoom<Repeater>*>(vec[i])->search(MAC_Address(to_string(textBoxValue->Text))).size();
			}
		}
		catch (std::length_error) {
			error("Введён невалидный MAC-Адрес (неполная строка)");
		}
		catch (std::overflow_error) {
			error("Введён невалидный MAC-Адрес (переполнение)");
		}
		catch (std::invalid_argument) {
			error("Введён невалидный MAC-Адрес (неверный символ)");
		}
	}
	if (comboBoxCriteria->Text == "clients_count") {
		try {
			int first = Int32::Parse(textBoxValue->Text->Split('-')[0]->Trim(' '));
			int second = first;
			if (textBoxValue->Text->Split('-')->Length > 1) second = Int32::Parse(textBoxValue->Text->Split('-')[1]->Trim(' '));
			for (int i = 0; i < vec.size(); i++) {
				count += static_cast<ServerRoom<Repeater>*>(vec[i])->search(first, second).size();
			}
		}
		catch (System::FormatException^) {
			error("Введено значение в неверном формате (принимается: целое число или диапазон)");
		}
		catch (std::invalid_argument) {
			error("Введён неверный диапазон (верхняя граница меньше нижней)");
		}
	}
	if (comboBoxCriteria->Text == "protocol") {
		count += static_cast<ServerRoom<Gateway>*>(vec[3])->search(to_string(textBoxValue->Text), SearchMode::Protocol).size();
		count += static_cast<ServerRoom<Router>*>(vec[4])->search(to_string(textBoxValue->Text), SearchMode::Protocol).size();
	}
	if (comboBoxCriteria->Text == "ssid") {
		count += static_cast<ServerRoom<WLRepeater>*>(vec[1])->search(to_string(textBoxValue->Text), SearchMode::SSID).size();
		count += static_cast<ServerRoom<Router>*>(vec[4])->search(to_string(textBoxValue->Text), SearchMode::SSID).size();
	}
	if (comboBoxCriteria->Text == "wps") {
		try {
			count += static_cast<ServerRoom<WLRepeater>*>(vec[1])->search(bool::Parse(textBoxValue->Text)).size();
			count += static_cast<ServerRoom<Router>*>(vec[4])->search(bool::Parse(textBoxValue->Text)).size();
		}
		catch (System::FormatException^) {
			error("Введено значение в неверном формате (принимается: true, false)");
		}
	}
	textBoxResult->Text = "Найдено " + count + " объектов";
}

/**
* Метод, запускающий полиморфную сортировку объектов по MAC-адресу
*/
System::Void WinUI::GUI::buttonSort_Click(System::Object^ sender, System::EventArgs^ e) {
	std::vector<void*> vec = contB->get_vector();
	for (int i = 0; i < vec.size(); i++) {
		static_cast<ServerRoom<Repeater>*>(vec[i])->sort();
	}
	updateAllTables();
}

/**
* Метод, полиморфно устанавливающий значения по умолчанию для всех объектов в контейнерах
*/
System::Void WinUI::GUI::buttonReset_Click(System::Object^ sender, System::EventArgs^ e) {
	std::vector<void*> vec = contB->get_vector();
	for (int i = 0; i < vec.size(); i++) {
		ServerRoom<Repeater>* cont = static_cast<ServerRoom<Repeater>*>(vec[i]);
		for (int i = 0; i < cont->size(); i++) {
			(*cont)[i]->reset();
		}
	}
	updateAllTables();
}

/**
* Метод, удаляющий все объекты в контейнерах
*/
System::Void WinUI::GUI::buttonDeleteAll_Click(System::Object^ sender, System::EventArgs^ e) {
	std::vector<void*> vec = contB->get_vector();
	for (int i = 0; i < vec.size(); i++) {
		ServerRoom<Repeater>* cont = static_cast<ServerRoom<Repeater>*>(vec[i]);
		cont->seek(cont->size());
	}
	updateAllTables();
}

System::Void WinUI::GUI::connectTo(Client& client, String^ criteria, bool gui, String^ passwd) {
	std::vector<void*> vec = contB->get_vector();
	WLRepeater* net_device = nullptr;
	ClientType cli_type = client.get_type();
	for (int i = 0; i < vec.size(); i++) {
		// Поиск устройства по критерию
		if (cli_type == ClientType::Wired) {
			std::vector<WLRepeater*> result = static_cast<ServerRoom<WLRepeater>*>(vec[i])->search(MAC_Address(to_string(criteria)));
			if (result.size() > 0)
				net_device = static_cast<WLRepeater*>(result[0]);
		}
		if (cli_type == ClientType::Wireless) {
			if (i == 1) {
				std::vector<WLRepeater*> result = static_cast<ServerRoom<WLRepeater>*>(vec[i])->search(to_string(criteria), SearchMode::SSID);
				if (result.size() > 0)
					net_device = static_cast<WLRepeater*>(result[0]);
			}
			if (i == 4) {
				std::vector<Router*> result = static_cast<ServerRoom<Router>*>(vec[i])->search(to_string(criteria), SearchMode::SSID);
				if (result.size() > 0)
					net_device = static_cast<WLRepeater*>(result[0]);
			}
		}
	}

	if (cli_type == ClientType::Wired) {
		if (net_device == nullptr) {
			if (gui)
				warning("Устройство с указанным адресом не найдено!");
			return;
		}
		net_device->connect(client);
	}
	if (cli_type == ClientType::Wireless) {
		if (net_device == nullptr) {
			if (gui)
				warning("Указанная сеть не найдена!");
			return;
		}
		if (net_device->is_wps()) {
			net_device->connect(client);
		}
		else {
			if (passwd == "" && gui)
				passwd = gcnew String(ShowWLANDialog().c_str());
			net_device->connect(client, net_device->get_ssid(), to_string(passwd));
		}
	}
}

/**
* Метод, подключающий клиента к сетевому устройству
* Вызывается нажатием на соотвествующую кнопку
*/
System::Void WinUI::GUI::buttonConnect_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		std::string name = to_string(textBoxCName->Text);
		MAC_Address address = textBoxMACC->Text == "" ? MAC_Address() : MAC_Address(to_string(textBoxMACC->Text));
		unsigned char* bytes = {}; // TODO: Заполнение поля байт
		ClientType type = comboBoxCType->Text == "Беспроводной" ? ClientType::Wireless : ClientType::Wired;
		Client client = Client(name, address, bytes, type);

		try {
			connectTo(client, textBoxConnectText->Text, true, "");
		}
		catch (std::invalid_argument) {
			error("Введён неверный пароль");
		}
		updateAllTables();
	}
	catch (std::length_error) {
		error("Введён невалидный MAC-Адрес (неполная строка)");
	}
	catch (std::overflow_error) {
		error("Введён невалидный MAC-Адрес (переполнение)");
	}
	catch (std::invalid_argument) {
		error("Введён невалидный MAC-Адрес (неверный символ)");
	}
}

/**
* Метод, загружающий объекты в контейнеры из текстового файла
*/
System::Void WinUI::GUI::buttonLoadFile_Click(System::Object^ sender, System::EventArgs^ e) {
	openFileDialog1->FileName = "";
	openFileDialog1->ShowDialog();
	if (openFileDialog1->FileName != "") {
		StreamReader^ reader = gcnew StreamReader(openFileDialog1->FileName, Encoding::GetEncoding("windows-1251"));
		bool error = false;
		do {
			System::String^ line = reader->ReadLine()->Trim(' ');
			if (line != "") {
				cli::array<System::String^>^ data = line->Split(',');
				try {
					String^ type = data[0]->Trim(' ');
					if (type == "Repeater") {
						Repeater* obj = new Repeater();
						obj->set_address(MAC_Address(to_string(data[1]->Trim(' '))));
						contRepeater->add(*obj);
					}
					else if (type == "WLRepeater") {
						WLRepeater* obj = new WLRepeater();
						obj->set_address(MAC_Address(to_string(data[1]->Trim(' '))));
						obj->set_ssid(to_string(data[4]->Trim(' ')));
						obj->set_passwd(to_string(data[5]->Trim(' ')));
						contWLRepeater->add(*obj);
					}
					else if (type == "Switch") {
						Switch* obj = new Switch();
						obj->set_address(MAC_Address(to_string(data[1]->Trim(' '))));
						obj->set_capacity(Int32::Parse(data[2]->Trim(' ')));
						contSwitch->add(*obj);
					}
					else if (type == "Gateway") {
						Gateway* obj = new Gateway();
						obj->set_address(MAC_Address(to_string(data[1]->Trim(' '))));
						obj->set_protocol(to_string(data[3]->Trim(' ')));
						contGateway->add(*obj);
					}
					else if (type == "Router") {
						Router* obj = new Router();
						obj->set_address(MAC_Address(to_string(data[1]->Trim(' '))));
						obj->set_capacity(Int32::Parse(data[2]->Trim(' ')));
						obj->set_protocol(to_string(data[3]->Trim(' ')));
						obj->set_ssid(to_string(data[4]->Trim(' ')));
						obj->set_passwd(to_string(data[5]->Trim(' ')));
						if (bool::Parse(data[6]->Trim(' '))) obj->wps_init();
						contRouter->add(*obj);
					}
				}
				catch (std::exception) {
					error = true;
				}
			}
		} while (reader->Peek() != -1);
		updateAllTables();
		if (error) warning("Не удалось загрузить некоторые из объектов в файле");
		reader->Close();
	}
}

/**
* Метод, сохраняющий данные об хранимых обектах в текстовый файл
*/
System::Void WinUI::GUI::buttonSaveFile_Click(System::Object^ sender, System::EventArgs^ e) {
	saveFileDialog1->FileName = "";
	saveFileDialog1->ShowDialog();

	if (saveFileDialog1->FileName != "") {
		StreamWriter^ writer = gcnew StreamWriter(saveFileDialog1->FileName);
		writer->WriteLine("type,mac,cli_cap,protocol,ssid,passwd,wps"); // Заголовок

		std::vector<void*> vec = contB->get_vector();
		for (int i = 0; i < vec.size(); i++) {
			ServerRoom<Repeater>* devices = static_cast<ServerRoom<Repeater>*>(vec[i]);
			for (int j = 0; j < devices->size(); j++) {
				Repeater* device = (*devices)[j];
				std::string type_name = device->type_name();

				String^ line = "";
				line += gcnew String(type_name.c_str()) + ",";
				line += gcnew String(device->get_address().as_string().c_str()) + ",";
				line += (dynamic_cast<Switch*>(device) ? dynamic_cast<Switch*>(device)->get_capacity().ToString() : "") + ",";
				line += gcnew String(dynamic_cast<Gateway*>(device) ? dynamic_cast<Gateway*>(device)->get_protocol().c_str() : "") + ",";
				line += dynamic_cast<WLRepeater*>(device) ? gcnew String(dynamic_cast<WLRepeater*>(device)->get_ssid().c_str()) + ",[REDACTED]," : ",,";

				writer->WriteLine(line);
			}
		}
		writer->Close();
	}
}

/**
* Метод, подключающий клиентов из текстового файла к устройствам
*/
System::Void WinUI::GUI::buttonLoadFileC_Click(System::Object^ sender, System::EventArgs^ e) {
	openFileDialog1->FileName = "";
	openFileDialog1->ShowDialog();
	if (openFileDialog1->FileName != "") {
		StreamReader^ reader = gcnew StreamReader(openFileDialog1->FileName, Encoding::GetEncoding("windows-1251"));
		bool error = false;
		do {
			System::String^ line = reader->ReadLine()->Trim(' ');
			if (line != "") {
				if (line == "name,address,bytes,type,connect_to,passwd") continue;
				cli::array<System::String^>^ data = line->Split(',');
				try {
					Client cli = Client();
					cli.set_name(to_string(data[0]->Trim(' ')));
					cli.set_address(MAC_Address(to_string(data[1]->Trim(' '))));
					// TODO: bytes
					cli.set_type(Int32::Parse(data[3]->Trim(' ')) == 1 ? ClientType::Wireless : ClientType::Wired);
					connectTo(cli, data[4]->Trim(' '), false, data[5]->Trim(' '));
				}
				catch (std::exception) {
					error = true;
				}
				catch (System::Exception^) {
					error = true;
				}
			}
		} while (reader->Peek() != -1);
		updateAllTables();
		if (error) warning("Не удалось подключить некоторых клиентов из файла");
		reader->Close();
	}
}

unsigned char* WinUI::GUI::loadBinary(String^ filename) {
	Stream^ stream = File::Open(filename, FileMode::Open);
	BinaryReader^ reader = gcnew BinaryReader(stream);
	array<unsigned char>^ arr =  reader->ReadBytes(stream->Length);
	unsigned char* bytes = new unsigned char[stream->Length];
	for (int i = 0; i < stream->Length; i++)
		bytes[i] = arr[i];
	return bytes;
}

/**
* Метод, сохраняющий данные о подключенных клиентах в текстовый файл
*/
System::Void WinUI::GUI::buttonSaveFileC_Click(System::Object^ sender, System::EventArgs^ e) {
	saveFileDialog1->FileName = "";
	saveFileDialog1->ShowDialog();

	if (saveFileDialog1->FileName != "") {
		StreamWriter^ writer = gcnew StreamWriter(saveFileDialog1->FileName);
		writer->WriteLine("name,address,bytes,type,connect_to,passwd"); // Заголовок

		std::vector<void*> vec = contB->get_vector();
		for (int i = 0; i < vec.size(); i++) {
			ServerRoom<Repeater>* devices = static_cast<ServerRoom<Repeater>*>(vec[i]);
			for (int j = 0; j < devices->size(); j++) {
				std::vector<Client> clients = (*devices)[j]->get_clients();
				for (int k = 0; k < clients.size(); k++) {
					String^ line = "";
					line += gcnew String(clients[k].get_name().c_str()) + ",";
					line += gcnew String(clients[k].get_address().as_string().c_str()) + ",";
					line += "[REDACTED]" + ",";
					line += (clients[k].get_type() == ClientType::Wireless ? "1" : "0") + ",";
					if (clients[k].get_type() == ClientType::Wireless) {
						line += gcnew String(dynamic_cast<WLRepeater*>((*devices)[j])->get_ssid().c_str()) + ",";
						line += "[REDACTED]";
					}
					else {
						line += gcnew String((*devices)[j]->get_address().as_string().c_str()) + ",";
					}
					writer->WriteLine(line);
				}
			}
		}
		writer->Close();
	}
}

/**
* Метод, вызываемый при загрузке графического интерфейса программы
*/
System::Void WinUI::GUI::GUI_Load(System::Object^ sender, System::EventArgs^ e) {
	updateTable(contRepeater->get_vector(), dataGridViewRepeater);
	updateBTable();
}

