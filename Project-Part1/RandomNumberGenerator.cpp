#include "RandomNumberGenerator.h"

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