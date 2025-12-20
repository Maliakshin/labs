#include "hotel.h"

int price_st = 100;
hotel::hotel() {
	name = input_name("hotel name:");
	int rooms_amount = input("amount of standart rooms:");
	standart_price = input("price of standart rooms:");
	int luxrooms_amount = input("amount of lux rooms:");
	lux_price = input("price of lux rooms:");
	int prrooms_amount = input("amount of president rooms:");
	president_price = input("price of president rooms:");
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

void hotel::new_client(roomtype type) {
	int passport = input("passport number (together): ");
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
		cout << "this passport already used!" << endl;
		return;
	}
	flag = false;
	switch (static_cast<int>(type))

	{
	case(1):
		for (int i = 0; i < rooms.size(); i++) {
			if (rooms[i].free()) {
				rooms[i].new_guest(passport);
				cout << "Guest added" << endl;
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			cout << "all rooms of this type are busy!" << endl;
		}
		break;
	case(2):
		for (int i = 0; i < luxrooms.size(); i++) {
			if (luxrooms[i].free()) {
				luxrooms[i].new_guest(passport);
				cout << "Guest added" << endl;
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			cout << "all rooms of this type are busy!" << endl;
		}
		break;
	case(3):
		for (int i = 0; i < presidentrooms.size(); i++) {
			if (presidentrooms[i].free()) {
				presidentrooms[i].new_guest(passport);
				cout << "Guest added" << endl;
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			cout << "all rooms of this type are busy!" << endl;
		}
		break;
	}

}
void hotel::free_rooms() {
	cout << "free standart rooms: " << endl;
	for (int i = 0; i < rooms.size(); i++) {
		if (rooms[i].free()) {
			cout << "standart " << i + 1 << endl;
		}
	}
	cout << "free lux rooms: " << endl;
	for (int i = 0; i < luxrooms.size(); i++) {
		if (luxrooms[i].free()) {
			cout << "lux " << i + 1 << endl;

		}
	}
	cout << "free president rooms: " << endl;
	for (int i = 0; i < presidentrooms.size(); i++) {
		if (presidentrooms[i].free()) {
			cout << "president " << i + 1 << endl;
		}
	}
}
void hotel::guests() {
	for (int i = 0; i < rooms.size(); i++) {
		if (!rooms[i].free()) {
			cout << "room standart:" << endl;
			cout << i + 1 << endl;
			rooms[i].get_guest_info();
		}
	}
	for (int i = 0; i < luxrooms.size(); i++) {
		if (!luxrooms[i].free()) {
			cout << "room lux:" << endl;
			cout << i + 1 << endl;
			luxrooms[i].get_guest_info();
		}
	}
	for (int i = 0; i < presidentrooms.size(); i++) {
		if (!presidentrooms[i].free()) {
			cout << "room president:" << endl;
			cout << i + 1 << endl;
			presidentrooms[i].get_guest_info();
		}
	}
}
void hotel::get_profit() {
	int passport = input("passport (together): ");
	bool fl = false;
	for (int i = 0; i < rooms.size(); i++) {
		if (!rooms[i].free()) {
			if (passport == rooms[i].get_passport()) {
				rooms[i].get_profit();
				fl = true;
				break;
			}
		}
	}
	if (!fl) {
		for (int i = 0; i < luxrooms.size(); i++) {
			if (!luxrooms[i].free()) {
				if (passport == luxrooms[i].get_passport()) {
					luxrooms[i].get_profit();
					fl = true;
					break;
				}
			}
		}
	}
	if (!fl) {
		for (int i = 0; i < presidentrooms.size(); i++) {
			if (!presidentrooms[i].free()) {
				cout << 12312 << endl;
				if (passport == presidentrooms[i].get_passport()) {
					presidentrooms[i].get_profit();
					fl = true;
					break;
				}
			}
		}
	}
	if (!fl) {
		cout << "no such guest" << endl;
	}
}
void hotel::get_info() {
	cout << "name: " << endl;
	cout << name << endl;
	cout << "amount of standart rooms:" << endl;
	cout << rooms.size() << endl;
	cout << "price of standart rooms:" << endl;
	cout << standart_price << endl;
	cout << "amount of lux rooms:" << endl;
	cout << luxrooms.size() << endl;
	cout << "price of lux rooms:" << endl;
	cout << lux_price << endl;
	cout << "amount of president rooms:" << endl;
	cout << presidentrooms.size() << endl;
	cout << "price of president rooms:" << endl;
	cout << president_price << endl;
}