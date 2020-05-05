#pragma once
#include <iostream>
#include <string>

using namespace std;

class contact // Class contact containing variables for contact details. This will act as a node.
{
private:
	string phoneNumber; // Contact phone number.
	string firstName, lastName, fullName, fatherName; // Contact name.
	string address, email; // Contact e-mail address and physical address.
	string gender, relation; // Gender and relation.
	contact* next = NULL; // Address to next node in linked list.

public:

	friend class directory; // Declare the linked list class as a friend.
};


