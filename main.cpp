#include <iostream>
#include <Windows.h>

#include "contact.h"
#include "directory.h"
using namespace std;

int main()
{
	int selection;
	string name;
	directory phonebook; // Create an object of class directory as a linked list.
	phonebook.loadContacts("Contacts.csv");
	while (1) // Infinite loop on menu.
	{
		cout << "Welcome to PhoneBook." << endl;
		cout << "\t\t\t\tMENU \n\n";
		cout << "\t\t1. Add Contacts\n\t\t2. List\n\t\t3. Update Contacts\n\t\t4. Search Contacts\n\t\t5. Delete Contact\n\t\t6. Exit\n";
		cin >> selection; // Menu selection.
		cin.ignore();
		switch (selection)
		{
		case 1: // For adding new contact.
			phonebook.addContact();
			break;
		case 2: // For listing all contacts.
			phonebook.list();
			break;
		case 3: // Update details of an existing contact.
			cout << "Enter contact you want to update: ";
			getline(cin, name);
			phonebook.updateContact(name);
			break;
		case 4: // Search contact by name.
			cout << "Enter contact you want to search: ";
			getline(cin, name);
			phonebook.searchContact(name);
			break;
		case 5: // Delete contact by name.
			cout << "Enter contact you want to delete: ";
			getline(cin, name);
			phonebook.deleteContact(name);
			break;
		case 6: // Exit program.
			return 0;
		default:
			cout << "Please enter a valid option." << endl;
			Sleep(1000);
			break;
		}
		system("CLS"); // Clear screen.
	}
	return 0;
}
