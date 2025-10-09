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
		void complain( std::string level );
};
