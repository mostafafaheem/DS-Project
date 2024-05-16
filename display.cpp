#include "display.h"

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
            break;
        }
        Admin session;
        if (currentLoggedIn != NULL && currentLoggedIn->isAdmin)
        {
            cout << "Welcome back Mr. " << "name" << "! choose which action you want to perform:";
            int adminSelection;
            int id;
            cout << "1. Delete Property" << endl << "2. Edit Property" << endl << "3.Approve Property" << endl << "4. Highlight Property" << endl;
            do
            {
            cin >> adminSelection;
                switch (adminSelection)
                {
                case 1:
                    cout << "Choose the id of the property you want to delete: " << endl;
                    cin >> id;
                    session.deleteProperty(id);
                    break;
                case 2:
                    cout << "Choose the id of the property you want to edit: " << endl;
                    cin >> id;
                    session.editProperty(id);
                    break;
                case 3:
                    cout << "Choose the id of the property you want to approve: " << endl;
                    cin >> id;
                    session.approveProperty(id);
                    break;
                case 4:
                    cout << "Choose the id of the property you want to hicghlight: " << endl;
                    cin >> id;
                    session.highlightProperty(id);
                    break;
                default:
                    cout << "Incorrect input, please try again: ";
                    break;
                }
            } while (adminSelection == 1 || adminSelection == 2 || adminSelection == 3 || adminSelection == 4);
        }
        else if (currentLoggedIn != NULL && !currentLoggedIn->isAdmin)
        {
            cout << "Welcome to the Real Estate Portal System! What actions would you like to perform?" << endl;
            cout << "1-Search for a property" << endl;
            cout << "2-Show random propertiess you may like" << endl;
            cout << "3-Compare properties" << endl;
            cout << "4-Post your own property" << endl;
            int userSelection;
            int minBeds;
            int minBaths;
            int maxBeds;
            int maxBaths;
            int beds;
            int baths;
            string type;
            string description;
            string location;
            float minPrice;
            float maxPrice;
            float price;
            int saleRent;
            int criteria;
            Search instance;
            do
            {
                cin >> userSelection;
            switch (userSelection)
            {
            case 1:
                cout << "Where are you searching for properties? Type \"anywhere\" if you do not have any specific preference: " << endl;
                cin >> location;
                cout << "What is the least number of bedrooms you would like in your property? " << endl;
                cin >> minBeds;
                cout << "and the most? "<< endl;
                cin >> maxBeds;
                cout << "What is the least number of bathrooms you would like in your property? " << endl;
                cin >> minBaths;
                cout << "and the most? " << endl;
                cin >> maxBaths;
                cout << "Would you like seeing properties for rent (type\"rental\"), sale (type\"sale\"), or both (type\"both\")?" << endl;
                cin >> type;
                cout << "What is the minimum price point you are searching for? "<<endl;
                cin >> minPrice;
                cout << "and the maximum? " << endl;
                cin >> maxPrice;
                instance.compositePropertySearch(propertyMap, minBeds, maxBeds, minBaths, maxBaths, minPrice, maxPrice, location, type);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                cout << "Where is your property located?" << endl;
                cin >> location;
                cout << "How many bedrooms does your property have?" << endl;
                cin >> beds;
                cout << "How many bathrooms does your property have?" << endl;
                cin >> baths;                
                cout << "Is your property: \n1-For rent\n2-For sale" << endl;
                do
                {
                    cin >> saleRent;
                    if (saleRent == 1)
                        type = "rental";
                    else if (saleRent == 2)
                        type = "sale";
                    else
                        cout << "Invalid choice, please try again!";
                } while (saleRent == 1 || saleRent == 2);
                cout << "Now, please provide a brief description of your property!" << endl;
                cin >> description;
                cout << "How much would you like to list your property for?" << endl;
                cin >> price;
                propertyMap[idCounter] = Property(idCounter, beds, baths, type, description,currentLoggedIn->username, location, price);
//                 properties.insert(price, & propertyMap[idCounter]);
                 
                break;
            default:
                cout << "Invalid choice, please try again!";
                    break;
                }
            } while (userSelection == 1 || userSelection == 2 || userSelection == 3 || userSelection == 4);
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
    } while (currentLoggedIn!=NULL);
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
    string name;
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
    cout << "Now please enter your name: " << endl;
    cin >> name;
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
    attempt.registerUser(username, email, password, phoneNumber, name);
}