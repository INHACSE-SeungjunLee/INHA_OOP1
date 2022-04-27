#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int type, quantity;
	int quantity1{ 0 }, quantity2{ 0 }, quantity3{ 0 }, quantity4{ 0 }, quantity5{ 0 };

	do {
		cout << "Enter kit number [1, 5] or -1 to quit: ";
		cin >> type;
		switch (type)
		{
		case 1:
			cout << "Enter quantity: ";
			cin >> quantity;
			quantity1 += quantity;
			break;
		case 2:
			cout << "Enter quantity: ";
			cin >> quantity;
			quantity2 += quantity;
			break;
		case 3:
			cout << "Enter quantity: ";
			cin >> quantity;
			quantity3 += quantity;
			break;
		case 4:
			cout << "Enter quantity: ";
			cin >> quantity;
			quantity4 += quantity;
			break;
		case 5:
			cout << "Enter quantity: ";
			cin >> quantity;
			quantity5 += quantity;
			break;
		case -1:
			break;
		default:
			cout << "Kit number must be between 1 and 5." << endl;
			break;
		}
	} while (type != -1);
	cout << endl;
	cout << fixed << setprecision(3);
	cout << "kit 1: " << quantity1 * 3.0 << " Kwon" << endl;
	cout << "kit 2: " << quantity2 * 4.5 << " Kwon" << endl;
	cout << "kit 3: " << quantity3 * 5.0 << " Kwon" << endl;
	cout << "kit 4: " << quantity4 * 5.5 << " Kwon" << endl;
	cout << "kit 5: " << quantity5 * 6.0 << " Kwon" << endl;
	cout << "total: " << quantity1 * 3.0 + quantity2 * 4.5 + quantity3 * 5.0 + quantity4 * 5.5 + quantity5 * 6.0 << " Kwon";
}