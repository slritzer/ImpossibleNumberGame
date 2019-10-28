/*
Impossible Guess a Number
Written by Stephanie Ritzer
This program gives users three chances to guess a number but will not allow the user to win.
*/
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;


/*
Input - minimum number & max number in the range.
selectRandom function adds max number and minimum number then divides by two.
Output - program's selected random number.
*/
int selectRandom(int min, int max)
{

	int range = (max + min) / 2;
	return range;

}

int main()
{
	int guess;										//user input for guess
	int upperEnd;									//possible solutions between guess and maximum number
	int lowerEnd;									//possible solutions between guess and minimum number
	int minNumber = 1;
	int maxNumber = 10;
	int attempts = 3;								//attempts remaining

	srand((unsigned)time(NULL));

	while (attempts > 0)
	{
		cout << "Guess a number between " << minNumber << " and " << maxNumber << endl;
		cout << attempts << " remaining attempts.\n";
		cout << "________________________________________\n";
		cin >> guess;								//console input for user's guess
		cout << "________________________________________\n\n";

		//if-else if statement limits user input within range
		if (guess > maxNumber)
		{
			cout << "You should know " << guess << " is too high. Guess a number less than or equal to " << maxNumber << endl << endl;
			continue;
		}

		else if (guess < minNumber)
		{
			cout << "You should know " << guess << " is too low. Guess a number greater than or equal to " << minNumber << endl << endl << endl;
			continue;
		}

		//calculates lower and upper end
		lowerEnd = guess - minNumber;
		upperEnd = maxNumber - guess;

		/*
		if-else statement tells user if guess is too high or low.
		maxNumber changes to user's guess minus one, if guess is too high.
		minNumber changes to user's guess, plus one, if guess is too low.
		*/
		if (upperEnd < lowerEnd)
		{
			cout << guess << " is too high.\n\n";
			maxNumber = guess - 1;
		}

		else
		{
			cout << guess << " is too low.\n\n";
			minNumber = guess + 1;
		}

		attempts--;									//each iteration decrements user attempts by 1
	}

	/*
	notify user the game is over and displays correct answer
	calls selectRandom function
	current minNumber, minus one, is sent to function
	current maxNumber, plus one, is sent to function
	*/
	cout << "Sorry, but you're out of guesses. GAME OVER. The correct number is: " << selectRandom(minNumber - 1, maxNumber + 1) << ".\n";

}