#include <iostream>
#include <stdlib.h>
#include <array>
using namespace std;

void printMatrix(const array<array<int, 3>, 3>& mat);

int main()
{
	array <array<int, 3>, 3>matrixA;
	array <array<int, 3>, 3>matrixB;
	array <array<int, 3>, 3>matrixC {0,0,0,0,0,0,0,0,0};
	srand(0);

	for (auto& row : matrixA)
	{
		for (auto& element : row)
			element = rand() % 4;
	}

	for (auto& row : matrixB)
	{
		for (auto& element : row)
			element = rand() % 4;
	}

	cout << "matrix A:" << endl;
	printMatrix(matrixA);
	cout << "matrix B:" << endl;
	printMatrix(matrixB);

	for (int i{ 0 }; i < 3; i++)
	{
		for (int j{ 0 }; j < 3; j++)
		{
			for (int k{ 0 }; k < 3; k++)
			{
				matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
			}
		}
	}
	cout << "matrix C:" << endl;
	printMatrix(matrixC);
}

void printMatrix(const array<array<int, 3>, 3>& mat)
{
	for (auto const& row : mat)
	{
		for (auto const& element : row)
		{
			cout << element << " ";
		}
		cout << endl;
	}
}