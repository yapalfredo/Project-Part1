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