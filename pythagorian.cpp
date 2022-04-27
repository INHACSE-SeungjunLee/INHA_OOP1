#include<iostream>
using namespace std;

int main()
{
	unsigned int side1{1}, side2{1}, side3{1}, max, count{0};
	cout << "The maximum side in [5, 100]: ";
	cin >> max;
	cout << "side1\tside2\tside3\t" << endl;

	while (side1 <= max)
	{
		while (side2 <= max)
		{
			while (side3 <= max)
			{
				if (side1 * side1 + side2 * side2 == side3 * side3)
				{
					cout << side1 << "\t" << side2 << "\t" << side3 << endl;
					count++;
				}
				side3++;
			}
			side2++;
			side3 = side2;
		}
		side1++;
		side2 = side1;
		side3 = side1;
	}

	cout << "A total of " << count << " triples were found.";
}