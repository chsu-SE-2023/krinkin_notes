#include "GUI.h"

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
