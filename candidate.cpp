#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

class Candidate 
{
public:
	static const int maxLength{ 11 };
	Candidate(unsigned candID = 0, const string& candName = "", unsigned v = 0) : ID{ candID }, name{""}, votes{v} {};

	void setID(unsigned candID)
	{
		ID = candID;
	}
	unsigned getID() const
	{
		return ID;
	}
	void setName(const string& candName )
	{
		char* namePtr{ name };
		if (candName.size() < 11)
		{
			unsigned i{ 0 };
			for ( ; i < candName.size(); i++)
			{
				*(namePtr + i) = candName[i];
			}
			*(namePtr + i+1) = '\0';
		}
		else if (candName.size() >= 11)
		{
			for (int i = 0; i < 10; i++)
			{
				*(namePtr + i) = candName[i];
			}
			*(namePtr + 10) = '\0';
		}
		
	}
	string getName() const
	{
		return name;
	}
	void setVotes(unsigned v)
	{
		votes = v;
	}
	unsigned getVotes() const
	{
		return votes;
	}
	void increaseVotes()
	{
		votes++;
	}

private:
	unsigned ID;
	char name[maxLength];
	unsigned votes;
};

int main()
{
	Candidate candidates[10];
	Candidate* candPtr{ candidates };
	int candNum, pollNum;
	string candName;
	cout << "Enter the number of candidates and polls: ";
	cin >> candNum >> pollNum;
	srand(pollNum);
	cin.ignore();

	for (int i = 0; i < candNum; i++)
	{
		cout << "Enter the name of candidate #" << i + 1 << ": ";
		getline(cin, candName);
		candPtr[i].setID(i + 1);
		candPtr[i].setName(candName);
	}
	cout << endl << "Results of " << pollNum << " exit polls" << endl;
	
	for (int i = 0; i < pollNum; i++)
	{
		int answer{ rand() % candNum + 1 };
		candPtr[answer - 1].increaseVotes();
	}

	for (int i = 0; i < candNum; i++)
	{
		double d = static_cast<double> (candPtr[i].getVotes()) / 100;
		int rounded = static_cast<int>(round(d));
		cout << "Candidate #" << candPtr[i].getID() << ": ";
		for (int i = 0; i < rounded; i++)
			cout << "*";
		cout << " (" << candPtr[i].getVotes() << " votes, " << fixed << setprecision(2) << static_cast<double>(candPtr[i].getVotes())*100 / pollNum << "%)" << endl;
	}
	cout << endl;

	int maxCand = 0;
	
	for (int i = 0; i < candNum; i++)
	{
		unsigned maxVote = candPtr[maxCand].getVotes();
		if (candPtr[i].getVotes() > maxVote)
		{
			maxCand = i;
		}
	}

	cout << "Candidate #" << candPtr[maxCand].getID() << " " << candPtr[maxCand].getName() << " is likely to win.";
}