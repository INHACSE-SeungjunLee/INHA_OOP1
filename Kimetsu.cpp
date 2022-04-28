#include <iostream>
#include <string>
using namespace std;

class Kimetsu
{
public:
	Kimetsu(std::string characterName, std::string weaponName, int experience) : cName{ characterName }, wName{ weaponName }, exp{ experience } {}

	void setCharacter(std::string characterName)
	{
		cName = characterName;
	}
	void setWeapon(std::string weaponName)
	{
		wName = weaponName;
	}
	void setExperience(int experience)
	{
		exp = experience;
	}

	std::string getCharacter()
	{
		return cName;
	}
	std::string getWeapon()
	{
		return wName;
	}
	int getExperience()
	{
		return exp;
	}

	void seeInfo()
	{
		std::cout << "Name: " << getCharacter() << std::endl;
		std::cout << "Weapon: " << getWeapon() << std::endl;
		std::cout << "Experience: " << getExperience() << std::endl;
	}

	void oniHunt(int oni)
	{
		if (oni > 0)
		{
			exp += oni;
		}
	}

private:
	std::string cName;
	std::string wName;
	int exp;
};

int main()
{
	Kimetsu you{ "anonymous", "bare hands", 0};
	int choice, oni;
	string characterName, weaponName;
	cout << "Enter character name: ";
	getline(cin, characterName);
	cout << "Enter weapon name: ";
	getline(cin, weaponName);
	
	you.setCharacter(characterName);
	you.setWeapon(weaponName);
	cout << "\nYou have created " << you.getCharacter() << "." << endl;

	do
	{
		cout << "\n1. See Info 2. Change Weapon 3. Oni Hunt 4. Exit" << endl;
		cout << "Choice: ";
		cin >> choice;

		switch (choice)
		{	
		case 1:
			you.seeInfo();
			break;
		case 2:
			cout << "What is new weapon?: ";
			cin.ignore(100, '\n');
			getline(cin, weaponName);
			you.setWeapon(weaponName);
			break;
		case 3:
			cout << "How many Onis to hunt?: ";
			cin >> oni;
			you.oniHunt(oni);
			break;
		case 4:
			cout << "Good Bye!";
			break;
		default:
			cout << "Choose again!";
			break;
		}
	} while (choice != 4);
}