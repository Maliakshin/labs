#include "guest.h"

guest::guest(int set_passport, string Name, string Surname, int Days) {
	name = Name;
	surname = Surname;
	days = Days;
	passport = set_passport;
}
array<string, 4>  guest::get_info() {
	array<string, 4> arr;
	arr[0] = name;
	arr[1] = surname;
	arr[2] = to_string(passport);
	arr[3] = to_string(days);
	return arr;
}
int guest::get_days() {
	return days;
}
int guest::get_passport() {
	return passport;
}