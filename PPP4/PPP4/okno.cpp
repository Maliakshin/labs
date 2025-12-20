#include "okno.h"
#include "menu.h"
#include "hotel.h"
#include <msclr/marshal_cppstd.h>
System::Void PPP4::okno::button1_Click(System::Object^ sender, System::EventArgs^ e) // button accept 
{
	hotel::Create(string(msclr::interop::marshal_as<std::string>(textBox1->Text)), Convert::ToInt32(numericUpDown1->Value), Convert::ToInt32(numericUpDown2->Value), Convert::ToInt32(numericUpDown3->Value), Convert::ToInt32(numericUpDown4->Value), Convert::ToInt32(numericUpDown5->Value), Convert::ToInt32(numericUpDown6->Value));
	this->Close();
}