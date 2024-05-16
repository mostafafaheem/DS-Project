#include <iostream>
#include <regex>
#include <conio.h>
#include "auth.h"
#include "property.h"
#include "user.h"
#include "globals.h"
#include "admin.h"
//#include "search.h"

using namespace std;

class Display {
public:
	void mainWindow();
	void loginWindow();
	void signupWindow();
};