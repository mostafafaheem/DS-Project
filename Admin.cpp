#include "admin.h"

void Admin::deleteProperty(int id) {
	if (currentLoggedIn == NULL || !currentLoggedIn->isAdmin) return;
	propertyMap.erase(id);
}


void Admin::editProperty(int id) {
    auto it = propertyMap.find(id);
    if (it != propertyMap.end()) {
        Property& prop = it->second;
        char choice;
        do {
            cout << "Editing Property #" << prop.id << endl;
            cout << "1. Edit Number of Bedrooms (" << prop.beds << ")" << endl;
            cout << "2. Edit Number of Bathrooms (" << prop.baths << ")" << endl;
            cout << "3. Edit Type (" << prop.type << ")" << endl;
            cout << "4. Edit Description (" << prop.description << ")" << endl;
            cout << "5. Edit Listed By (" << prop.listedBy << ")" << endl;
            cout << "6. Edit Location (" << prop.location << ")" << endl;
            cout << "7. Edit Price (" << prop.price << ")" << endl;
            cout << "8. Edit Approval Status (" << (prop.approved ? "Approved" : "Not Approved") << ")" << endl;
            cout << "9. Edit Highlighted Status (" << (prop.highlighted ? "Highlighted" : "Not Highlighted") << ")" << endl;
            cout << "0. Finish Editing" << endl;
            cout << "Choose an attribute to edit (0-9): ";
            cin >> choice;

            switch (choice) {
            case '1':
                cout << "Enter new number of bedrooms: ";
                cin >> prop.beds;
                break;
            case '2':
                cout << "Enter new number of bathrooms: ";
                cin >> prop.baths;
                break;
            case '3':
                cout << "Enter new type (e.g., sale, rental): ";
                cin >> prop.type;
                break;
            case '4':
                cout << "Enter new description: ";
                cin.ignore(); // Ignore leftover newline character
                getline(cin, prop.description);
                break;
            case '5':
                cout << "Enter new listed by: ";
                cin >> prop.listedBy;
                break;
            case '6':
                cout << "Enter new location: ";
                cin >> prop.location;
                break;
            case '7':
                cout << "Enter new price: ";
                cin >> prop.price;
                break;
            case '8':
                cout << "Enter approval status (1 for approved, 0 for not approved): ";
                cin >> prop.approved;
                if (prop.approved) {
                    cout << "Enter the admin username who approved this property: ";
                    cin >> prop.approvedBy;
                }
                else {
                    prop.approvedBy = "";
                }
                break;
            case '9':
                cout << "Enter highlighted status (1 for highlighted, 0 for not highlighted): ";
                cin >> prop.highlighted;
                break;
            case '0':
                cout << "Finished editing property #" << prop.id << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
            }
        } while (choice != '0');
    }
    else {
        cout << "Property with ID #" << id << " not found." << endl;
    }
}



void Admin::approveProperty(int id) {
	propertyMap[id].approved = true;
	propertyMap[id].approvedBy = currentLoggedIn->username;
	approvalQueue.pop();
}


void Admin::highlightProperty(int id) {
	propertyMap.at(id).highlighted = true;
}
//add functionality to remove highlights, include user prompts