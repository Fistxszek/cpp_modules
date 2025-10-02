#include "PhoneBook.hpp"

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
