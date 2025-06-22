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

std::string ShowWLANDialog()
{
	WinUI::WLANDialog^ form = gcnew WinUI::WLANDialog();
	form->Show();
	if (form->result == Windows::Forms::DialogResult::OK)
		return WinUI::GUI::to_string(form->passwd);
	else return "";
}
