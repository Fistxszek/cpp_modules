#pragma once

#include <string>
#include <iostream>

class Harl
{
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
		typedef void (Harl::*FuncPtr)();
		FuncPtr Functions[4];
		std::string Levels[4];
	public:
		Harl();
		void complainFiler( std::string level );
};

enum Level { DEBUG, INFO, WARNING, ERROR, UNKNOWN };

void to_upper(std::string &str);
Level getLevel(const std::string& level);
