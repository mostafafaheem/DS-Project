#pragma once
#include<iostream>
#include<string>
#include "globals.h"

using namespace std;

class Admin {
public:
	void deleteProperty(int id);
	void editProperty(int id);
	void approveProperty(int id);
	void highlightProperty(int id);
};