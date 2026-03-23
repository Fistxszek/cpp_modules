#include "BitcoinExchange.hpp"
#include <iostream>
#include <iterator>
#include <ostream>

BitcoinExchange::BitcoinExchange(void)
{

}

BitcoinExchange::BitcoinExchange(std::string csv, std::string input)
{
	std::string csvSeparator = ",";
	std::string inputSeparator = "|";
	this->ParseDB(csv, this->_csvDB, csvSeparator);
	std::cout << std::endl;
	this->ParseDB(input, this->_inputDB, inputSeparator);
	std::cout << std::endl;

	for (std::map<t_date, float>::iterator it = _inputDB.begin(); it != _inputDB.end(); ++it)
	{
		float val = this->GetBtValueByDate(it->first);
		std::cout << val * it->second << std::endl;
	}
}

BitcoinExchange::BitcoinExchange(BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &other)
{
	if (this == &other)
		return *this;
	this->_csvDB = other._csvDB;
	this->_inputDB = other._inputDB;
	return *this;
}

void BitcoinExchange::ParseDB(std::string file, std::map<t_date, float> &db, std::string &seperateChar)
{
	std::ifstream dbFile;
	dbFile.open(file.c_str());

	std::string line;
	(void)db;
	while (std::getline(dbFile, line))
	{
		t_date dateTest;
		std::string dateTxt; 

		int start = 0;
		int end = -1;

		for (int i = 0; i < 3; ++i)
		{
			start = end + 1;
			end = i != 2 ? line.find("-", start) : line.find(seperateChar, start);
			dateTxt = line.substr(start, end - start);
			switch (i)
			{
				case 0:
					dateTest.year = std::atoi(dateTxt.c_str());
					break;
				case 1:
					dateTest.month = std::atoi(dateTxt.c_str());
					break;
				case 2:
					dateTest.day = std::atoi(dateTxt.c_str());
					break;
			}
		}
		
		start = end + 1;
		end = line.length();
		float value = std::atof(line.substr(start, end - start).c_str());

		db.insert(std::pair<t_date, float>(dateTest, value));
		std::cout << dateTest.day << ", ";
		std::cout << dateTest.month << ", ";
		std::cout << dateTest.year << seperateChar;
		std::cout << value << "\n";
	}
}

float BitcoinExchange::GetBtValueByDate(BitcoinExchange::t_date date)
{
	float test = 0;
	try
	{
		test = this->_csvDB.at(date);
	}
	catch (...){}

	return test;
}

std::map<BitcoinExchange::t_date, float> const &BitcoinExchange::GetCsvDB(void)
{
	return this->_csvDB;
}

std::map<BitcoinExchange::t_date, float> const &BitcoinExchange::GetInputDB(void)
{
	return this->_inputDB;
}

bool BitcoinExchange::s_date::operator<(const s_date& other) const
{
	if (year != other.year)
		return year < other.year;
	if (month != other.month)
		return month < other.month;
	return day < other.day;
}
