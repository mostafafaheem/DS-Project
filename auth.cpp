#include "auth.h"
#include "models.h"
#include "globals.h"
string Auth::registerUser(string username, string email, string password, string phone) {
	if (username == "" || email == "" || password == "" || phone == "" ) return "input all fields";
	if (password.size() < 8 || password.size() > 16) return "invlaid password";
	for (char i : phone) if (!isdigit(i)) return "invlaid phone number";
	user* newUser = new user(username, email, password, phone);
	usersList.push_back(newUser);
	return "success";

}
bool Auth::loginUser(string email, string password) {
	
	for (user* User : usersList) {
		if (User->email == email && User->password == password) {
			currentLoggedIn = User;
			return true;
		}

	}
	return false;
}
