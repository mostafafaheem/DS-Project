#include<iostream>
using namespace std;

class Auth {
public:
	string registerUser(string username, string email, string password, string phone);
	bool loginUser(int loginType, string accountInfo, string password);
};
