#pragma once

#include <iostream>
#include <cstdlib>
#include <map>
#include <fstream>
#include <utility>


class BitcoinExchange
{
	public:
		typedef struct s_date
		{
			int year;
			int month;
			int day;

			bool operator<(const s_date& other) const;
		} t_date;

		BitcoinExchange(void);
		BitcoinExchange(std::string csv, std::string input);
		BitcoinExchange(BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		//void ParseDB(std::string file, std::map<t_date, float> &db);
		void ParseDB(std::string file, std::map<t_date, float> &db, std::string &seperateChar);
		float GetBtValueByDate(t_date date);
		std::map<t_date, float> const &GetCsvDB(void);	
		std::map<t_date, float> const &GetInputDB(void);	
	private:
		std::map<t_date, float> _csvDB;
		std::map<t_date, float> _inputDB;
};
