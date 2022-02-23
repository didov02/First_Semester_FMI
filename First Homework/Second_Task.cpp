#include <iostream>
using namespace std;

int main()
{
	int number;
	cin >> number;

	if (number < 1 || number>9)
	{
		cout << "-1";
		return -1;
	}

	int counter = 0;// count spaces
	for (int i = 1; i < number; i++)
	{
		for (int p = 0; p < counter; p++)
		{
			cout << " ";
		}
		for (int j = i; j <= number; j++)
		{
			cout << j;
		}
		cout << endl;
		counter++;
	}

	for (int i = number; i >= 1; i--)
	{
		int secondCounter = counter;
		while (secondCounter > 0)
		{
			cout << " ";
			secondCounter--;
		}

		for (int j = number; j >= i; j--)
		{
			cout << j;
		}
		cout << endl;
	}

	return 0;
}
