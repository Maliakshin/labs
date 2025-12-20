#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "room.h"
#include "input.h"
#include "roomtype.h"
#include "okno.h"
using namespace std;
class hotel {
public:
	vector <room> rooms;
	vector <room> luxrooms;
	vector <room> presidentrooms;
	static hotel* current;
	int price_st = 100;
	string name;
	hotel(string a, int b, int c, int d, int f, int g, int h);
	static void Create(const std::string& name, int p1, int p2, int p3, int p4, int p5, int p6);
	static hotel* GetCurrent() { return current; }
	static void Clear() {
		if (current != nullptr) {
			delete current;
			current = nullptr;
		}
	}
	~hotel();
	int new_client(roomtype type, int passport, string name, string surname, int days);
	int free_rooms(roomtype type);
	void guests();
	int get_profit(int passport);
};