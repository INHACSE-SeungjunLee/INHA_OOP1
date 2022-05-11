#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printVector(const vector<unsigned int>& v);

int main()
{
	vector <unsigned int> A;
	vector <unsigned int> B;
	vector <unsigned int> AunionB;
	vector <unsigned int> AintersectionB;

	cout << "Enter nonredundant, positive integers for A (-1 to end): ";
	int fA;
	cin >> fA;
	A.insert(A.begin(), fA);
	vector <unsigned int> dupA;
	unsigned int count{ 0 };
	while (1)
	{
		unsigned int intA;
		cin >> intA;
		if (intA == -1)
			break;
		A.push_back(intA);
		for (int i{ 0 }; i < A.size() - 1; i++)
		{
			if (A[i] == intA)
			{
				cout << "Duplicate number in A: " << intA << endl;
				A.pop_back();
			}
		}
	}
	vector <unsigned int> unsortA(A);
	sort(A.begin(), A.end());

	cout << "Enter nonredundant, positive integers for B (-1 to end): ";
	int fB;
	cin >> fB;
	B.insert(B.begin(), fB);
	
	while (1)
	{
		unsigned int intB;
		cin >> intB;
		if (intB == -1)
			break;
		B.push_back(intB);
		for (int i{ 0 }; i < B.size() - 1; i++)
		{
			if (B[i] == intB)
			{
				cout << "Duplicate number in B: " << intB << endl;
				B.pop_back();
			}
		}
	}
	vector <unsigned int> unsortB(B);
	sort(B.begin(), B.end());

	cout << "A before sorting: " << "{ ";
	printVector(unsortA);
	cout << "}" << endl;
	cout << "B before sorting: " << "{ ";
	printVector(unsortB);
	cout << "}" << endl;
	cout << "A after sorting: " << "{ ";
	printVector(A);
	cout << "}" << endl;
	cout << "B after sorting: " << "{ ";
	printVector(B);
	cout << "}" << endl;

	for (unsigned int numA : A)
	{
		for (unsigned int numB : B)
		{
			if (numA == numB)
			{
				AintersectionB.push_back(numA);
			}
		}
	}

	for (unsigned int numA : A)
		AunionB.push_back(numA);
	for (unsigned int numB : B)
	{
		bool search{ binary_search(A.begin(), A.end(), numB) };
		if (search == 0)
			AunionB.push_back(numB);
	}
	sort(AintersectionB.begin(), AintersectionB.end());
	sort(AunionB.begin(), AunionB.end());
	cout << "A union B: { ";
	printVector(AunionB);
	cout << "}" << endl;
	cout << "A intersection B: { ";
	printVector(AintersectionB);
	cout << "}";
}

void printVector(const vector<unsigned int>& v)
{
	for (auto const& integer : v)
		cout << integer << " ";
}