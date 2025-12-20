#include "guest.h"

guest::guest(int set_passport, string Name, string Surname, int Days) {
	name = Name;
	surname = Surname;
	days = Days;
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
	return passport;
}