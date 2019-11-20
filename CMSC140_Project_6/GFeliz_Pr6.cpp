/*
* Class: CMSC140 CRN 20780
* Instructor: Madvhi Shah
* Project4
* Description: Write a program that asks the user for a file name.
The program should read the contents of the file in to an array and
then display the lowest number, the highest number, the total and
average of the numbers in the array.
* Due Date: 11/29/17
* I pledge that I have completed the programming assignment independently.
I have not copied the code from a student or any source.
I have not given my code to any student.
* Gabriel I Feliz
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

// Function prototypes
void readNum(ifstream &, int[], const int);
int lowNum(int numArray[], const int SIZE);
int hiNum(int numArray[], const int SIZE);
int sumNum(int numArray[], const int SIZE);
double avgNum(int numArray[], const int SIZE);

// Main function
int main()
{	
	/* Declare ifstream object for file, string literal for file name,
	and the array. Also, declare the size, and initiialize to 12 because
	12 numbers will be stored in the array*/
	string fileName;
	ifstream numbersFile;
	const int SIZE = 12;
	int numArray[SIZE];

	// Prompt and get file name
	cout << "Please enter the name of the file to read numbers for Number Analysis program:" << endl;
	cin >> fileName;

	/* The file will open and the  if the user enters "numbers.txt"
	Otherwise, the program will display an error message, and it will exit.	*/
	if (fileName == "numbers.txt")
	{
		numbersFile.open(fileName);
		readNum(numbersFile, numArray, SIZE);

		cout << " The highest number is " << hiNum(numArray, SIZE) << endl;
		cout << " The lowest number is " << lowNum(numArray, SIZE) << endl;
		cout << " The sum of numbers is " << sumNum(numArray, SIZE) << endl;
		cout << " The average of the numbers is "
			<< fixed << setprecision(2) << avgNum(numArray, SIZE) << endl;
	}
	else
	{
		cout << "Error opening the file." << endl;
	}

	numbersFile.close();

	system("pause");
	return 0;
}
// Read data from the file and store them into the array
void readNum(ifstream &numbersFile, int numArray[], const int SIZE)
{
	/*The for loops allows the program to start storing the first number 
	in the file into the first element of the array, the second number to
	the second element, and so on. It stops when the 12th number is stored 
	into the 12th element. */
	for (int count = 0; count < SIZE; count++)
	{
		numbersFile >> numArray[count];
	}
}

// Find lowest number
/* Arguments accepted are array and array size.
Both arguments are integers and derived from main function*/
int lowNum(int numArray[], const int SIZE)
{
	/*Declare int variable for lowest number and initialize it
	to the first element of the array*/
	int lowNumber = numArray[0];

	/*The for loops allows the program to start analyzing if the first element
	in the array is the lowest number. If not, it analyzes the next elements.
	When the lowest number is found, it is assigned to the int variable lowNumber. */
	for (int count = 0; count < SIZE; count++)
	{
		if (numArray[count] < lowNumber)
		{
			lowNumber = numArray[count];
		}
	}
	// The lowest number is returned to the lowNum function
	return lowNumber;
}

// Find highest number
/* Arguments accepted are array and array size.
Both arguments are integers and derived from main function*/
int hiNum(int numArray[], const int SIZE)
{
	/*Declare int variable for highest number and initialize it
	to the first element of the array*/
	int hiNumber = numArray[0];

	/*The for loops allows the program to start analyzing if the first element
	in the array is the highest number. If not, it analyzes the next elements.
	When the highest number is found, it is assigned to the int variable hiNumber. */
	for (int count = 0; count < SIZE; count++)
	{
		if (numArray[count] > hiNumber)
		{
			hiNumber = numArray[count];
		}
	}
	// The highest number is returned to the hiNum function
	return hiNumber;
}

// Find total of numbers
/* Arguments accepted are array and array size.
Both arguments are integers and derived from main function*/
int sumNum(int numArray[], const int SIZE)
{	
	// Declare and initialize int variable to 0
	int sumNumber = 0; 

	// Running total
	/*The for loops allows the program to accumulate each number stored in
	the 12 elements of the array into the int variable sumNumber */
	for (int count = 0; count < SIZE; count++)
	{
		sumNumber += numArray[count];
	}

	// The sum of the numbers is returned to the totalNum function
	return sumNumber;
}

// Find average of numbers
/* Arguments accepted are array and array size.
Both arguments are integers and derived from main function*/
double avgNum(int numArray[], const int SIZE)
{
	/* static_cast is used to convert the int variable stored in the totalNum
	function to a double variable */
	/* This is needed because at least one of the variables has to be double in a
	mathematical operation for a C++ program to display a double result*/
	double avgNumber = static_cast<double>(sumNum(numArray, SIZE)) / SIZE;
	// The average of the numbers is returned to the avgNum function
	return avgNumber;
}