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
	
	void UnixCommands::HMW2Choice()
	{
		try
		{
			do
			{
				cout << "	UNIX COMMANDS" << endl << endl;
				cout << "	Press" << endl;
				cout << "			1 - to run homework" << endl;
				cout << "			2 - to go back" << endl;
				cin >> choice;

				switch (choice)
				{
				case '1':
					loadScreen();
					break;
				case '2':
					return;
					break;
				default:
					cout << endl << "P L E A S E   E N T E R   O N L Y   B E T W E E N   1 - 2 " << endl << endl;
					HMW2Choice();
					break;
				}
			} while (choice != '2');
		}
		catch (exception& e)
		{
			cout << e.what() << endl;
		}

	}

	void UnixCommands::loadScreen()
	{
		try
		{
			cout << "----------------------------------" << endl;
			cout << "Basic Unix Commands Help Reference" << endl;
			cout << "----------------------------------";
			string input = "";
			while (!(input == "quit")) {
				cout << endl << endl << "Please input a unix command, or type quit to return: "; getline(cin, input);
				unixCommands(input);
			}
		}
		catch (exception& e)
		{
			cout << e.what() << endl;
		}
		
	}

	void UnixCommands::unixCommands(string input)
	{
		int index = 0;
		bool flag = false;
		const int SIZE = 26;
		const string _unixCMD[SIZE] = { "cat", "cp","ls","ls -l", "mv", "rm", "diff","fmt", "grep","head",
			"less", "more", "sort", "tail", "wc", "wc -l", "cd","mkdir","pwd","rm -r","rmdir","ftp",
			"rcp","rcp -r","telnet","ssh" };
		const string _unixCMDDef[SIZE] = { "Concatenate or display files", "copy files", "list file names",
			"list file names, sizes, attributes", "move or rename files" ,"remove files","compare two files",
			"simple line adjuster for mail", "scan a file for a pattern", "display the first ten lines of a file",
			"display file one screen at a time", "display file one screen at a time", "sort/merge utility",
			"display the last ten lines of a file", "count lines, words, characters in a file", "count lines",
			"change to a different directory","make a directory","print the current directory name",
			"remove directory & all files in that directory", "remove empty directory","general file transfer utility",
			"copy files between UNIX systems","copy entire directory tree","connect to a remote system to log in",
			"connect via a secure channel to a remote system to log in" };

		if (input == "quit") {
			return;
		}
		else {
			for (int i = 0; i < SIZE; i++)
			{
				if (input.compare(_unixCMD[i]) == 0) {
					index = i;
					flag = true;
				}
			}

			if (flag)
			{
				cout << "\n	-> " << _unixCMDDef[index];
			}
			else {
				cout << "\n ! Input not recognized !";
			}

		}
	}
