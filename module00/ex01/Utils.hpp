#pragma once

#include <string>
#include <exception>
#include <iostream>
#include <sstream>
#include <cctype>

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

class ExitException : public std::exception {};

int stringToInt(const std::string &str);
std::string toUpper(std::string str);
