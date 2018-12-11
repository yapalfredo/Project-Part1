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