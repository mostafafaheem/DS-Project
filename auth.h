#include <iostream>
#include <bcrypt.h>
#include "models.h"
#include "globals.h"

using namespace std;

class Auth {
public:
	//string hashPassword(const string& password);
	void registerUser(string username, string email, string password, string phone);
	bool loginUser(int loginType, string accountInfo, string password);
};
