#include <iostream>
#include <iomanip>
using namespace std;

void selectionSort(int A[], const int size, int order);
void swap(int* const p1, int* const p2);

int main()
{
	int n, order;
	int A[10];
	int size{ 10 };

	cout << "Enter 10 integers in [-99, 99] to sort: ";
	for (int i{ 0 }; i < 10; i++)
	{
		cin >> n;
		A[i] = n;
	}
	cout << "Choose sorting order (1: ascending order, 2: descending order): ";
	cin >> order;
	cout << "Initial array: ";
	for (int integer : A)
	{
		cout << setw(4) << integer;
	}
	cout << endl;

	selectionSort(A, size, order);

	if (order == 1)
	{
		cout << "Sorted in ascending order: ";
		for (int integer : A)
		{
			cout << setw(4) << integer;
		}
	}

	if (order == 2)
	{
		cout << "Sorted in descending order: ";
		for (int integer : A)
		{
			cout << setw(4) << integer;
		}
	}

}

void swap(int* const p1, int* const p2)
{
	int a{ *p1 }, b{ *p2 };
	*p1 = b;
	*p2 = a;
}

void selectionSort(int A[], const int size, int order)
{
	int k{ 0 };
	if (order == 1)
	{
		for (int i{ 0 }; i < size - 1; i++)
		{
			int* front{ &A[i] };
			int min{ i };

			for (int j{ i }; j < size; j++)
			{
				if (A[j] < A[min])
				{
					min = j;
				}
			}
			int* newMin{ &A[min] };
			swap(front, newMin);
			cout << "after " << k << "-th iteration:";
			k++;
			for (int l{ 0 }; l < 10; l++)
				cout << setw(4) << A[l];
			cout << endl;
		}
	}
	if (order == 2)
	{
		for (int i{ 0 }; i < size - 1; i++)
		{
			int* front{ &A[i] };
			int max{ i };

			for (int j{ i }; j < size; j++)
			{
				if (A[j] > A[max])
				{
					max = j;
				}
			}
			int* newMax{ &A[max] };
			swap(front, newMax);
			cout << "after " << k << "-th iteration:";
			k++;
			for (int l{ 0 }; l < 10; l++)
				cout << setw(4) << A[l];
			cout << endl;
		}
	}
}

