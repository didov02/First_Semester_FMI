#include <iostream>

using namespace std;

void Swap(int& num1, int& num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

int* convertNum(long num, int k, int m)
{
	int temp = num;
	int numSize = 0;

	while (temp > 0)
	{
		numSize++;
		temp /= 10;
	}

	int* buffer = new int[numSize];
	int counter = 0;
	while (num > 0)
	{
		buffer[counter++] = num % 10;
		num /= 10;
	}

	for (int i = 0; i < numSize / 2; i++)
	{
		Swap(buffer[i], buffer[numSize - 1 - i]);
	}

	Swap(buffer[k - 1], buffer[m - 1]);

	return buffer;

}
