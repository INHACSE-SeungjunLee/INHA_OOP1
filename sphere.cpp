#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Sphere
{
public:
	Sphere(int x, int y, int z, int R, std::string name) : coordX{ x }, coordY{ y }, coordZ{ z }, radius{ R }, name{} {}

	void setName(std::string sphereName)
	{
		name = sphereName;
	}
	void setCenter(int x, int y, int z)
	{
		coordX = x;
		coordY = y;
		coordZ = z;
	}
	void setRadius(int R)
	{
		radius = R;
	}

	std::string getName()
	{
		return name;
	}
	int getX()
	{
		return coordX;
	}
	int getY()
	{
		return coordY;
	}
	int getZ()
	{
		return coordZ;
	}

private:
	int coordX;
	int coordY;
	int coordZ;
	int radius;
	std::string name;
};

int main()
{
	int x1, y1, z1, r1;
	int x2, y2, z2, r2;
	string name1, name2;
	Sphere firstSphere{ 0, 0, 0, 0 , " "};
	Sphere secondSphere{ 0, 0, 0, 0 , " "};

	cout << "Input name of first sphere: ";
	getline(cin, name1);
	firstSphere.setName(name1);
	cout << "Input name of second sphere: ";
	getline(cin, name2);
	secondSphere.setName(name2);

	cout << "Enter the center and radius of sphere " << firstSphere.getName() << " : ";
	cin >> x1 >> y1 >> z1 >> r1;
	firstSphere.setCenter(x1, y1, z1);
	firstSphere.setRadius(r1);
	cout << "Enter the center and radius of sphere " << secondSphere.getName() << " : ";
	cin >> x2 >> y2 >> z2 >> r2;
	secondSphere.setCenter(x2, y2, z2);
	secondSphere.setRadius(r2);

	int distance, sum;
	distance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2) + pow(z1 - z2, 2));
	sum = r1 + r2;

	if (distance > sum)
	{
		cout << firstSphere.getName() << " and " << secondSphere.getName() << " do not overlap.";
	}

	else if (distance == sum)
	{
		cout << firstSphere.getName() << " and " << secondSphere.getName() << " are tangent.";
	}

	else if (distance < sum)
	{
		cout << firstSphere.getName() << " and " << secondSphere.getName() << " overlap.";
	}
}