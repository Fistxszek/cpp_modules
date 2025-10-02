#include <cstdlib>
#include <exception>
#include <string>
#include <sstream>
#include <cctype>
#include <iostream>

#define MAX_CONTACTS 8

enum	DataTypes
{
		Command,
		FirstName,
		LastName,
		Nickname,
		Number,
		Secret
};

class Contact
{
	public:
		void	clearContact();
		std::string FirstName;
		std::string LastName;
		std::string Nickname;
		std::string	Number;
		std::string Secret;
};

class PhoneBook
{
	public:
		Contact Contacts[MAX_CONTACTS];
		int		takenCount;
		int		currCount;
};

class	ExitException : public std::exception {};

bool	readLine(DataTypes type, PhoneBook &phoneBook);

int	stringToInt(const std::string &str)
{
	std::stringstream ss(str);
	int	result;
	ss >> result;

	if (ss.fail())
	{
		return (-1);
	}
	return result;
}

///void	Contact::clearContact(Contact &contact)
void	Contact::clearContact()
{
	if (!FirstName.empty())
		FirstName.clear();
	if (!LastName.empty())
		LastName.clear();
	if (!Nickname.empty())
		Nickname.clear();
	if (!Number.empty())
		Number.clear();
	if (!Secret.empty())
		Secret.clear();
}

void	search_behaviour(std::string text, bool isLast)
{
	int	chars_left = 10;

	chars_left -= text.length();
	if (chars_left < 0)
	{
		text.resize(9);
		text += '.';
		chars_left = 0;
	}
	std::string spaces(chars_left, ' ');
	if (isLast)
		std::cout << spaces << text; 
	else
		std::cout << spaces << text << '|';
}

bool	cmdType(std::string line, PhoneBook &phoneBook)
{
	if (line == "Add")
	{
		phoneBook.currCount = phoneBook.takenCount % MAX_CONTACTS;

		for (int i = 1; i < 6; i++)	
		{
			if (!readLine(static_cast<DataTypes>(i), phoneBook))
			{
				std::cout << "Empty field is prohibited, contact creation interrupted\n";
				//clearContact(phoneBook.Contacts[phoneBook.currCount]);
				phoneBook.Contacts[phoneBook.currCount].clearContact();
				return false;
			}
		}

		if (phoneBook.takenCount < MAX_CONTACTS)
		{
			phoneBook.takenCount++;
		}

		std::cout << "Succesfully added " << phoneBook.Contacts[phoneBook.currCount].FirstName << " to the contact list!\n";
	}
	else if (line == "Search")
	{
		if (phoneBook.takenCount == 0)
		{
			std::cout << "Contact list is empty, add a new contact using: Add\n";
			return true;
		}
		for (int i = 0; i < phoneBook.takenCount; i++)
		{
			Contact contact = phoneBook.Contacts[i];
			std::cout << "         " << i << "|";
			search_behaviour(contact.FirstName, false);
			search_behaviour(contact.LastName, false);
			search_behaviour(contact.Nickname, true);
			std::cout << "\n";
		}
		std::cout << "Enter index of the contact you're looking for\n";
		std::string index;
		if (!std::getline(std::cin, index))
			return false;
		int	indexInt = stringToInt(index.c_str());
		if (indexInt < 0)
		{
			std::cout << "Invalid character...\n";
			return true;
		}
		if (indexInt < phoneBook.takenCount)
		{
			std::cout << "First name : "<< phoneBook.Contacts[indexInt].FirstName << "\n";
			std::cout << "Last name : "<< phoneBook.Contacts[indexInt].LastName << "\n";
			std::cout << "Nickname : "<< phoneBook.Contacts[indexInt].Nickname << "\n";
			std::cout << "Number : "<< phoneBook.Contacts[indexInt].Number << "\n";
			std::cout << "Secret : "<< phoneBook.Contacts[indexInt].Secret << "\n";
		}
		else
			std::cout << "User index out of contact list bounds\n";
	}
	else if (line == "Exit")
		throw ExitException();
		//std::exit(0);
	return true;
}

bool	readLine(DataTypes type, PhoneBook &phoneBook)
{
	std::string line;
	Contact		&contact = phoneBook.Contacts[phoneBook.currCount];

	switch (type)
	{
		case Command:
		std::cout << "Enter a command\n";
			break;
		case FirstName:
		std::cout << "Provide first name\n";
			break;
		case LastName:
		std::cout << "Provide last name\n";
			break;
		case Nickname:
		std::cout << "Provide nickname\n";
			break;
		case Number:
		std::cout << "Provide number\n";
			break;
		case Secret:
		std::cout << "Provide secret\n";
			break;
	}
	if (!std::getline(std::cin, line))
	{
		return false;
	}
	if (line.empty() && type != Command)
	{
		//clearContact(contact);
		contact.clearContact();
		return false;
	}
	switch (type)
	{
		case Command:
			if (!cmdType(line, phoneBook))
				return false;
			break;
		case FirstName:
			contact.FirstName = line;
			break;
		case LastName:
			contact.LastName = line;
			break;
		case Nickname:
			contact.Nickname = line;
			break;
		case Number:
			contact.Number = line;
			break;
		case Secret:
			contact.Secret = line;
			break;
	}
	return true;
}

int main()
{
	std::string line;
	std::string nameLine;
	PhoneBook phoneBook;
	
	phoneBook.takenCount = 0;
	phoneBook.currCount = 0;
	try
	{
		while (true)
			readLine(Command, phoneBook);
	}
	catch (const ExitException&)
	{
		return 0;
	}
	return 0;
}
