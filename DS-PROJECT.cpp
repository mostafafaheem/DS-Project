#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <conio.h>
#include <sstream>
#include "search.h"
#include "auth.h"
#include "database.h"
#include "display.h"

using namespace std;

int main()
{

    Display display;
    display.mainWindow();
    return 0;
}



//reads the array of doctors in the file stream
int readfiledoctor(dr arr[]) {
	// if the file is empty make sure that it contains at least 0
	ifstream f;
	f.open("tst.txt");
	int sz;
	f >> sz;

	for (size_t i = 0; i < sz; i++)
	{
		f >> arr[i].username;
		f >> arr[i].password;
		f >> arr[i].name;
		f >> arr[i].email;
		f >> arr[i].phone;
		f >> arr[i].major;
		f >> arr[i].price;
		f >> arr[i].clinic;
		f >> arr[i].governorate;
		f >> arr[i].timesLen;
		for (size_t j = 0; j < arr[i].timesLen; j++) {
			f >> arr[i].times[j].day;
			f >> arr[i].times[j].hours;
		}
	}

	f.close();
	return sz;
};
//writes the array of doctors in the file stream
void writefiledoctor(dr arr[], int sz) {
	ofstream f;
	f.open("tst.txt");
	f << sz << endl;

	for (size_t i = 0; i < sz; i++) {
		f << arr[i].username << endl;
		f << arr[i].password << endl;
		f << arr[i].name << endl;
		f << arr[i].email << endl;
		f << arr[i].phone << endl;
		f << arr[i].major << endl;
		f << arr[i].price << endl;
		f << arr[i].clinic << endl;
		f << arr[i].governorate << endl;
		f << arr[i].timesLen << endl;
		for (size_t j = 0; j < arr[i].timesLen; j++)
		{
			f << arr[i].times[j].day << endl;
			f << arr[i].times[j].hours << endl;
		}
	}
	f.close();
}
//reads the array of appointments in the file stream