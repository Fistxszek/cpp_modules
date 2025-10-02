#include <cstdlib>
#include <exception>
#include <string>
#include <sstream>
#include <cctype>
#include <iostream>
#include <iomanip> 

#define MAX_CONTACTS 8

enum DataTypes
{
    Command,
    FirstName,
    LastName,
    Nickname,
    Number,
    Secret
};

class PhoneBook;
class Contact;

class ExitException : public std::exception {};

bool readLine(DataTypes type, PhoneBook &phoneBook);
int stringToInt(const std::string &str);

class Contact
{
public:
    std::string getFirstName() const { return m_FirstName; }
    void setFirstName(const std::string& val) { m_FirstName = val; }

    std::string getLastName() const { return m_LastName; }
    void setLastName(const std::string& val) { m_LastName = val; }

    std::string getNickname() const { return m_Nickname; }
    void setNickname(const std::string& val) { m_Nickname = val; }

    std::string getNumber() const { return m_Number; }
    void setNumber(const std::string& val) { m_Number = val; }

    std::string getSecret() const { return m_Secret; }
    void setSecret(const std::string& val) { m_Secret = val; }

    void clearContact()
    {
        m_FirstName.clear();
        m_LastName.clear();
        m_Nickname.clear();
        m_Number.clear();
        m_Secret.clear();
    }

private:
    std::string m_FirstName;
    std::string m_LastName;
    std::string m_Nickname;
    std::string m_Number;
    std::string m_Secret;
};

class PhoneBook
{
public:
    Contact Contacts[MAX_CONTACTS];
    int takenCount;
    int currCount;

    PhoneBook() : takenCount(0), currCount(0) {}

    bool addContact()
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

    bool searchContacts()
    {
        if (takenCount == 0)
        {
            std::cout << "Contact list is empty, add a new contact using: Add\n";
            return true;
        }
        
        std::cout << " ___________________________________________\n";
        std::cout << "|     Index|First Name| Last Name|  Nickname|\n";
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

private:
    void format_text(const std::string& text, bool isLast) const
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

    bool getContactDetails()
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
};

int stringToInt(const std::string &str)
{
    std::stringstream ss(str);
    int result;
    ss >> result;

    if (ss.fail())
    {
        return (-1);
    }
    return result;
}

std::string toUpper(std::string str)
{
    std::string::iterator it;
    for (it = str.begin(); it != str.end(); ++it)
    {
        *it = (char)std::toupper(*it); 
    }
    return str;
}

bool readLine(DataTypes type, PhoneBook &phoneBook)
{
    std::string line;
    Contact& contact = phoneBook.Contacts[phoneBook.currCount];

    switch (type)
    {
        case Command:   std::cout << "Enter a command (Add, Search, Exit)\n"; break;
        case FirstName: std::cout << "Provide first name\n"; break;
        case LastName:  std::cout << "Provide last name\n"; break;
        case Nickname:  std::cout << "Provide nickname\n"; break;
        case Number:    std::cout << "Provide number\n"; break;
        case Secret:    std::cout << "Provide secret\n"; break;
    }
    if (!std::getline(std::cin, line))
        return false;
    if (line.empty() && type != Command)
    {
        contact.clearContact();
        return false;
    }
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
        case FirstName: contact.setFirstName(line); break;
        case LastName:  contact.setLastName(line); break;
        case Nickname:  contact.setNickname(line); break;
        case Number:    contact.setNumber(line); break;
        case Secret:    contact.setSecret(line); break;
    }
    return true;
}

int main()
{
    PhoneBook phoneBook; 
    
    try
    {
        while (true)
        {
            readLine(Command, phoneBook);
        }
    }
    catch (const ExitException&)
    {
        std::cout << "Exiting phone book application.\n";
        return 0;
    }
    return 0; 
}
