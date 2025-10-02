#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : takenCount(0), currCount(0) {}

bool PhoneBook::addContact()
{
    currCount = takenCount % MAX_CONTACTS;

    for (int i = 1; i <= Secret; i++) 
    {
        if (!readLine(static_cast<DataTypes>(i), *this))
        {
            std::cout << "Empty field is prohibited, contact creation interrupted\n";
            Contacts[currCount].clearContact();
            return false;
        }
    }

    if (takenCount < MAX_CONTACTS)
    {
        takenCount++;
    }

    std::cout << "Succesfully added " << Contacts[currCount].getFirstName() << " to the contact list!\n";
    return true;
}

bool PhoneBook::searchContacts()
{
    if (takenCount == 0)
    {
        std::cout << "Contact list is empty, add a new contact using: Add\n";
        return true;
    }
    
    // Print header
    std::cout << " ___________________________________________\n";
    std::cout << "|   Index  |First Name| Last Name|  Nickname|\n";
    std::cout << "|----------|----------|----------|----------|\n";

    std::cout << std::right; 

    for (int i = 0; i < takenCount; i++)
    {
        const Contact& contact = Contacts[i];
        std::cout << "|";
        std::cout << std::setw(10) << i << "|"; 
        format_text(contact.getFirstName(), false);
        format_text(contact.getLastName(), false);
        format_text(contact.getNickname(), true);
        std::cout << "|";
        std::cout << "\n";
        std::cout << "|----------|----------|----------|----------|\n";
    }
    std::cout << "|__________|__________|__________|__________|\n";

    return getContactDetails();
}

void PhoneBook::format_text(const std::string& text, bool isLast) const
{
    std::string display_text = text;
    const int COL_WIDTH = 10;
    
    if (display_text.length() > COL_WIDTH)
    {
        display_text.resize(COL_WIDTH - 1);
        display_text += '.';
    }

    std::cout << std::setw(COL_WIDTH) << display_text; 
    
    if (!isLast)
        std::cout << "|";
}

bool PhoneBook::getContactDetails()
{
    std::cout << "Enter index of the contact you're looking for\n";
    std::string index;
    if (!std::getline(std::cin, index))
        return false;
    
    int indexInt = stringToInt(index);
    
    if (indexInt == -1) 
    {
        std::cout << "Invalid character...\n";
        return true;
    }

    if (indexInt >= 0 && indexInt < takenCount)
    {
        const Contact& contact = Contacts[indexInt];
        std::cout << "\n";
        std::cout << " ___________________________________________\n";
        std::cout << "|First name : " << contact.getFirstName() << "\n";
        std::cout << "|___________________________________________\n";
        std::cout << "|Last name : " << contact.getLastName() << "\n";
        std::cout << "|___________________________________________\n";
        std::cout << "|Nickname : " << contact.getNickname() << "\n";
        std::cout << "|___________________________________________\n";
        std::cout << "|Number : " << contact.getNumber() << "\n";
        std::cout << "|___________________________________________\n";
        std::cout << "|Secret : " << contact.getSecret() << "\n";
        std::cout << "|___________________________________________\n";
    }
    else
        std::cout << "User index out of contact list bounds\n";
        
    return true;
}

// --- GLOBAL readLine IMPLEMENTATION ---

bool readLine(DataTypes type, PhoneBook &phoneBook)
{
    std::string line;
    Contact& contact = phoneBook.Contacts[phoneBook.currCount];

    // 1. Output the prompt
    switch (type)
    {
        case Command:   std::cout << "Enter a command (Add, Search, Exit)\n"; break;
        case FirstName: std::cout << "Provide first name\n"; break;
        case LastName:  std::cout << "Provide last name\n"; break;
        case Nickname:  std::cout << "Provide nickname\n"; break;
        case Number:    std::cout << "Provide number\n"; break;
        case Secret:    std::cout << "Provide secret\n"; break;
    }

    // 2. Read the line
    if (!std::getline(std::cin, line))
    {
        return false;
    }

    // 3. Handle empty line constraint
    if (line.empty() && type != Command)
    {
        contact.clearContact();
        return false;
    }

    // 4. Process the line
    switch (type)
    {
        case Command:
        {
            std::string upperLine = toUpper(line);
            
            if (upperLine == "ADD")
                return phoneBook.addContact();
            else if (upperLine == "SEARCH")
                return phoneBook.searchContacts();
            else if (upperLine == "EXIT")
                throw ExitException();
            else
                std::cout << "Unknown command. Use Add, Search, or Exit.\n";
            break;
        }
        // Use setters to modify private data
        case FirstName: contact.setFirstName(line); break;
        case LastName:  contact.setLastName(line); break;
        case Nickname:  contact.setNickname(line); break;
        case Number:    contact.setNumber(line); break;
        case Secret:    contact.setSecret(line); break;
    }
    return true;
}
