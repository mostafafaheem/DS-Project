#pragma once
#include<iostream>
#include<string>
#include "globals.h"

using namespace std;

class Admin {
public:
	void deleteProperty(int id);
	void editProperty(int id, string editName, string edit);
	void approveProperty(int id);
	void highlightProperty(int id);
};