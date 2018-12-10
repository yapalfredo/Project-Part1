#include "RandomNumberGenerator.h"
#include "UnixCommands.h"
#include "MyStats.h"

char choice;

void menuFunction();

int main()
{

	menuFunction();
	system("pause");
	return 0;

}

void menuFunction()
{


	try
	{
		do
		{
			RandomNumberGenerator hm1;
			UnixCommands hm2;
			MyStats hm3;

			cout << "BMCC CSC FALL 2018 HOMEWORK MENU" << endl << endl;

			cout << "Press: " << endl;
			cout << "		1 - Random Number Generator " << endl;
			cout << "		2 - Unix Commands" << endl;
			cout << "		3 - My Stats" << endl;
			cout << "		4 - Exit" << endl;
			cin >> choice;
			
				switch (choice)
				{
				case '1':
					//call Homework 1
					hm1.HMW1Choice();
					break;
				case '2':
					//call Homework 2
					hm2.HMW2Choice();
					break;
				case '3':
					hm3.HMW3Choice();
					//call Homework 3
					break;
				case '4':
					exit;
					break;
				default:
					cout << endl << "P L E A S E   E N T E R   O N L Y   B E T W E E N   1 - 4 " << endl << endl;
					menuFunction();
					break;
				}
				hm1.~RandomNumberGenerator();
				hm2.~UnixCommands();
				hm3.~MyStats();
		} while (choice != '4');
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}

}