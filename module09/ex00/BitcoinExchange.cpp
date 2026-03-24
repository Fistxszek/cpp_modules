#include "BitcoinExchange.hpp"
#include <iostream>
#include <iterator>
#include <ostream>

BitcoinExchange::BitcoinExchange(void)
{

}

BitcoinExchange::BitcoinExchange(std::string csv, std::string input)
{
	this->ParseDB(csv, O_CSV);
	std::cout << std::endl;
	this->ParseDB(input, O_INPUT);
	std::cout << std::endl;

	std::map<t_date, float>::iterator it;

//	for (it = _inputDB.begin(); it != _inputDB.end(); ++it)
//	{
//		float val = this->GetBtValueByDate(it->first);
//		std::cout << val * it->second << std::endl;
//	}
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

void BitcoinExchange::ParseDB(std::string file, int parseType)
{
	bool firstLine = true;
	std::ifstream dbFile;
	dbFile.open(file.c_str());

	std::string separateChar = parseType == O_CSV ? "," : "|";
	std::string line;
	while (std::getline(dbFile, line))
	{
		if (firstLine)
		{
			firstLine = false;
			continue;
		}

		t_date dateTest;
		std::string dateTxt; 

		int start = 0;
		int end = -1;
		bool badInput = false;

		for (int i = 0; i < 3; ++i)
		{
			start = end + 1;
			end = i != 2 ? line.find("-", start) : line.find(separateChar, start);
			if (end == -1)
			{
				std::cerr << "Error: Bad input!" << std::endl;
				badInput = true;
				continue;
			}
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
		
		if (badInput)
		{
			badInput = false;
			continue ;
		}
		start = end + 1;
		end = line.length();
		std::string left_l = line.substr(start, end - start);
		float value = std::atof(left_l.c_str());

		if (parseType == O_CSV)
			_csvDB.insert(std::pair<t_date, float>(dateTest, value));
		else if (parseType == O_INPUT)
		{
			if (dateTest < 0 || value < 0)
			{
				std::cerr << "Error: not a positive number!" << std::endl;
				continue;
			}
			else if (!dateTest.IsDateValid())
			{
				std::cerr << "Error: invalid date!" << std::endl;
				continue;
			}

			float val = this->GetBtValueByDate(dateTest);
			std::cout << dateTest.year << "-" << dateTest.month << "-" << dateTest.day << " => " << value << " = " << value * val << std::endl;
		}
	}
}

float BitcoinExchange::GetBtValueByDate(BitcoinExchange::t_date date)
{
	t_date closestDate = _csvDB.begin()->first;
	std::map<t_date, float>::iterator it = _csvDB.end();

	for (--it; it != _csvDB.begin(); --it)
	{
		t_date itDate = it->first;
		
		if (itDate > date)
			continue;
		else if (itDate == date)
			return this->_csvDB.at(date);
		else if (itDate < date)
		{
			if (itDate > closestDate)
				closestDate = itDate;
		}
	}
	return this->_csvDB.at(closestDate);
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

bool BitcoinExchange::s_date::operator>(const s_date& other) const
{
	if (year != other.year)
		return year > other.year;
	if (month != other.month)
		return month > other.month;
	return day > other.day;
}

bool BitcoinExchange::s_date::operator==(const s_date& other) const
{
	if (year == other.year && month == other.month && day == other.day)
		return true;
	return false;
}

bool BitcoinExchange::s_date::operator<(const float other) const
{
	if (year != other)
		return year < other;
	if (month != other)
		return month < other;
	return day < other;
}

bool BitcoinExchange::s_date::IsDateValid(void)
{
	bool isLeap = false;
	if (year % 400 == 0)
		isLeap = true;
	else if (year % 100 == 0)
		isLeap = false;
	else if (year % 4 == 0)
		isLeap = true;

	if (month < 1 || month > 12 || day < 1 || day > 31)
		return false;

	if (month == 2)
	{
		if (isLeap && day > 29)
			return false;
		if (!isLeap && day > 28)
			return false;
	}
	else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;
	return true;
}
