#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include "globals.h"
#include "property.h"
#include "user.h"

using namespace std;

class Files {
public:
	void readUserDataFromFile(const string& filename, vector<User*>& users);
	void writeUserDataToFile(const string& filename, const vector<User*>& users);
	void writePropertyDataToFile(const std::string& filename, const std::unordered_map<int, Property>& properties);
	void readPropertyDataFromFile(const std::string& filename, std::unordered_map<int, Property>& properties);
};