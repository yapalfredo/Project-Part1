#pragma once

//HOMEWORK 1
/* Assignment 1 - 1.) “rand”  test program

Write a program that tests the validity of the rand() function.
Generate 10,000 random numbers. For each random number, determine if
it is even (divisible by 2) or odd, counting the total number of
even and odd numbers. Compute the ratio of even to odd numbers. Print
to the screen the number of even numbers generated, the number of
odd numbers generated and the ratio of even to odd numbers.

*/

#ifndef RANDOM_NUMBER_GENERATOR   
#define RANDOM_NUMBER_GENERATOR
	#include <iostream>
	#include <time.h>
	#include <fstream>	
	#include <string>
	using namespace std;
	

	class RandomNumberGenerator
	{
	private:
		char choice;
	public:
		RandomNumberGenerator() {}
		~RandomNumberGenerator(){}
		void HMW1Choice();
		void generateRandomNumber();
	};

#endif

	void RandomNumberGenerator::HMW1Choice()
	{
		try
		{
			do
			{
				cout << "	RANDOM NUMBER GENERATOR" << endl << endl;
				cout << "	Press" << endl;
				cout << "			1 - to run homework" << endl;
				cout << "			2 - to go back" << endl;
				cin >> choice;

				switch (choice)
				{
				case '1':
					generateRandomNumber();
					break;
				case '2':
					return;
					break;
				default:
					cout << endl << "P L E A S E   E N T E R   O N L Y   B E T W E E N   1 - 2 " << endl << endl;
					HMW1Choice();
					break;
				}
			} while (choice != '2');
		}
		catch (exception& e)
		{
			cout << e.what() << endl;
		}
	}


	void RandomNumberGenerator::generateRandomNumber()
	{
		try
		{
			//do
			//{

			//declared ofstream object to out to a text file
			ofstream outFile("random.txt");
			//initialized two int variables 'odd', 'even' to 0
			int odd = 0, even = 0;
			//maps the random generator to time
			srand(time(NULL));

			for (int i = 0; i < 10000; i++)
			{
				//Generates random number between 1 to 100
				if ((rand() % (1 + 100)) % 2 == 0)
				{
					even++; //increments even variable if generated number is even
				}
				else {
					odd++;  //increments odd otherwise
				}
			}
			//----------------------- OUTPUT FILE -----------------------------------------
			//----- Output these lines to the txt file 'random.txt'
			outFile << "The number of random even numbers generated is: " << even << "\n";
			outFile << "The number of random odd numbers generated is: " << odd << "\n";
			outFile << "The ratio of random numbers generated of even to odd is: " << static_cast<double>(even) / odd;
			outFile.close();
			//------------------------ OUTPUT FILE ----------------------------------------

			//-------------------------INPUT FILE-----------------------------------------
			ifstream inFile("random.txt");     //declare an ifstream object to read
												//the random.txt
			if (!inFile) throw string("Error opening file ");
			else
			{
				string input;              //declare a string input variable to store lines in text
				while (!inFile.eof())       //goes through each line in the file
				{
					getline(inFile, input, '\n'); //get each line from the file and store to input
													//variable
					cout << input << endl;        // cout the input string to the screen
				}

				inFile.close();             //close inFile object when done
			}
			//-------------------------INPUT FILE-----------------------------------------

			cout << endl << "Do you want to try again ? y/n" << endl;
			cin >> choice;
			if (tolower(choice) == 'y')
			{
			generateRandomNumber();
			}
			else if (isdigit(choice) || tolower(choice)!='n' )
			{
				cout << "P L E A S E   E N T E R   O N L Y   B E T W E E N   'y'  or  'n' " << endl;
			}
			

			//} while (isdigit(choice) || tolower(choice) != 'n');
		}
		catch (const string str)
		{
			cout << str << endl;
			exit(1);
		}
		catch (const exception& e)
		{
			cout << e.what() << endl;
		}

	}