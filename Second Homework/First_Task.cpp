#include <iostream>
using namespace std;

int turnIntoBinary(unsigned num)
{
	int binaryNumber = 0;
	int multiplier = 1;
	while (num > 0)
	{
		if (num % 2 != 0)
		{
			binaryNumber += multiplier * 1;
			multiplier *= 10;
		}
		else
		{
			multiplier *= 10;
		}
		num /= 2;
	}

	return binaryNumber;
}

bool hasAlternatingBits(unsigned n)
{
	int convertedBinaryN = turnIntoBinary(n);
	bool isAlternating = true;
	while (convertedBinaryN > 10)
	{
		int lastDigit = convertedBinaryN % 10;
		int beforeLastDigit = convertedBinaryN / 10 % 10;
		if (lastDigit == beforeLastDigit)
		{
			isAlternating = false;
			break;
		}
		convertedBinaryN /= 10;
	}

	return isAlternating;
}

int main()
{
	int number;
	cin >> number;
	
	if (number < 0)
	{
		cout << "-1" << endl;
		return -1;
	}

	bool isNumberAlternating = hasAlternatingBits(number);
	
	if (isNumberAlternating == true)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}

	return 0;
}
