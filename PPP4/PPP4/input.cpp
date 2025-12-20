#include "input.h"
using namespace std;
int standart_price = 0;
int lux_price = 0;
int president_price = 0;

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