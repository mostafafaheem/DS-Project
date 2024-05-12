#include "auth.h"
#include "models.h"
#include "globals.h"

//string Auth::hashPassword(const string& password) {
//	char salt[BCRYPT_HASHSIZE];
//	bcrypt_gensalt(12, salt);
//
//	char hash[BCRYPT_HASHSIZE];
//	bcrypt_hashpw(password.c_str(), salt, hash);
//
//	return string(hash);
//}

void Auth::registerUser(string username, string email, string password, string phone) {
	User* newUser = new User(username, email, password, phone);
	usersList.push_back(newUser);
}

bool Auth::loginUser(int loginType, string accountInfo, string password) {
	switch (loginType) {
	case 1:
		for (User* User : usersList) {
			if (User->email == accountInfo && User->password == password) {
				currentLoggedIn = User;
				return true;
			}
		}
		break;
	case 2:
		for (User* User : usersList) {
			if (User->username == accountInfo && User->password == password) {
				currentLoggedIn = User;
				return true;
			}
		}
		break;
	case 3:
		for (User* User : usersList) {
			if (User->phoneNumber == accountInfo && User->password == password) {
				currentLoggedIn = User;
				return true;
			}
		}
		break;
	}
	return false;
}
