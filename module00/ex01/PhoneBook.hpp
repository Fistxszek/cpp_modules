#pragma once

#include "Contact.hpp"
#include "Utils.hpp"

class PhoneBook
{
public:
    Contact Contacts[MAX_CONTACTS];
    int takenCount; 
    int currCount;  

    PhoneBook(); 

    bool addContact();
    bool searchContacts();

private:
    void format_text(const std::string& text, bool isLast) const;
    bool getContactDetails();
};

bool readLine(DataTypes type, PhoneBook &phoneBook);
