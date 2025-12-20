#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "room.h"
#include "input.h"
#include "roomtype.h"
using namespace std;
class hotel {
private:
	vector <room> rooms;
	vector <room> luxrooms;
	vector <room> presidentrooms;
	string name;
public:
	int price_st = 100;
	hotel();
	~hotel();
	void new_client(roomtype type);
	void free_rooms();
	void guests();
	void get_profit();
	void get_info();
};