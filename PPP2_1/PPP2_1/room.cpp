#include "room.h"

room :: room(int x, roomtype type)
{
	price = getroomprice(type);
	room_number = x;
}
bool room::free() {
	if (client == nullptr) {
		return true;
	}
	else {
		return false;
	}
}
void room::new_guest(int passport) {
	if (client == nullptr) {
		client = new guest(passport);
	}
}
void room::get_profit() {
	cout << "profit:" << endl;
	cout << client->get_days() * price << endl;
}
int room::get_passport() {
	return client->get_passport();
}
void room::get_guest_info() {
	client->get_info();
}
