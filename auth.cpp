#include "auth.h"
#include "models.h"
#include "globals.h"

string Auth::registerUser(string username, string email, string password, string phone) {
	user* newUser = new user(username, email, password, phone);
	usersList.push_back(newUser);
	return "success";
}

bool Auth::loginUser(char method, string accountInfo, string password) {
	
	for (user* User : usersList) {
		if (User->email == email && User->password == password) {
			currentLoggedIn = User;
			return true;
		}
	}
	return false;
}
