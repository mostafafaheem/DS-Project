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
	Files instance;
    Display display;
	vector<User> users = instance.readUserDataFromFile(filename);
    display.mainWindow();
	instance.writeUserDataToFile(filename, users);

    return 0;
}



//reads the array of doctors in the file stream
