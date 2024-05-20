#include "display.h"
#include <algorithm> 

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


void Display::mainWindow() {
    std::cout  << "Are you an existing user? (select 1), or would you like to create an account? (select 2): ";
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
            std::cout << "Incorrect input, please try again: ";
            break;
        }
        Admin session;
        if (currentLoggedIn != NULL && currentLoggedIn->isAdmin)
        {
            std::cout << "Welcome back Mr. " << currentLoggedIn->name << "! choose which action you want to perform:";
            int adminSelection;
            char adminChoice;
            int id;
            std::cout << "1. Delete Property" << endl << "2. Edit Property" << endl << "3.Approve Property" << endl << "4. Highlight Property" << endl;
            do
            {
                cin >> adminSelection;
                switch (adminSelection)
                {
                case 1:
                {
                    do
                    {
                        std::cout << "Search for property you would like to delete: " << endl;
                        std::cout << "What is the location of the property/properties? Type \"anywhere\" if you do not have any specific preference: " << endl;
                        cin >> location;
                        std::cout << "What is the least number of bedrooms in the property/properties? " << endl;
                        cin >> minBeds;
                        std::cout << "and the most? " << endl;
                        cin >> maxBeds;
                        std::cout << "What is the least number of bathrooms in the property/ies? " << endl;
                        cin >> minBaths;
                        std::cout << "and the most? " << endl;
                        cin >> maxBaths;
                        std::cout << "Would you like seeing properties for rent (type\"rental\"), sale (type\"sale\"), or both (type\"both\")?" << endl;
                        cin >> type;
                        std::cout << "What is the minimum price point you are searching for? " << endl;
                        cin >> minPrice;
                        std::cout << "and the maximum? " << endl;
                        cin >> maxPrice;
                        for (const auto& pair : propertyMap) {
                            const Property& prop = pair.second;
                            if (prop.beds >= minBeds && prop.beds <= maxBeds &&
                                prop.baths >= minBaths && prop.baths <= maxBaths &&
                                prop.price >= minPrice && prop.price <= maxPrice &&
                                prop.location == location && prop.type == type) {
                                std::cout << "Property #" << prop.id << endl <<
                                    "For" << prop.type << endl <<
                                    "Located in " << prop.location <<
                                    "Bedrooms: " << prop.beds << endl <<
                                    "Bathrooms: " << prop.baths << endl <<
                                    "Description: " << prop.description << endl <<
                                    "Price: " << prop.price << endl <<
                                    "------------------------------------------------------------" << endl;
                            }
                        }
                        std::cout << "Type the id of the property you would like to delete: " << endl;
                        cin >> id;
                        session.deleteProperty(id);
                        std::cout << "Would you like to delete another property? (y/n)" << endl;
                        cin >> adminChoice;
                    } while (adminChoice == 'y' || adminChoice == 'Y');
                    break;
                }
                case 2:
                {
                    do
                    {
                        std::cout << "Search for property you would like to edit: " << endl;
                        std::cout << "What is the location of the property/properties? Type \"anywhere\" if you do not have any specific preference: " << endl;
                        cin >> location;
                        std::cout << "What is the least number of bedrooms in the property/properties? " << endl;
                        cin >> minBeds;
                        std::cout << "and the most? " << endl;
                        cin >> maxBeds;
                        std::cout << "What is the least number of bathrooms in the property/ies? " << endl;
                        cin >> minBaths;
                        std::cout << "and the most? " << endl;
                        cin >> maxBaths;
                        std::cout << "Would you like seeing properties for rent (type\"rental\"), sale (type\"sale\"), or both (type\"both\")?" << endl;
                        cin >> type;
                        std::cout << "What is the minimum price point you are searching for? " << endl;
                        cin >> minPrice;
                        std::cout << "and the maximum? " << endl;
                        cin >> maxPrice;
                        for (const auto& pair : propertyMap) {
                            const Property& prop = pair.second;
                            if (prop.beds >= minBeds && prop.beds <= maxBeds &&
                                prop.baths >= minBaths && prop.baths <= maxBaths &&
                                prop.price >= minPrice && prop.price <= maxPrice &&
                                prop.location == location && prop.type == type) {
                                std::cout << "Property #" << prop.id << endl <<
                                    "For" << prop.type << endl <<
                                    "Located in " << prop.location <<
                                    "Bedrooms: " << prop.beds << endl <<
                                    "Bathrooms: " << prop.baths << endl <<
                                    "Description: " << prop.description << endl <<
                                    "Price: " << prop.price << endl <<
                                    "------------------------------------------------------------" << endl;
                            }
                        }
                        std::cout << "Type the id of the property you would like to edit: " << endl;
                        cin >> id;
                        session.editProperty(id);
                        std::cout << "Would you like to edit another property? (y/n)" << endl;
                        cin >> adminChoice;
                    } while (adminChoice == 'y' || adminChoice == 'Y');
                    break;
                }
                case 3:
                {
                    char adminChoice;

                    while (!approvalQueue.empty()) {
                        Property* property = approvalQueue.front();

                        std::cout << "Do you want to approve this property?: (y/n)" << std::endl;
                        std::cout << "Property #" << property->id << "\n"
                            << "For: " << property->type << "\n"
                            << "Located in: " << property->location << "\n"
                            << "Bedrooms: " << property->beds << "\n"
                            << "Bathrooms: " << property->baths << "\n"
                            << "Description: " << property->description << "\n"
                            << "Price: " << property->price << "\n"
                            << "------------------------------------------------------------\n";

                        do {
                            std::cin >> adminChoice;

                            if (adminChoice == 'y' || adminChoice == 'Y') {
                                session.approveProperty(property->id);
                                approvalQueue.pop();
                            }
                            else if (adminChoice == 'n' || adminChoice == 'N') {
                                approvalQueue.pop();
                                propertyMap.erase(property->id);
                            }
                            else {
                                std::cout << "Wrong input, please try again!" << std::endl;
                            }
                        } while (!(adminChoice == 'y' || adminChoice == 'Y' || adminChoice == 'n' || adminChoice == 'N'));
                    }

                        break;
                }
                case 4:
                {
                    do
                    {
                        std::cout << "Search for property you would like to highlight: " << endl;
                        std::cout << "What is the location of the property/properties? Type \"anywhere\" if you do not have any specific preference: " << endl;
                        cin >> location;
                        std::cout << "What is the least number of bedrooms in the property/properties? " << endl;
                        cin >> minBeds;
                        std::cout << "and the most? " << endl;
                        cin >> maxBeds;
                        std::cout << "What is the least number of bathrooms in the property/ies? " << endl;
                        cin >> minBaths;
                        std::cout << "and the most? " << endl;
                        cin >> maxBaths;
                        std::cout << "Would you like seeing properties for rent (type\"rental\"), sale (type\"sale\"), or both (type\"both\")?" << endl;
                        cin >> type;
                        std::cout << "What is the minimum price point you are searching for? " << endl;
                        cin >> minPrice;
                        std::cout << "and the maximum? " << endl;
                        cin >> maxPrice;
                        for (const auto& pair : propertyMap) {
                            const Property& prop = pair.second;
                            if (prop.beds >= minBeds && prop.beds <= maxBeds &&
                                prop.baths >= minBaths && prop.baths <= maxBaths &&
                                prop.price >= minPrice && prop.price <= maxPrice &&
                                prop.location == location && prop.type == type) {
                                std::cout << "Property #" << prop.id << endl <<
                                    "For" << prop.type << endl <<
                                    "Located in " << prop.location <<
                                    "Bedrooms: " << prop.beds << endl <<
                                    "Bathrooms: " << prop.baths << endl <<
                                    "Description: " << prop.description << endl <<
                                    "Price: " << prop.price << endl <<
                                    "------------------------------------------------------------" << endl;
                            }
                        }
                        std::cout << "Type the id of the property you would like to highlight: " << endl;
                        cin >> id;
                        session.highlightProperty(id);
                        std::cout << "Would you like to highlight another property? (y/n)" << endl;
                        cin >> adminChoice;
                    } while (adminChoice == 'y' || adminChoice == 'Y');
                    break;
                }
                default:
                    std::cout << "Incorrect input, please try again: ";
                    break;
                    continue;
                }
                std::cout << "Do you want to peroform any other operation? (y/n)" << endl;
                cin >> adminChoice;
            } while (!(adminSelection == 1) || !(adminSelection == 2) || !(adminSelection == 3) || !(adminSelection == 4) || (adminChoice == 'y') || (adminChoice == 'Y'));
        }
        else if (currentLoggedIn != NULL && !currentLoggedIn->isAdmin)
        {
            std::cout << "Welcome to the Real Estate Portal System! What actions would you like to perform?" << endl;
            std::cout << "1-Search for a property" << endl;
            std::cout << "2-Show random properties you may like" << endl;
            std::cout << "3-Compare properties" << endl;
            std::cout << "4-Post your own property" << endl;
            int saleRent;
            const int colWidth = 20;
            random_device rd;
            mt19937 gen(rd());
            vector<Property> highlightedProperties;
            int* array = new int[4];
            do
            {
                cin >> userSelection;
            switch (userSelection){
            case 1:
            {
                std::cout << "Where are you searching for properties? Type \"anywhere\" if you do not have any specific preference: " << endl;
                cin >> location;
                std::cout << "What is the least number of bedrooms you would like in your property? " << endl;
                cin >> minBeds;
                std::cout << "and the most? " << endl;
                cin >> maxBeds;
                std::cout << "What is the least number of bathrooms you would like in your property? " << endl;
                cin >> minBaths;
                std::cout << "and the most? " << endl;
                cin >> maxBaths;
                std::cout << "Would you like seeing properties for rent (type\"rental\"), sale (type\"sale\"), or both (type\"both\")?" << endl;
                cin >> type;
                std::cout << "What is the minimum price point you are searching for? " << endl;
                cin >> minPrice;
                std::cout << "and the maximum? " << endl;
                cin >> maxPrice;
                for (const auto& pair : propertyMap) {
                    const Property& prop = pair.second;
                    if (prop.beds >= minBeds && prop.beds <= maxBeds &&
                        prop.baths >= minBaths && prop.baths <= maxBaths &&
                        prop.price >= minPrice && prop.price <= maxPrice &&
                        prop.location == location && prop.type == type) {
                        std::cout << "Property #" << prop.id << endl <<
                            "For" << prop.type << endl <<
                            "Located in " << prop.location <<
                            "Bedrooms: " << prop.beds << endl <<
                            "Bathrooms: " << prop.baths << endl <<
                            "Description: " << prop.description << endl <<
                            "Price: " << prop.price << endl <<
                            "------------------------------------------------------------" << endl;
                    }
                }
                break;
            }
            case 2:
            {
                for (const auto& entry : propertyMap) {
                    if (entry.second.highlighted) {
                        highlightedProperties.push_back(entry.second);
                    }
                }
                shuffle(highlightedProperties.begin(), highlightedProperties.end(), gen);
                // Display the first three highlighted properties
                std::cout << "Three Random Highlighted Properties:\n";
                for (int i = 0; i < 3; ++i) {
                    const Property& prop = highlightedProperties[i];
                    std::cout << "Property ID" << prop.id << endl <<
                        "For" << prop.type << endl <<
                        "Located in " << prop.location <<
                        "Bedrooms: " << prop.beds << endl <<
                        "Bathrooms: " << prop.baths << endl <<
                        "Description: " << prop.description << endl <<
                        "Price: " << prop.price << endl <<
                        "------------------------------------------------------------" << endl;
                }
                std::cout << "These are all the properties that correspond to your search, if none are shown, then unfortunately no listings match your criteria \n Please braden your search and try again!";
                break;
            }
            case 3:
            {
                std::cout << "How many properties would you like to compare? (up to 4): ";
                int numProperties;
                cin >> numProperties;
                do
                {
                    if (numProperties < 1 || numProperties > 4) {
                        std::cout << "You can only compare between 1 and 4 properties, please try again!\n";

                    }
                } while (numProperties < 1 || numProperties > 4);
                int* array = new int[numProperties];
                for (size_t i = 0; i < numProperties; i++)
                {
                    std::cout << "Choose property #" << i + 1 << endl;
                    std::cout << "Where are you searching for properties? Type \"anywhere\" if you do not have any specific preference: " << endl;
                    cin >> location;
                    std::cout << "What is the least number of bedrooms you would like in your property? " << endl;
                    cin >> minBeds;
                    std::cout << "and the most? " << endl;
                    cin >> maxBeds;
                    std::cout << "What is the least number of bathrooms you would like in your property? " << endl;
                    cin >> minBaths;
                    std::cout << "and the most? " << endl;
                    cin >> maxBaths;
                    std::cout << "Would you like seeing properties for rent (type\"rental\"), sale (type\"sale\"), or both (type\"both\")?" << endl;
                    cin >> type;
                    std::cout << "What is the minimum price point you are searching for? " << endl;
                    cin >> minPrice;
                    std::cout << "and the maximum? " << endl;
                    cin >> maxPrice;
                    for (const auto& pair : propertyMap) {
                        const Property& prop = pair.second;
                        if (prop.beds >= minBeds && prop.beds <= maxBeds &&
                            prop.baths >= minBaths && prop.baths <= maxBaths &&
                            prop.price >= minPrice && prop.price <= maxPrice &&
                            prop.location == location && prop.type == type) {
                            std::cout << "Property ID: " << prop.id << endl <<
                                "For " << prop.type << endl <<
                                "Located in " << prop.location <<
                                "Bedrooms: " << prop.beds << endl <<
                                "Bathrooms: " << prop.baths << endl <<
                                "Description: " << prop.description << endl <<
                                "Price: " << prop.price << endl <<
                                "------------------------------------------------------------" << endl;
                        }
                    }
                    std::cout << "Choose the ID of the property you would like to compare";
                    do
                    {
                        cin >> array[i];
                        if (array[i] < 0 || array[i] >= idCounter)
                            std::cout << "No property with this id exists, please try again! " << endl;
                    } while (array[i] < 0 || array[i] >= idCounter);
                }
                std::cout << std::setw(colWidth) << "Property ID"
                    << std::setw(colWidth) << "For "
                    << std::setw(colWidth) << "Located in "
                    << std::setw(colWidth) << "Bedrooms"
                    << std::setw(colWidth) << "Bathrooms"
                    << std::setw(colWidth) << "Price"
                    << endl;
                std::cout << std::string(colWidth * 6, '-') << "\n";
                for (size_t i = 0; i < numProperties; i++)
                {
                    std::cout << std::setw(colWidth) << propertyMap[array[i]].id
                        << std::setw(colWidth) << propertyMap[array[i]].type
                        << std::setw(colWidth) << propertyMap[array[i]].location
                        << std::setw(colWidth) << propertyMap[array[i]].beds
                        << std::setw(colWidth) << propertyMap[array[i]].baths
                        << std::setw(colWidth) << propertyMap[array[i]].price
                        << endl;
                }
                break;
            }
            case 4:
            {
                std::cout << "Where is your property located?" << endl;
                cin >> location;
                std::cout << "How many bedrooms does your property have?" << endl;
                cin >> beds;
                std::cout << "How many bathrooms does your property have?" << endl;
                cin >> baths;
                std::cout << "Is your property: \n1-For rent\n2-For sale" << endl;
                do
                {
                    cin >> saleRent;
                    if (saleRent == 1)
                        type = "rental";
                    else if (saleRent == 2)
                        type = "sale";
                    else
                        std::cout << "Invalid choice, please try again!";
                } while (~saleRent == 1 || ~saleRent == 2);
                std::cout << "Now, please provide a brief description of your property!" << endl;
                cin >> description;
                std::cout << "How much would you like to list your property for?" << endl;
                cin >> price;
                propertyMap[idCounter] = Property(idCounter, beds, baths, type, description, currentLoggedIn->username, location, price);
                approvalQueue.push(&propertyMap[idCounter]);

                break;
            }
            default:
                std::cout << "Invalid choice, please try again!";
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
    bool isLoggedIn = true;
    do {
        std::cout << "Please enter your username, email, or phone number to sign in:" << endl;
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
            std::cout << "Invalid input, please try again!" << endl;
            continue;
        }
        std::cout << "Please enter your password:" << endl;
        char c;
        while ((c = _getch()) != 13) { 
            if (c == '\b') { 
                if (!password.empty()) {
                    password.pop_back();
                    std::cout << "\b \b"; 
                }
            }
            else if (isprint(c)) { 
                password += c;
                std::cout << "*"; 
            }
        }
        std::cout << endl;
        if (!regex_match(password, passwordPattern)) {
            std::cout << "Your password should contain at least 8 characters, including at least one uppercase letter, one lowercase letter, one digit, and one special character, please try again:" << endl;
            continue;
        }
        isLoggedIn = attempt.loginUser(loginType, entry, password);
        if (!isLoggedIn) {
            std::cout << "This account does not exist or the credentials are incorrect, please try again!" << endl;
        }
    } while (currentLoggedIn == NULL && !isLoggedIn);
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

    std::cout << "Please enter your email: " << endl;
    do {
        cin >> email;
        if (!regex_match(email, emailPattern)) {
            std::cout << "Incorrect format, please try again:" << endl;
            continue;
        }
        for (User* User : usersList) {
            if (User->email == email) {
                std::cout << "This email is already in use, please try again!" << endl;
                continue;
            }
        }
       } while (!regex_match(email, emailPattern));

    std::cout << "Now, please enter your password: " << endl;
    do {
        char c;
        while ((c = _getch()) != 13) { 
            if (c == '\b') {
                if (!password.empty()) {
                    password.pop_back();
                    std::cout << "\b \b";
                }
            }
            else if (isprint(c)) {
                password += c;
                std::cout << "*"; 
            }
        }
        std::cout << endl; 
        if (!regex_match(password, passwordPattern)) {
            std::cout << "Your password should contain at least 8 characters, including at least one uppercase letter, one lowercase letter, one digit, and one special character, please try again:" << endl;
        }

    } while (!regex_match(password, passwordPattern));

    std::cout << "Now, please enter your phone number: " << endl;
    do {
        cin >> phoneNumber;
        if (!regex_match(phoneNumber, phonePattern)) {
            std::cout << "Incorrect format, please try again:" << endl;
            continue;
        }
        for (User* User : usersList) {
            if (User->phoneNumber == phoneNumber) {
                std::cout << "This phone number is already in use, please try again!" << endl;
                continue;
            }
        }
    } while (!regex_match(phoneNumber, phonePattern));
    std::cout << "Now please enter your name: " << endl;
    cin >> name;
    std::cout << "Finally, please enter your chosen username: " << endl;
    do {
        cin >> username;
        if (!regex_match(username, usernamePattern)) {
            std::cout << "Incorrect format, please try again:" << endl;
            continue;
        }
        for (User* User : usersList) {
            if (User->username == username) {
                std::cout << "This username is already in use, please try again!" << endl;
                continue;
            }
        }
    } while (!regex_match(username, usernamePattern));
    attempt.registerUser(username, email, password, phoneNumber, name);
}