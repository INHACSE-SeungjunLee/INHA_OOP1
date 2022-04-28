
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int seed, count{0};
	char alphabet;
	cout << "Enter seed: ";
	cin >> seed;
	srand(seed);
	for (int i = 0; i < 100; i++)
	{
		int ascii = rand() % 26 + 97;
		alphabet = char(ascii);
		switch (alphabet)
		{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			count++;
			break;
		}
		cout << alphabet << "\n";
	}
	cout << "There are " << count << " vowels.";
}
