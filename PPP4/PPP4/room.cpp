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
void room::new_guest(int passport, string name, string surname, int days) {
	if (client == nullptr) {
		client = new guest(passport, name,surname, days);
	}
}
int room::get_profit() {
	return client->get_days() * price;
}
int room::get_passport() {
	return client->get_passport();
}
array<string, 4> room::get_guest_info() {
	return client->get_info();
}
