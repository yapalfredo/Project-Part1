#include "RandomNumberGenerator.h"

//char choice;

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
			cout << "BMCC CSC FALL 2018 HOMEWORK MENU" << endl << endl;

			cout << "Press: " << endl;
			cout << "		1 - Random Number Generator " << endl;
			cout << "		2 - Movie Stats Homework " << endl;
			cout << "		3 - Robot Homework" << endl;
			cout << "		4 - Exit" << endl;
			cin >> choice;
			
				switch (choice)
				{
				case '1':
					//call Homework 1
					HMW1Choice();
					break;
				case '2':
					//call Homework 2
					break;
				case '3':

					//call Homework 3
					break;
				case '4':
					exit;
					break;
				default:
					cout << endl << "Please enter only between 1 - 4 " << endl << endl;
					menuFunction();
					break;
				}
		} while (choice != '4');
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}

}