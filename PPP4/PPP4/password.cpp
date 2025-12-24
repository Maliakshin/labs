#include "password.h"
#include "data.h"

System::Void PPP4::password::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	if (textBox1->Text == "1") {
		data^ newForm = gcnew data(true);
		newForm->Show();
	}
	else {
		data^ newForm = gcnew data(false);
		newForm->Show();
	}
	this->Close();
}