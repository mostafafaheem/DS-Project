#pragma once
#include <iostream>
#include <regex>
#include <conio.h>
#include "auth.h"
#include "display.h"
#include "models.h"
#include "globals.h"
#include "admin.h"
using namespace std;

class Display {
public:
	void mainWindow();
	void loginWindow();
	void signupWindow();
};