#include "directory.h"
using namespace std;


void directory::addContact() // Function to add a node in linked list.
{
	// Make a new node.
	tempContact = new contact;

	// Ask user for contact details.
	cout << "Enter phone number: ";
	getline(cin, tempContact->phoneNumber);
	cout << "Enter first name: ";
	getline(cin, tempContact->firstName);
	cout << "Enter last name: ";
	getline(cin, tempContact->lastName);
	cout << "Enter contact father's name: ";
	getline(cin, tempContact->fatherName);
	cout << "Enter contact email address: ";
	getline(cin, tempContact->email);
	cout << "Enter contact address: ";
	getline(cin, tempContact->address);
	cout << "Enter contact relation: ";
	getline(cin, tempContact->relation);
	cout << "Enter contact gender: ";
	getline(cin, tempContact->gender);

	// Find full name by concatinating first and last name.
	tempContact->fullName = tempContact->firstName + " " + tempContact->lastName;

	if (baseContact == NULL) // For first entry.
	{
		baseContact = tempContact; // Assign the new node as a first/root node.
	}
	else // For other than first entry.
	{
		currentContact = baseContact;
		while (1) // Loop through linked list and add the new contact at the end of list.
		{
			if (currentContact->next == NULL)
			{
				currentContact->next = tempContact;
				break;
			}
			currentContact = currentContact->next;
		}
	}
	saveContacts("Contacts.csv"); // Save new contacts.
	//Successful message.
	cout << "\nContact \"" << tempContact->fullName << "\" Added successfully" << endl;
	system("pause");
}

void directory::searchContact(string searchName) // To search the linked list by name.
{
	int contactFound = 0; // Flag variable to check if contact is found or not.
	currentContact = baseContact;
	while (currentContact != NULL) // Loop through linked list to find the matching name.
	{
		// Match the search name with first name, last name or full name.
		if (currentContact->firstName == searchName || currentContact->lastName == searchName || currentContact->fullName == searchName) // Print the details of contact if contact is found.
		{
			contactFound = 1;
			cout << "Contact found!\n\n";
			cout << "First Name: " << currentContact->firstName << endl;
			cout << "Last Name: " << currentContact->lastName << endl;
			cout << "Phone Number: " << currentContact->phoneNumber << endl;
			cout << "Email: " << currentContact->email << endl;
			cout << "Address: " << currentContact->address << endl;
			cout << "Relation: " << currentContact->relation << endl;
			cout << "Gender: " << currentContact->gender << endl;
		}
		currentContact = currentContact->next;
	}
	//Error message when no matching contact is found.
	if (contactFound == 0)
		cout << "No contact found." << endl;
	system("pause");
}

void directory::list() // Function to display all the contacts as a list.
{
	currentContact = baseContact;
	cout << "\t\tNAME \t\t\tPhone Number\t\t\t\tEmail\t\t\tAddress \n\n";
	while (currentContact != NULL) // Loop through linked list to print all contacts.
	{
		cout << setw(25) << currentContact->fullName << "\t\t";
		cout << setw(15) << currentContact->phoneNumber;
		cout << setw(30) << currentContact->email;
		cout << setw(60) << currentContact->address << endl;

		currentContact = currentContact->next;
	}
	system("pause");
}

void directory::updateContact(string updateName) // Function to change details of a contact.
{
	int contactFound = 0; // Flag variable to check if contact is found or not.
	currentContact = baseContact;
	while (currentContact != NULL) // Loop through linked list to find the contact.
	{
		if (currentContact->firstName == updateName) // When contact is found.
		{
			contactFound = 1;
			cout << "Contact found" << endl;
			cout << "Name: " << currentContact->firstName << " " << currentContact->lastName << endl;
			cout << "Phone Number: " << currentContact->phoneNumber << endl;

			cout << "Select details need to be changed.\n";
			cout << "1. First Name\n2. Last Name\n3. Phone\n4. Email\n5. Address\n6. Relation\n7. Gender" << endl;
			int selection;
			cin >> selection;

			switch (selection) // Change details according to selected option.
			{
			case 1:
				cout << "Enter new first name: ";
				cin >> currentContact->firstName;
				break;
			case 2:
				cout << "Enter new last name: ";
				cin >> currentContact->lastName;
				break;
			case 3:
				cout << "Enter new phone number: ";
				cin >> currentContact->phoneNumber;
				break;
			case 4:
				cout << "Enter new email address: ";
				cin >> currentContact->email;
				break;
			case 5:
				cout << "Enter new address: ";
				cin >> currentContact->address;
				break;
			case 6:
				cout << "Enter new relation: ";
				cin >> currentContact->relation;
				break;
			case 7:
				cout << "Enter new gender: ";
				cin >> currentContact->gender;
				break;

			default:
				cout << "Enter a valid option.";
				break;
			}
		}
		currentContact = currentContact->next;
	}
	saveContacts("Contacts.csv"); // Update saved contacts.

	//Successful message when contact is updated.
	if (contactFound == 1)
		cout << "Contact updated successfully." << endl;
	else
		cout << "No contact with such name found." << endl;
	system("pause");
}



void directory::deleteContact(string deleteName)
{
	int contactFound = 0; // Flag variable to check if contact is found or not.
	string deleted; // Full name of deleted contact.
	if (baseContact != NULL)  // Check if there is no contact in the list.
	{
		if (baseContact->firstName == deleteName) // When the contact to be deleted is the root of linked list.
		{
			deleted = baseContact->firstName + " " + baseContact->lastName;
			contactFound = 1;
			tempContact = baseContact;
			baseContact = tempContact->next; // Make the contact after root contact as new root contact.
			delete tempContact; // Delete old base contact.
		}
		else // When contact to be deleted is other than root.
		{
			currentContact = baseContact;
			while (1) // Loop through linked list until contact is found.
			{
				if (currentContact->next == NULL) // Break the loop when pointer is at last node of linked list.
					break;
				if (currentContact->next->firstName == deleteName)
				{
					contactFound = 1;
					tempContact = currentContact->next;
					deleted = tempContact->firstName + " " + tempContact->lastName;
					currentContact->next = tempContact->next;
					delete tempContact;
					break;
				}
				currentContact = currentContact->next;
			}

		}

	}
	saveContacts("Contacts.csv"); // Update saved contacts.

	// Successful message if contact is found.
	if (contactFound == 0)
		cout << "No contact found with such name." << endl;
	else if (contactFound == 1)
		cout << "Contact \"" << deleted << "\" deleted succesfully." << endl;

	system("pause");
}


void directory::loadContacts(string fileName)
{
	ifstream file;
	file.open(fileName);
	while (file)
	{
		tempContact = new contact; // Make a new node.

		getline(file, tempContact->firstName, ',');
		getline(file, tempContact->lastName, ',');
		getline(file, tempContact->phoneNumber, ',');
		getline(file, tempContact->email, ',');
		getline(file, tempContact->address, ',');
		getline(file, tempContact->relation, ',');
		getline(file, tempContact->gender, '\n');
		// Find full name by concatinating first and last name.
		tempContact->fullName = tempContact->firstName + " " + tempContact->lastName;

		if (baseContact == NULL)
		{
			baseContact = tempContact;
		}
		else if (tempContact->firstName == "") // Fix a bug where program would load an empty line into contacts.
		{
			break;
		}
		else
		{
			currentContact = baseContact;
			currentContact->next = tempContact;
			currentContact = currentContact->next;
		}

	}
	//Successful message.
	cout << "Contacts loaded successfully" << endl;

}
void directory::saveContacts(string fileName) // Function to save contacts in a .csv file
{
	ofstream file;
	file.open(fileName, ofstream::trunc); // Open file in overwrite mode.
	currentContact = baseContact;
	while (currentContact != NULL) // Loop through linked list until the end of list.
	{
		// Write the contact details in a .csv file.
		file << currentContact->firstName << ",";
		file << currentContact->lastName << ",";
		file << currentContact->phoneNumber << ",";
		file << currentContact->email << ",";
		file << currentContact->address << ",";
		file << currentContact->relation << ",";
		file << currentContact->gender << "\n";

		currentContact = currentContact->next;
	}
}