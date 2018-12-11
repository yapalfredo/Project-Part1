#pragma once
/* Assignment 1 - 2.) unix command help program

Write a program that will provide help with basic unix commands. The
program should contain a loop that asks the user to input a unix
command or enter quit to stop the program. Your program should
recognize at least 6 of the basic unix commands  we discussed in
class on Week 1 (e.g., ls, pwd, etc.). Your program should print out
the brief description of the command the user entered.  If the user
enters a command that your program does not recognize, then print a
message to that effect.

*/

#ifndef UNIX_COMMAND 
#define UNIX_COMMAND
	#include <iostream>
	#include <string>
	
	using namespace std;

	class UnixCommands
	{
	private:
		char choice;
	public:
		UnixCommands(){}
		~UnixCommands(){}
		void HMW2Choice();
		void loadScreen();
		void unixCommands(string);
	};
#endif