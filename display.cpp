#include "display.h"
#include "auth.h"
using namespace std;
void Display::mainWindow() {
    cout << "Are you an existing user? (select 1), or would you like to create an account? (select 2): ";
    bool validInput = false;
    while (!validInput) {
        cin >> selection;

        switch (selection) {
        case 1:
            Display::loginWindow();
            validInput = true;
            break;
        case 2:
            Display::signupWindow();
            validInput = true;
            break;
        default:
            cout << "Incorrect input, please try again: ";
        }
    }

}

void Display::loginWindow(); {
    string entry;
    cout << "Please enter your username or email to sign in:" << endl;
    static const regex emailPattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    static const regex usernamePattern("^[a-zA-Z0-9_]{3,20}$");
    static const regex phonePattern("^(010|011|012|015)\\d{8}$");
    cin >> entry;
    do
    {
        if (regex_match(entry, email)) {
            cout << "Please enter your password:" << endl;
            cin << password;
        attempt.loginUser(entry, password)
        }
        else if (std::regex_match(entry, username)) {
            // sign in with username logic
        }
        else if (std::regex_match(entry, phonePattern)) {
            // sign in with phone number logic
        }
        else {
            cout << "Invalid input, please try again!" << endl;
        }
    } while (!regex_match(entry, email) || !regex_match(entry, username));
}

void Display::signupWindow(); {
    static const regex emailPattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    static const regex usernamePattern("^[a-zA-Z0-9_]{3,20}$");
    static const regex passwordPattern("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[@$!%*?&])[A-Za-z\\d@$!%*?&]{8,}$");
    static const regex phonePattern("^(010|011|012|015)\\d{8}$");

    string email;
    string username;
    string password;
    string phonenumber;
    Auth attempt;
    cout << "Please enter your email: " << endl;
    do {
        cin >> email;
        if (!regex_match(email, emailPattern))
            cout << "Incorrect format, please try again:" << endl;
    } while (!regex_match(entry, emailPattern));
    cout << "Now, please enter your password: " << endl;
    do {
        cin >> password;
        if (!regex_match(password, passwordPattern))
            cout << "Your password should contain at least 8 characters, including at least one uppercase letter, one lowercase letter, one digit, and one special character, please try again:" << endl;
    } while (!regex_match(password, email));
    cout << "Now, please enter your phone number: " << endl;
    do {
        cin >> phonenumber;
        if (!regex_match(phonenumber, numberPattern))
            cout << "Incorrect format, please try again:" << endl;
    } while (!regex_match(phonenumber, numberPattern));
    cout << "Finally, please enter your chosen username: " << endl;
    do {
        cin >> username;
        if (!regex_match(username, usernamePattern))
            cout << "Incorrect format, please try again:" << endl;
    } while (!regex_match(username, usernamePattern));
    attempt.registerUser(username, email, password, phoneNumber); 
}
