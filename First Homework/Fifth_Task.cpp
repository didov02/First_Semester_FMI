#include <iostream>
using namespace std;

int main()
{
	int number;
	cin >> number;

	if (number < 0)
	{
		cout << "-1";
		return -1;
	}

	int result = 0;
	int counter = 1;

	while (number > 0)
	{
		int currentNumber = number % 10;
		if (currentNumber % 2 != 0)
		{
			result += (currentNumber)*counter;
			counter *= 10;
		}
		number /= 10;
	}
	cout << result;

	return 0;
}
