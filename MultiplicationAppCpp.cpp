// This project is created by Sihab Uddin and Omar Khan

#include <iostream>  //Header file. For cin and cout statements.
#include <ctime>     //Header file. For using ctime.
#include <cstdlib>   //Header file. For rand()
#include <math.h>    //Header file. For functions like pow(x,y), abs and other math functions
using namespace std;
/*All the elements of the standard C++ library are declared
within what is called a namespace. The namespace with the name std */
int a, b; // Global variables for two random numbers.
double p; // Global variable for the percentage.
char choice; // For choice to continue- Yes or No.
void Intro(); // Function prototype for the introduction.
int gen_numbers(double x);// Function prototype to generate random numbers.
int ask_question(double x);
//Funtion prototype that ask the questions and increment NumRight and NumWrong answers as needed
int main()
//Above line corresponds to the beginning of the definition of the main function.
{
	Intro();// Function Calling.
	double x;// Variable for the level of difficulty.
	cin >> x;
	cout << "---------------------------------------------------" << endl;
	cout << "Difficulty Level = " << x << endl;
	ask_question(x);// Function Calling.
	cout << "\n \n \n Do you want to quit(Y/N)";
	cin >> choice;
	int k = x;// initialized 

	while (choice != 89 && choice != 121)// ASCII values for "Y" and "y" (Sentinel Values).
	{
		if (p >= 80.0) // Level increments if the user scores more than 80%
		{
			++k;
			cout << "---------------------------------------------------" << endl;
			cout << "Difficulty Level = " << k << endl;
			ask_question(k); // Function Calling.
			cout << "\n \n \n Do you want to quit(Y/N)";
			cin >> choice;

		}

		else // Level remains the same for score less than 80%
		{
			cout << "---------------------------------------------------" << endl;
			cout << "Difficulty Level = " << k << endl;
			ask_question(k); // Function Calling.
			cout << "\n \n \n Do you want to quit(Y/N)";
			cin >> choice;

		}

	}
	system("pause");
	/*To keep the screen on the monitor after execution, without it the screen disappears after execution*/
	return 0;//The return statement causes the main function to finish.
}
void Intro() // Program Description. Function Definition.
{
	cout << "Welcome to Multiplication Practice Software." << endl << endl;
	cout << "This program will help you practice multiplication by" << endl;
	cout << "presenting you with randomly generated practice" << endl;
	cout << "problems at different level of difficulty." << endl;
	cout << "The difficulty is determined by the number of digits in" << endl;
	cout << "the multiplication. You can specify the initial" << endl;
	cout << "number of digits. The program will also keep track" << endl;
	cout << "of your progress. At the end of each session, you" << endl;
	cout << "may choose to continue or not." << endl << endl << endl;
	cout << "\nPlease enter the level of difficulty (1 and up):";

}
int gen_numbers(double x)// Function definition to generate random numbers
{
	srand(time(NULL));// Randomize number with respect to time.
	double lvl = x - 1.00;
	int m = 9 * pow(10.0, lvl);//Max value of the level.
	int n = pow(10.0, lvl);  //Min value of the level.
	if (lvl == 0)
		/* Any number raised to zero is 1. This block is made because we want to include 0 for 1-digit numbers.*/
	{
		a = rand() % 10;
		b = rand() % 10;
	}
	else
		//This block is made for 2 digits or more digit numbers
	{
		a = n + rand() % m;
		b = n + rand() % m;
	}
	cout << "\n " << a << "*" << b << "=";//Outputs the random numbers as a equation on screen.
	return 0;
}
int ask_question(double x)// Function definition to ask questions.
{
	int numWrong = 0;// Calculates wrong answers.
	int numRight = 0;// Calculates correct answers.
	for (int i = 1; i <= 5; i++)// Maximum number of questions is 5.
	{
		gen_numbers(x);//Function Calling.
		int n;         // n is the answer of the user.
		cin >> n;
		if (a * b != n)
		{
			for (int j = 0; j <= 1; j++)
			{
				++numWrong;//counts the increment of wrong answers
				cout << "Incorrect answer. Try again." << endl << endl;
				cout << "\n " << a << "*" << b << "=";
				cin >> n;
				if (j == 1 && a * b != n)
				{
					++numWrong;//counts the increment of wrong answers
					cout << "Incorrect answer. The answer is:" << a * b << " Lets move on." << endl << endl;
				}
				if (a * b == n)
				{
					cout << "Correct!" << endl << endl;
					++numRight; //counts the increment of correct answers
					break;  //Used to break the loop
				}
			}
		}
		else
		{
			cout << "Correct!" << endl << endl;
			++numRight; // increments correct answers.
		}
	}
	p = 100 * (double(numRight) / double(numRight + numWrong)); // calculates the total percentage.
	cout << "\n End of one session. " << p << "% correct." << endl << endl;
	if (p >= 80.0 && p <= 100.0)// Output when user scores 80%+.
		cout << "Excellent! You are ready for the next level of difficulty." << endl;
	if (p >= 60.0 && p < 80.0)//Output when user scores between 60%-80%.
		cout << "Good job, continue with more practice." << endl;
	if (p < 60)//Output when user scores less than 60%.
		cout << "You need to practice more. Please seek help from the instructor." << endl;
	return p;// returns the percentage.
}
