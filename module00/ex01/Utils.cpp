#include "Utils.hpp"

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
