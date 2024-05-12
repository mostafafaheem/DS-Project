#include "display.h"
#include "auth.h"
#include "models.h"
#include "globals.h"
#include "admin.h"
using namespace std;
void Display::mainWindow() {
    cout <<""<< "Are you an existing user? (select 1), or would you like to create an account? (select 2): ";
    bool validInput = false;
    int selection;
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
        Admin session;
        if (currentLoggedIn != NULL && currentLoggedIn->isAdmin)
        {
            cout << "Welcome back Mr. " << name << "! choose which action you want to perform:";
            int adminSelection;
            do
            {
                cout << "1. Delete Property" << endl << "2. Edit Property" << endl << "3.Approve Property" << endl << "4. Highlight Property" << endl;
                switch (adminSelection)
                {
                case 1:
                    session.deleteProperty();
                    break;
                case 2:
                    session.editProperty();
                    break;
                case 3:
                    session.approveProperty();
                    break;
                case 4:
                    session.highlightProperty();
                    break;
                default:
                    break;
                }
            } while (adminSelection == 1 || adminSelection == 2 || adminSelection == 3 || adminSelection == 4);
        }
        else
        {

        }
    }
}

void Display::loginWindow() {
    string entry;
    string password;
    static const regex emailPattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    static const regex usernamePattern("^[a-zA-Z0-9_]{3,20}$");
    static const regex passwordPattern("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[@$!%*?&])[A-Za-z\\d@$!%*?&]{8,}$");
    static const regex phonePattern("^(010|011|012|015)\\d{8}$");
    Auth attempt;
    int loginType;
    bool isLoggedIn;
    cout << "Please enter your username, email, or phone number to sign in:" << endl;
    do {
        cin >> entry;
        if (regex_match(entry, emailPattern)) {
            loginType = 1;
        }
        else if (regex_match(entry, usernamePattern)) {
            loginType = 2;
        }
        else if (regex_match(entry, phonePattern)) {
            loginType = 3;
        }
        else {
            cout << "Invalid input, please try again!" << endl;
            continue;
        }
        cout << "Please enter your password:" << endl;
        char c;
        while ((c = _getch()) != 13) { 
            if (c == '\b') { 
                if (!password.empty()) {
                    password.pop_back();
                    cout << "\b \b"; 
                }
            }
            else if (isprint(c)) { 
                password += c;
                cout << "*"; 
            }
        }
        cout << endl;
        if (!regex_match(password, passwordPattern)) {
            cout << "Your password should contain at least 8 characters, including at least one uppercase letter, one lowercase letter, one digit, and one special character, please try again:" << endl;
            continue;
        }
        isLoggedIn = attempt.loginUser(loginType, entry, password);
        if (!isLoggedIn) {
            cout << "This account does not exist or the credentials are incorrect, please try again!" << endl;
        }
    } while (!isLoggedIn);
}

void Display::signupWindow() {
    static const regex emailPattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    static const regex usernamePattern("^[a-zA-Z0-9_]{3,20}$");
    static const regex passwordPattern("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[@$!%*?&])[A-Za-z\\d@$!%*?&]{8,}$");
    static const regex phonePattern("^(010|011|012|015)\\d{8}$");

    string email;
    string username;
    string password;
    string phoneNumber;
    Auth attempt;

    cout << "Please enter your email: " << endl;
    do {
        cin >> email;
        if (!regex_match(email, emailPattern)) {
            cout << "Incorrect format, please try again:" << endl;
            continue;
        }
        for (User* User : usersList) {
            if (User->email == email) {
                cout << "This email is already in use, please try again!" << endl;
                continue;
            }
        }
       } while (!regex_match(email, emailPattern));

    cout << "Now, please enter your password: " << endl;
    do {
        char c;
        while ((c = _getch()) != 13) { 
            if (c == '\b') {
                if (!password.empty()) {
                    password.pop_back();
                    cout << "\b \b";
                }
            }
            else if (isprint(c)) {
                password += c;
                cout << "*"; 
            }
        }
        cout << endl; 
        if (!regex_match(password, passwordPattern)) {
            cout << "Your password should contain at least 8 characters, including at least one uppercase letter, one lowercase letter, one digit, and one special character, please try again:" << endl;
        }

    } while (!regex_match(password, passwordPattern));

    cout << "Now, please enter your phone number: " << endl;
    do {
        cin >> phoneNumber;
        if (!regex_match(phoneNumber, phonePattern)) {
            cout << "Incorrect format, please try again:" << endl;
            continue;
        }
        for (User* User : usersList) {
            if (User->phoneNumber == phoneNumber) {
                cout << "This phone number is already in use, please try again!" << endl;
                continue;
            }
        }
    } while (!regex_match(phoneNumber, phonePattern));

    cout << "Finally, please enter your chosen username: " << endl;
    do {
        cin >> username;
        if (!regex_match(username, usernamePattern)) {
            cout << "Incorrect format, please try again:" << endl;
            continue;
        }
        for (User* User : usersList) {
            if (User->username == username) {
                cout << "This username is already in use, please try again!" << endl;
                continue;
            }
        }
    } while (!regex_match(username, usernamePattern));

    attempt.registerUser(username, email, password, phoneNumber);
}