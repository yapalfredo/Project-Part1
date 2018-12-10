#pragma once
/*
For this assignment, you will write a program that generates an array of integers and calculates statistics on the data (i.e., the integers) in the array. 
You need to write separate functions to do each step

Design your class called : MyStats.h, MyStats.cpp and TestMyStats.cpp and submit ONLY these three files in google Drive.
• Define an integer 10x10 2D (Two dimensional) array to store 100 values. (0.5 point)
 • Initialize values in the array to random numbers between -128 and 127. (1 point)
 • Display on the screen the values stored in the array. (0.5 point)
• Calculate the average of the values stored in the array and display it. (1 point)
• Find the largest value stored in the array and display it. (0.5 point)
 • Find the smallest value stored in the array and display it. (0.5 point)

Compile, build and run your program to make sure it works as you expect it to.

*/

#ifndef MY_STATS 
#define MY_STATS
	#include <cstdlib>
	#include <iostream>
	#include <ctime>
	#include <iomanip>
	using namespace std;

	// GLOBAL VARIABLES
	const int rowSize = 10;
	const int colSize = 10;

	class MyStats
	{
	private:
		int arrStat[rowSize][colSize];
		int temp;
		char choice;
	public:
		//CONSTRUCTOR
		MyStats() { init();  }

		//DESTRUCTOR
		~MyStats() {}

		// MUTATORS
		void setArrStat(int, int, int);
		void setTemp(int);

		// ACCESSORS
		int getArrStat(int, int);
		int getTemp();

		// WILL INITIALIZE THE VALUES OF THE ELEMENTS IN THE ARRAY
		void init();

		// WILL PRINT THE INDIVIDUAL ELEMENTS IN THE ARRAY
		void print();

		// WILL CALCULATE FOR THE AVERAGE VALUE OF ALL ELEMENTS IN THE ARRAY
		double average();

		// WILL LOOK FOR THE LARGEST VALUE IN THE ARRAY
		int findLargest();

		// WILL LOOK FOR THE SMALLEST VALUE IN THE ARRAY
		int findSmallest();

		void HMW3Choice();
		void loadScreen();
	};
#endif

	void MyStats::HMW3Choice()
	{
		try
		{
			do
			{
				cout << "	MY STATS" << endl << endl;
				cout << "	Press" << endl;
				cout << "			1 - to run homework" << endl;
				cout << "			2 - to go back" << endl;
				cin >> choice;

				switch (choice)
				{
				case '1':
					init();
					loadScreen();
					break;
				case '2':
					return;
					break;
				default:
					cout << endl << "P L E A S E   E N T E R   O N L Y   B E T W E E N   1 - 2 " << endl << endl;
					HMW3Choice();
					break;
				}
			} while (choice != '2');
		}
		catch (exception& e)
		{
			cout << e.what() << endl;
		}
	}
	

	void MyStats::loadScreen()
	{
		try
		{
			cout << "-------------------------------------------------------------------------" << endl;
			cout << "The initialized values of elements in the array are: " << endl << endl;
			print();

			cout << endl;
			cout << "The average of the values stored in the array is: " << average() << endl;

			cout << endl;
			cout << "The largest value stored in the array is: " << findLargest() << endl;

			cout << endl;
			cout << "The smallest value stored in the array is: " << findSmallest() << endl << endl;
			cout << "-------------------------------------------------------------------------" << endl;

		}
		catch (exception& e)
		{
			cout << e.what() << endl;
		}

	}

	void MyStats::setArrStat(int row, int col, int val)
	{
		//modifies the value orders in the array
		arrStat[row][col] = val;
	}

	int MyStats::getArrStat(int row, int col)
	{
		//returns an array value
		int result;

		result = arrStat[row][col];

		return result;
	}

	void MyStats::setTemp(int temp)
	{
		//to be used for the temporary variable
		//this class modifies the temp value
		this->temp = temp;
	}

	int MyStats::getTemp()
	{
		//to be used for the temporary variable
		//this class returns the temp value
		return temp;
	}

	void MyStats::init()
	{
		//This class initializes all the values in the array ranging from -128 to 127
		srand(time(NULL));

		for (int row = 0; row < rowSize; row++)
		{
			for (int col = 0; col < colSize; col++)
			{
				setArrStat(row, col, (rand() % (0 + 256)) - 128);
			}
		}
	}

	void MyStats::print()
	{
		//Prints the values in the array
		for (int row = 0; row < rowSize; row++)
		{
			for (int col = 0; col < colSize; col++)
			{
				cout << setw(5) << getArrStat(row, col) << " ";
			}
			cout << endl;
		}
	}

	double MyStats::average()
	{
		//This class gets the average for all the values in the array
		double result = 0;

		for (int row = 0; row < rowSize; row++)
		{
			for (int col = 0; col < colSize; col++)
			{
				result += getArrStat(row, col);
			}
		}

		return (result / static_cast<double>(rowSize*colSize));
	}

	int MyStats::findLargest()
	{
		//this class will look for the largest value in the array
		for (int y = 0; y < rowSize; y++)
		{
			for (int x = 0; x < colSize; x++)
			{
				if (x < colSize - 1)
				{
					if (getArrStat(y, x) > getArrStat(y, x + 1))
					{
						setTemp(getArrStat(y, x + 1));
						setArrStat(y, x + 1, getArrStat(y, x));
						setArrStat(y, x, getTemp());
					}
				}
				else if (x == colSize - 1)
				{
					if (y < rowSize - 1)
					{
						if (getArrStat(y, x) > getArrStat(y + 1, 0))
						{
							setTemp(getArrStat(y + 1, 0));
							setArrStat(y + 1, 0, getArrStat(y, x));
							setArrStat(y, x, getTemp());
						}
					}
				}
			}
		}
		return getArrStat(rowSize - 1, colSize - 1);
	}

	int MyStats::findSmallest()
	{
		//this class will look for the smallest value in the array
		for (int y = rowSize - 1; y >= 0; y--)
		{
			for (int x = colSize - 1; x >= 0; x--)
			{
				if (x > 0)
				{
					if (getArrStat(y, x) < getArrStat(y, x - 1))
					{
						setTemp(getArrStat(y, x - 1));
						setArrStat(y, x - 1, getArrStat(y, x));
						setArrStat(y, x, getTemp());
					}
				}
				else if (x == 0)
				{
					if (y > 0)
					{
						if (getArrStat(y, x) < getArrStat(y - 1, colSize - 1))
						{
							setTemp(getArrStat(y - 1, colSize - 1));
							setArrStat(y - 1, colSize - 1, getArrStat(y, x));
							setArrStat(y, x, getTemp());
						}
					}
				}
			}
		}
		return getArrStat(0, 0);
	}