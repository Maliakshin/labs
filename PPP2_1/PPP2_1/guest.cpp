#include "guest.h"

guest::guest(int set_passport) {
	name = input_name("guest name: ");
	surname = input_name("guest surname: ");
	days = input("how many days: ");
	passport = set_passport;
}
void guest::get_info() {
	cout << "name:" << endl;
	cout << name << endl;
	cout << "surname:" << endl;
	cout << surname << endl;
	cout << "days:" << endl;
	cout << days << endl;
	cout << "passport:" << endl;
	cout << passport << endl;
}
int guest::get_days() {
	return days;
}
int guest::get_passport() {
	cout << 1 << endl;
	return passport;
}