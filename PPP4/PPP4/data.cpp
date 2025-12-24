#include "data.h"
#include "hotel.h"
#include <msclr/marshal_cppstd.h>
using namespace msclr::interop;
System::Void PPP4::data::update() {
	dataGridView1->Rows->Clear();
	vector <array<string, 4>> guests = hotel::current->guests();
	for (int i = 0; i < guests.size(); i++) {
		switch (static_cast<int>(hotel::current->get_roomtype(stoi(guests[i][2]))))
		{
		case(1):
			dataGridView1->Rows->Add(marshal_as<String^>(guests[i][0]), marshal_as<String^>(guests[i][1]), marshal_as<String^>(guests[i][2]), marshal_as<String^>(guests[i][3]), "standart");
			break;
		case(2):
			dataGridView1->Rows->Add(marshal_as<String^>(guests[i][0]), marshal_as<String^>(guests[i][1]), marshal_as<String^>(guests[i][2]), marshal_as<String^>(guests[i][3]), "lux");
			break;
		case(3):
			dataGridView1->Rows->Add(marshal_as<String^>(guests[i][0]), marshal_as<String^>(guests[i][1]), marshal_as<String^>(guests[i][2]), marshal_as<String^>(guests[i][3]), "president");
			break;
		}	
	}
}

System::Void PPP4::data::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	update();
}