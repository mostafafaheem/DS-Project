#include <iostream>
#include <algorithm> 
#include <regex>
#include <conio.h>
#include <iomanip>
#include "auth.h"
#include "property.h"
#include "user.h"
#include "globals.h"
#include "admin.h"
#include <random>
#include <ctime>

using namespace std;

class Display {
public:
	void mainWindow();
	void loginWindow();
	void signupWindow();
};