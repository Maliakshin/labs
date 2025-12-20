#include "menu.h"
#include "okno.h"
#include "hotel.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]

void main(cli::array<System::String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	PPP4::okno from;
	Application::Run(% from);
	PPP4::menu form;
	Application::Run(% form);
}