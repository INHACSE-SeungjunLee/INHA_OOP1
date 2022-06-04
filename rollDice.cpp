#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

unsigned rollDice();

int main()
{
	enum class Status { Continue, Won, Lost};
	srand(static_cast<unsigned> (time(0)) );
	unsigned myPoint{ 0 };
	Status gameStatus;
	unsigned sumOfDice{ rollDice() };
	switch (sumOfDice)
	{
	case 7:
	case 11:
		gameStatus = Status::Won;
		break;
	case 2:
	case 3:
	case 12:
		gameStatus = Status::Lost;
		break;
	default:
		gameStatus = Status::Continue;
		myPoint = sumOfDice;
		cout << "Point is " << myPoint << endl;
		break;
	}

	while (gameStatus == Status::Continue)
	{
		sumOfDice = rollDice();

		if (sumOfDice == myPoint)
			gameStatus = Status::Won;
		else if (sumOfDice == 7)
			gameStatus == Status::Lost;
	}

	if (gameStatus == Status::Won)
		cout << "You Win!";
	if (gameStatus == Status::Lost)
		cout << "You Lose!";
}

unsigned rollDice()
{
	int die1{ rand() % 6 + 1 };
	int die2{ rand() % 6 + 1 };
	int sum{ die1 + die2 };

	cout << "You got " << die1 << " and " << die2 << "\nThe sum is " << sum << endl;
	return sum;
}
 