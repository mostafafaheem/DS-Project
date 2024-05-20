#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <conio.h>
#include <sstream>
#include "search.h"
#include "display.h"
#include "files.h"

using namespace std;

int main()
{
	const string filename = "userdata.txt";
	Files files;
    Display display;
	files.readUserDataFromFile(filename, usersList);
	files.readPropertyDataFromFile(filename, propertyMap);
    display.mainWindow();
	files.writeUserDataToFile(filename, usersList);
	files.writePropertyDataToFile(filename,propertyMap);
	for (User* user : usersList) {
		delete user;
	}
    return 0;
}