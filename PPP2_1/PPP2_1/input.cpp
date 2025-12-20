#include "input.h"
using namespace std;
int standart_price = 0;
int lux_price = 0;
int president_price = 0;
int input(string x) {
	int y;
	do
	{
		cout << x << endl;
		cin >> y;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (y < 1 || y > 2000000000);
	return y;
}
string input_name(string x) {
	string y;
	cout << x << endl;
	cin >> y;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return y;
}
int getroomprice(roomtype type) {
	switch (static_cast<int>(type)) {
	case 1:
		return standart_price;
		break;
	case 2:
		return lux_price;
		break;
	case 3:
		return president_price;
		break;
	}
}