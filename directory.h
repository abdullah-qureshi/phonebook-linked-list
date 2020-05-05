#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "contact.h"

class directory // Class directory as a linked list of contact objects.
{
private:
	// The first node in linked list.
	contact* baseContact = NULL;
	// Temporary addresses to hold nodes for insertion/deleting.
	contact* currentContact = NULL;
	contact* tempContact = NULL;


public:

	void addContact(); // To add contacts in directory.
	void searchContact(string); // To search contacts by name
	void list(); // List all contacts as a table.
	void updateContact(string); // Modify an existing contact.
	void deleteContact(string); // Delete an existing contact.
	void loadContacts(string); // Load contacts from a .csv file
	void saveContacts(string); // Save contacts in a .csv file

};


