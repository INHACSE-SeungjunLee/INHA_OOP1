#include <iostream>
#include <string>
#include <array>
using namespace std;

bool testPalindrome(string s, size_t left, size_t right);

int main()
{
	string s;
	while (cout << "Enter a string (EOF to quit): " && getline(cin, s))
	{
		int len = s.length();
		int l{ 0 }, r{ len - 1 };

		for (int i = 0; i < len; i++)
		{
			char character = s[i];
			int asciiValue = int(character);
			if (asciiValue != 32 && asciiValue != 46 && asciiValue != 44 && asciiValue != 63)
				break;
			if (asciiValue == 32 || asciiValue == 46 || asciiValue == 44 || asciiValue == 63)
				l++;
		}

		for (int j = len - 1; j > 0; j--)
		{
			char character = s[j];
			int asciiValue = int(character);
			if (asciiValue != 32 && asciiValue != 46 && asciiValue != 44 && asciiValue != 63)
				break;
			r--;
		}
		size_t left = l;
		size_t right = r;
		if (testPalindrome(s, left, right) == true)
			cout << "\"" << s << "\"" << " is a palindrome." << endl;
		if (testPalindrome(s, left, right) == false)
			cout << "\"" << s << "\"" << " is not a palindrome." << endl;
	}

}

bool testPalindrome(string s, size_t left, size_t right)
{
	while (left < right)
	{
		string marks{ " ,.?" };
		while (s[left] == marks[0] || s[left] == marks[1] || s[left] == marks[2] || s[left] == marks[3])
		{
			left += 1;
		}
		while (s[right] == marks[0] || s[right] == marks[1] || s[right] == marks[2] || s[right] == marks[3])
		{
			right -= 1;
		}
		if (s.length() == 1)
			return true;
		if (s[left] != s[right])
			return false;
		if (s[left] == s[right])
			return testPalindrome(s, left + 1, right - 1);
		return true;
	}
	return true;
}