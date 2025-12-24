#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "input.h"
#include "roomtype.h"
#include <array>
class guest {
private:
	string name;
	string surname;
	int passport= 0;
	int days;
public:
	guest(int set_passport, string name, string surname, int days);
	array<string, 4>  get_info();
	int get_days();
	int get_passport();
};