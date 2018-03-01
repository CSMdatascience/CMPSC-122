/*
Author:		Cole Meyers - csm5532
Class:		CMPSC 122
Project:	1
File:		proj1.cpp
Purpose(s):	review C++ basics
				create a guessing game
					use a binary search algorithm for automated play
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	const int C = 100;				//C will be the max range of the random number generated
	
	int ans, guess;					//ans will be the answer, guess will be the guess

	srand(unsigned(time(NULL)));	//seeds random number generator with the time
	
	char choice;					//user's choice to the following game mode selection

	cout << "Would you like to (p)lay or watch the (c)omputer play?\n";
	cin >> choice;					//user enters game mode selectoin
	choice = tolower(choice);		//forces user input character to lower case to simplify following conditional statement

	do {
		while (choice != 'p' && choice != 'c')	//validate game mode selection
		{
			cout << "Invalid entry. Please enter 'p' to play or 'c' to watch the computer play.\n";
			cin >> choice;
			choice = tolower(choice);
		}

		if (choice == 'p')					//enter user-play mode
		{
			ans = (rand() % C + 1);			//generates random number x between 1 - 100
			cout << "Enter your guess between 1 and 100.\n";			

			do {
				cin >> guess;			//user makes a guess

				if (guess == ans)
					cout << "Congrats, you guessed the correct number, " << ans << ".\n";
				else if (guess < ans)
					cout << "Sorry, your guess is too low, try again.\n";
				else
					cout << "Sorry, your guess is too high, try again.\n";
			} while (guess != ans);
		}

		else if (choice == 'c')				//enter computer-play mode
		{
			ans = (rand() % C + 1);			//generates random ans between 1 - 100

			int low = 1;
			int high = C;
			guess = 50;						//must initialize guess to use in conditional... not elegant but it works

			do {
				guess = low + (high - low) / 2;		//computer makes a guess, based on binary search parameters in the following loop
				cout << "The computer's guess is " << guess << ".\n";

				if (guess == ans)					//binary search algorithm
					cout << "Congrats, you guessed the correct number, " << ans << ".\n";
				else if (guess < ans)
				{
					cout << "Sorry, your guess is too low, try again.\n";
					low = guess + 1;
				}
				else 
				{
					cout << "Sorry, your guess is too high, try again.\n";
					high = guess - 1;
				}
			} while (guess != ans);
		}

		cout << "Would you like to (p)lay or watch the (c)omputer play or (q)uit?\n";	//gives user option to play again, or quit this time
		cin >> choice;
		choice = tolower(choice);
	} while (choice != 'q');
	
	return 0;
}

/* Sample execution:

Would you like to (p)lay or watch the (c)omputer play?
A
Invalid entry. Please enter 'p' to play or 'c' to watch the computer play.
d
Invalid entry. Please enter 'p' to play or 'c' to watch the computer play.
P
Enter your guess between 1 and 100.
50
Sorry, your guess is too high, try again.
25
Sorry, your guess is too low, try again.
33
Sorry, your guess is too high, try again.
29
Sorry, your guess is too high, try again.
27
Sorry, your guess is too low, try again.
28
Congrats, you guessed the correct number, 28.
Would you like to (p)lay or watch the (c)omputer play or (q)uit?
c
The computer's guess is 50.
Sorry, your guess is too low, try again.
The computer's guess is 75.
Sorry, your guess is too high, try again.
The computer's guess is 62.
Sorry, your guess is too low, try again.
The computer's guess is 68.
Sorry, your guess is too low, try again.
The computer's guess is 71.
Sorry, your guess is too low, try again.
The computer's guess is 73.
Congrats, you guessed the correct number, 73.
Would you like to (p)lay or watch the (c)omputer play or (q)uit?
Q
Press any key to continue . . .
*/