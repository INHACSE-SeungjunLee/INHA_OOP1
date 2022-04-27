#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

int findGCD(int x, int y)
{
	if (x % y == 0)
		return y;
	else
		return findGCD(y, x % y);
}

class Fraction
{
public:
	Fraction(int n, int d = 1) : num{ n }, den{ d } {};
	void setNum(int n)
	{
		num = n;
	}
	void setDen(int d)
	{
		den = d;
	}
	int getNum() const
	{
		return num;
	}
	int getDen() const
	{
		return den;
	}

	void setFraction(int &n, int &d)
	{
		if (n == 0)
		{
			n = 0;
			d = 1;
		}
		int div = findGCD(n, d);
		n = n / div;
		d = d / div;

		if (d < 0)
		{
			n *= -1;
			d *= -1;
		}
	}

private:
	int num;
	int den;
};

Fraction add(Fraction x, Fraction y);
Fraction subtract(Fraction x, Fraction y);
Fraction multiply(Fraction x, Fraction y);
Fraction divide(Fraction x, Fraction y);

int main()
{
	int n1{ 0 }, n2{ 0 }, d1{ 1 }, d2{ 1 };
	Fraction firstFraction{ n1, d1 };
	Fraction secondFraction{ n2, d2 };
	cout << "Enter the numerator and denominator of the first fraction: ";
	cin >> n1 >> d1;
	firstFraction.setFraction(n1, d1);
	firstFraction.setNum(n1);
	firstFraction.setDen(d1);
	cout << "First fraction: " << n1 << "/" << d1 << endl;
	cout << "Enter the numerator and denominator of the second fraction: ";
	cin >> n2 >> d2;
	secondFraction.setFraction(n2, d2);
	secondFraction.setNum(n2);
	secondFraction.setDen(d2);
	cout << "Second fraction: " << n2 << "/" << d2 << endl;

	cout << "(" << n1 << "/" << d1 << ")" << " + " << "(" << n2 << "/" << d2 << ")" << " = " 
		<< add(firstFraction, secondFraction).getNum() << "/" << add(firstFraction, secondFraction).getDen() << endl;

	cout << "(" << n1 << "/" << d1 << ")" << " - " << "(" << n2 << "/" << d2 << ")" << " = " 
		<< subtract(firstFraction, secondFraction).getNum() << "/" << subtract(firstFraction, secondFraction).getDen() << endl;

	cout << "(" << n1 << "/" << d1 << ")" << " * " << "(" << n2 << "/" << d2 << ")" << " = " 
		<< multiply(firstFraction, secondFraction).getNum() << "/" << multiply(firstFraction, secondFraction).getDen() << endl;

	cout << "(" << n1 << "/" << d1 << ")" << " / " << "(" << n2 << "/" << d2 << ")" << " = " 
		<< divide(firstFraction, secondFraction).getNum() << "/" << divide(firstFraction, secondFraction).getDen() << endl;
}

Fraction add(Fraction x, Fraction y)
{
	int num = x.getNum() * y.getDen() + x.getDen() * y.getNum();
	int den = x.getDen() * y.getDen();
	Fraction addFraction{ num, den };
	addFraction.setFraction(num, den);
	addFraction.setNum(num);
	addFraction.setDen(den);
	return addFraction;
}

Fraction subtract(Fraction x, Fraction y)
{
	int num = x.getNum() * y.getDen() - x.getDen() * y.getNum();
	int den = x.getDen() * y.getDen();
	Fraction subtractFraction{ num, den };
	subtractFraction.setFraction(num, den);
	subtractFraction.setNum(num);
	subtractFraction.setDen(den);
	return subtractFraction;
}

Fraction multiply(Fraction x, Fraction y)
{
	int num = x.getNum() * y.getNum();
	int den = x.getDen() * y.getDen();
	Fraction multiplyFraction{ num, den };
	multiplyFraction.setFraction(num, den);
	multiplyFraction.setNum(num);
	multiplyFraction.setDen(den);
	return multiplyFraction;
}

Fraction divide(Fraction x, Fraction y)
{
	int num = x.getNum() * y.getDen();
	int den = x.getDen() * y.getNum();
	Fraction divideFraction{ num, den };
	divideFraction.setFraction(num, den);
	divideFraction.setNum(num);
	divideFraction.setDen(den);
	return divideFraction;
}