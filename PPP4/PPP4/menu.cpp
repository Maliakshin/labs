#include "menu.h"
#include "hotel.h"
#include "input.h"
#include "password.h"
#include <msclr/marshal.h>
#include <msclr/marshal_cppstd.h>
#include <string>
using namespace msclr::interop;
using namespace System::IO;


using namespace System; //
using namespace System::Windows::Forms;//
System::Void PPP4::menu::update() {
    label24->Text = Convert::ToString(hotel::current->free_rooms(roomtype::standart));
    label25->Text = Convert::ToString(hotel::current->free_rooms(roomtype::lux));
    label27->Text = Convert::ToString(hotel::current->free_rooms(roomtype::president));
}
System::Void PPP4::menu::setdata() {
    label2->Text = gcnew System::String(hotel::current->name.c_str());
    label14->Text = Convert::ToString(hotel::current->rooms.size());
    label13->Text = Convert::ToString(standart_price);
    label12->Text = Convert::ToString(hotel::current->luxrooms.size());
    label11->Text = Convert::ToString(lux_price);
    label10->Text = Convert::ToString(hotel::current->presidentrooms.size());
    label9->Text = Convert::ToString(president_price);
    update();
}
System::Void PPP4::menu::button1_Click(System::Object^ sender, System::EventArgs^ e) 
{
    int a = hotel::current->get_profit(Convert::ToInt32(numericUpDown1->Value));
    label16->Visible = true;
    if (a != 0) {
        label16->Text = Convert::ToString(a);
    }
    else {
        label16->Text = "Такого нету";
    }
}
System::Void PPP4::menu::inClient(roomtype type) {
    label22->Visible = true;
    int b = hotel::current->new_client(type, Convert::ToInt32(numericUpDown3->Value), msclr::interop::marshal_as<std::string>(textBox2->Text), msclr::interop::marshal_as<std::string>(textBox1->Text), Convert::ToInt32(numericUpDown2->Value));
    if (b == 0) {
        label22->Text = "Этот паспорт уже был добавлен ранее";
    }
    if (b == 1) {
        label22->Text = "Клиент добавлен в базу";
        update();
    }
    if (b == 2) {
        label22->Text = "Все комнаты этого типа уже заняты";
    }
}
System::Void PPP4::menu::button2_Click(System::Object^ sender, System::EventArgs^ e) { // люкс
    inClient(roomtype::lux);
}
System::Void PPP4::menu::button3_Click(System::Object^ sender, System::EventArgs^ e) { 
    inClient(roomtype::president);
}
System::Void PPP4::menu::button4_Click(System::Object^ sender, System::EventArgs^ e) { 
    inClient(roomtype::standart);
}
System::Void PPP4::menu::button5_Click(System::Object^ sender, System::EventArgs^ e)
{
	// here  openFile dialog 
	String^ fileName;
	OpenFileDialog^ openDlg = gcnew OpenFileDialog();
	openDlg = openFileDialog1;
	openDlg->Filter = "(*.txt)|*.txt";
	openDlg->ShowDialog();
	fileName = openDlg->FileName;

	String^ dataFrom;

	StreamReader^ reader = File::OpenText(fileName);
	while ((dataFrom = reader->ReadLine()) != nullptr) {
		cli::array <String^, 1>^ StringArray = dataFrom->Split();
        int b;
        switch (Convert::ToInt32(StringArray[0]))
        {
        case (1):
            b = hotel::current->new_client(roomtype::standart, Convert::ToInt32(StringArray[1]), string((gcnew marshal_context())->marshal_as<const char*>(StringArray[2])), string((gcnew marshal_context())->marshal_as<const char*>(StringArray[3])), Convert::ToInt32(StringArray[4]));
            break;
        case (2):
            b = hotel::current->new_client(roomtype::lux, Convert::ToInt32(StringArray[1]), string((gcnew marshal_context())->marshal_as<const char*>(StringArray[2])), string((gcnew marshal_context())->marshal_as<const char*>(StringArray[3])), Convert::ToInt32(StringArray[4]));
            break;
        case (3):
            b = hotel::current->new_client(roomtype::president, Convert::ToInt32(StringArray[1]), string((gcnew marshal_context())->marshal_as<const char*>(StringArray[2])), string((gcnew marshal_context())->marshal_as<const char*>(StringArray[3])), Convert::ToInt32(StringArray[4]));
            break;
        }
   	}
	reader->Close();
    update();

}
System::Void PPP4::menu::button6_Click(System::Object^ sender, System::EventArgs^ e) {
    hotel::current->data_output();
}
System::Void PPP4::menu::button7_Click(System::Object^ sender, System::EventArgs^ e) {
    password^ newForm = gcnew password();
    newForm->Show();
}