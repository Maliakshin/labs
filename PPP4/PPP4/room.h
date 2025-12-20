#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "input.h"
#include "guest.h"
#include "roomtype.h"
using namespace std;
class room {
private:
	int price;
	int room_number;
	guest* client = nullptr;
public:
	room(int x, roomtype type);
	bool free();
	void new_guest(int passport, string name, string surname, int days);
	int get_profit();
	int get_passport();
	void get_guest_info();
};
