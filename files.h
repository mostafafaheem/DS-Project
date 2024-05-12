#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include "globals.h"
#include "models.h"

using namespace std;

class Files {
public:
	vector<User> readUserDataFromFile(const string& filename);
	void writeUserDataToFile(const string& filename, const vector<User>& users);
};