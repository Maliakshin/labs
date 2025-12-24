#include "hotel.h"
int price_st = 100;

hotel* hotel::current = nullptr;

hotel::hotel(string a, int b,  int c, int d, int f, int g, int h) {
	name = a;
	int rooms_amount = b;
	standart_price = c;
	int luxrooms_amount = d;
	lux_price = f;
	int prrooms_amount = g;
	president_price = h;
	for (int i = 1; i <= rooms_amount; i++) {
		rooms.emplace_back(room(i, roomtype::standart));
	}
	for (int i = 1; i <= luxrooms_amount; i++) {
		luxrooms.emplace_back(room(i, roomtype::lux));
	}
	for (int i = 1; i <= prrooms_amount; i++) {
		presidentrooms.emplace_back(room(i, roomtype::president));
	}
}
hotel::~hotel() {
	cout << "hotel destroyed" << endl;
}
void hotel::Create(const std::string& name, int p1, int p2, int p3, int p4, int p5, int p6) {
	Clear();
	current = new hotel(name, p1, p2, p3, p4, p5, p6);
}


void hotel::data_output() {
	array<string, 4> arr;
	ofstream output("output.csv");
	for (int i = 0; i < rooms.size(); i++) {
		if (!rooms[i].free()) {
			arr = rooms[i].get_guest_info();
			output << arr[0]<<";" << arr[1] << ";" << arr[2] << ";" << arr[3] << "\n";
		}
	}
	for (int i = 0; i < luxrooms.size(); i++) {
		if (!luxrooms[i].free()) {
			arr = luxrooms[i].get_guest_info();
			output << arr[0] << ";" << arr[1] << ";" << arr[2] << ";" << arr[3] << "\n";
		}
	}
	for (int i = 0; i < presidentrooms.size(); i++) {
		if (!presidentrooms[i].free()) {
			arr = presidentrooms[i].get_guest_info();
			output << arr[0] << ";" << arr[1] << ";" << arr[2] << ";" << arr[3] << "\n";
		}
	}
}


int hotel::new_client(roomtype type, int passport, string name, string surname, int days) {
	bool flag = false;
	for (int i = 0; i < rooms.size(); i++) {
		if (!rooms[i].free()) {
			if (passport == rooms[i].get_passport()) {
				flag = true;
				break;
			}
		}
	}
	if (!flag)
	{
		for (int i = 0; i < luxrooms.size(); i++) {
			if (!luxrooms[i].free()) {
				if (passport == luxrooms[i].get_passport()) {
					flag = true;
					break;
				}
			}
		}
	}
	if (!flag)
	{
		for (int i = 0; i < presidentrooms.size(); i++) {
			if (!presidentrooms[i].free()) {
				if (passport == presidentrooms[i].get_passport()) {
					flag = true;
					break;
				}
			}
		}
	}
	if (flag)
	{
		return 0;
	}
	flag = false;
	switch (static_cast<int>(type))
	{
	case(1):
		for (int i = 0; i < rooms.size(); i++) {
			if (rooms[i].free()) {
				rooms[i].new_guest(passport, name, surname, days);
				flag = true;
				return 1;
			}
		}
		if (!flag)
		{
			return 2;
		}
		break;
	case(2):
		for (int i = 0; i < luxrooms.size(); i++) {
			if (luxrooms[i].free()) {
				luxrooms[i].new_guest(passport, name, surname, days);
				flag = true;
				return 1;
			}
		}
		if (!flag)
		{
			return 2;
		}
		break;
	case(3):
		for (int i = 0; i < presidentrooms.size(); i++) {
			if (presidentrooms[i].free()) {
				presidentrooms[i].new_guest(passport, name, surname, days);
				flag = true;
				return 1;
			}
		}
		if (!flag)
		{
			return 2;
		}
		break;
	}

}
vector <array<string, 4>> hotel::guests() {
	vector <array<string, 4>> guests;
	for (int i = 0; i < rooms.size(); i++) {
		if (!rooms[i].free()) {
			guests.emplace_back(rooms[i].get_guest_info());
		}
	}
	for (int i = 0; i < luxrooms.size(); i++) {
		if (!luxrooms[i].free()) {
			guests.emplace_back(luxrooms[i].get_guest_info());
		}
	}
	for (int i = 0; i < presidentrooms.size(); i++) {
		if (!presidentrooms[i].free()) {
			guests.emplace_back(presidentrooms[i].get_guest_info());
		}
	}
	return guests;
}
roomtype hotel::get_roomtype(int passport) {
	for (int i = 0; i < rooms.size(); i++) {
		if (!rooms[i].free()) {
			if (passport == rooms[i].get_passport()) {
				return roomtype::standart;
			}
		}
	}
	for (int i = 0; i < luxrooms.size(); i++) {
		if (!luxrooms[i].free()) {
			if (passport == luxrooms[i].get_passport()) {
				return roomtype::lux;
			}
		}
	}
	for (int i = 0; i < presidentrooms.size(); i++) {
		if (!presidentrooms[i].free()) {
			cout << 12312 << endl;
			if (passport == presidentrooms[i].get_passport()) {
				return roomtype::president;
			}
		}
	}
}
int hotel::free_rooms(roomtype type) {
	int c = 0;
	switch (static_cast<int>(type))
	{
	case(1):
		for (int i = 0; i < rooms.size(); i++) {
			if (rooms[i].free()) {
				c++;
			}
		}
		return c;
		break;
	case(2):
		for (int i = 0; i < luxrooms.size(); i++) {
			if (luxrooms[i].free()) {
				c++;
			}
		}
		return c;
		break;
	case(3):
		for (int i = 0; i < presidentrooms.size(); i++) {
			if (presidentrooms[i].free()) {
				c++;
			}
		}
		return c;
		break;
	}
}
int hotel::get_profit(int passport) {
	for (int i = 0; i < rooms.size(); i++) {
		if (!rooms[i].free()) {
			if (passport == rooms[i].get_passport()) {
				return rooms[i].get_profit();
			}
		}
	}
	for (int i = 0; i < luxrooms.size(); i++) {
		if (!luxrooms[i].free()) {
			if (passport == luxrooms[i].get_passport()) {
				return luxrooms[i].get_profit();
			}
		}
	}
	for (int i = 0; i < presidentrooms.size(); i++) {
		if (!presidentrooms[i].free()) {
			cout << 12312 << endl;
			if (passport == presidentrooms[i].get_passport()) {
				return presidentrooms[i].get_profit();
			}
		}
	}
	return 0;
}
