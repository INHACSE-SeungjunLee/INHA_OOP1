#include <iostream> 
#include <cstdlib>
using namespace std;

unsigned int makeA(unsigned int level);
int makeS(unsigned int level);
unsigned int makeM(unsigned int level);
unsigned int makeD(unsigned int level);

int main()
{
	int level, seed;
	char arithmetic;
	cout << "Enter a seed of random numbers: ";
	cin >> seed;
	srand(seed);
	cout << "Select arithmetic (A, S, M, D) and level (1, 2, 3): ";
	cin >> arithmetic >> level;

	switch (arithmetic)
	{
	case 'A':
		makeA(level);
		break;
	case 'S':
		makeS(level);
		break;
	case 'M':
		makeM(level);
		break;
	case 'D':
		makeD(level);
		break;
	}

}

unsigned int makeA(unsigned int l)
{
	int num1{ 0 }, num2{ 0 }, answer{ 0 };
	while (answer != -1)
	{
		switch (l)
		{
		case 1:
			num1 = rand() % 9 + 1;
			num2 = rand() % 9 + 1;
			break;
		case 2:
			num1 = rand() % 90 + 10;
			num2 = rand() % 90 + 10;
			break;
		case 3:
			num1 = rand() % 900 + 100;
			num2 = rand() % 900 + 100;
			break;
		}
		cout << num1 << " + " << num2 << " = ? (-1 to quit) ";
		cin >> answer;
		if (answer == -1)
		{
			cout << "Bye.";
		}
		else if (num1 + num2 == answer)
		{
			cout << "Correct!" << endl;
		}
		else if (num1 + num2 != answer)
		{
			while (num1 + num2 != answer)
			{
				cout << "Wrong answer. Try again.\n";
				cout << "? ";
				cin >> answer;
			}
			cout << "Correct!\n";
		}

	}
	return 0;
}


int makeS(unsigned int l)
{
	int num1{ 0 }, num2{ 0 }, answer{ 0 };
	while (answer != -1)
	{
		switch (l)
		{
		case 1:
			num1 = rand() % 10 + 1;
			num2 = rand() % 10 + 1;
			break;
		case 2:
			num1 = rand() % 90 + 10;
			num2 = rand() % 90 + 10;
			break;
		case 3:
			num1 = rand() % 900 + 100;
			num2 = rand() % 900 + 100;
			break;
		}
		cout << num1 << " - " << num2 << " = ? (-1 to quit) ";
		cin >> answer;
		if (answer == -1)
		{
			cout << "Bye.";
		}
		else if (num1 - num2 == answer)
		{
			cout << "Correct!\n";
		}
		else if (num1 - num2 != answer)
		{
			while (num1 - num2 != answer)
			{
				cout << "Wrong answer. Try again.\n";
				cout << "? ";
				cin >> answer;
			}
			cout << "Correct!\n";
		}

	}
	return 0;
}

unsigned int makeM(unsigned int l)
{
	int num1{ 0 }, num2{ 0 }, answer{ 0 };
	while (answer != -1)
	{
		switch (l)
		{
		case 1:
			num1 = rand() % 10 + 1;
			num2 = rand() % 10 + 1;
			break;
		case 2:
			num1 = rand() % 90 + 10;
			num2 = rand() % 90 + 10;
			break;
		case 3:
			num1 = rand() % 900 + 100;
			num2 = rand() % 900 + 100;
			break;
		}
		cout << num1 << " * " << num2 << " = ? (-1 to quit) ";
		cin >> answer;
		if (answer == -1)
		{
			cout << "Bye.";
		}
		else if (num1 * num2 == answer)
		{
			cout << "Correct!\n";
		}
		else if (num1 * num2 != answer)
		{
			while (num1 * num2 != answer)
			{
				cout << "Wrong answer. Try again.\n";
				cout << "? ";
				cin >> answer;
			}
			cout << "Correct!\n";
		}

	}
	return 0;
}

unsigned int makeD(unsigned int l)
{
	int num1{ 0 }, num2{ 0 }, answer{ 0 };
	while (answer != -1)
	{
		switch (l)
		{
		case 1:
			num1 = rand() % 10 + 1;
			num2 = rand() % 10 + 1;
			break;
		case 2:
			num1 = rand() % 90 + 10;
			num2 = rand() % 90 + 10;
			break;
		case 3:
			num1 = rand() % 900 + 100;
			num2 = rand() % 900 + 100;
			break;
		}
		cout << num1 << " / " << num2 << " = ? (-1 to quit) ";
		cin >> answer;
		if (answer == -1)
		{
			cout << "Bye.";
		}
		else if (num1 / num2 == answer)
		{
			cout << "Correct!\n";
		}
		else if (num1 / num2 != answer)
		{
			while (num1 / num2 != answer)
			{
				cout << "Wrong answer. Try again.\n";
				cout << "? ";
				cin >> answer;
			}
			cout << "Correct!\n";
		}

	}
	return 0;
}
