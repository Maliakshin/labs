#pragma once
#include <string>
#include <limits>
#include <iostream>
#include <string>
#include "roomtype.h"
using namespace std;
extern int standart_price;
extern int lux_price;
extern int president_price;
int getroomprice(roomtype type);