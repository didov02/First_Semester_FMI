#include <iostream>
using namespace std;

int SizeOfArr(char array[255], int& size)
{
	for (int i = 0; array[i] != '\0'; i++)
	{
		size++;
	}
	return size;
}

int main()
{
	char arr[255];
	cin.getline(arr, 255);

	int size = 0;
	SizeOfArr(arr, size);

	char arrWithLowercase[255];
	char arrWithUppercase[255];

	int firstCounter = 0;
	int secondCounter = 0;
	for (int i = 0; i < size; i++)
	{
		if ((int)arr[i] >= 97 && (int)arr[i] <= 122)
		{
			arrWithLowercase[firstCounter] = arr[i];
			firstCounter++;
		}
		else if ((int)arr[i] >= 65 && (int)arr[i] <= 90)
		{
			arrWithUppercase[secondCounter] = arr[i];
			secondCounter++;
		}
	}
	arrWithLowercase[firstCounter] = '\0';
	arrWithUppercase[secondCounter] = '\0';

	int sizeOfArrWithLowercase = 0;
	int sizeOfArrWithUppercase = 0;
	SizeOfArr(arrWithLowercase, sizeOfArrWithLowercase);
	SizeOfArr(arrWithUppercase, sizeOfArrWithUppercase);

	bool areEqual = true;

	if (sizeOfArrWithLowercase != sizeOfArrWithUppercase)
	{
		areEqual = false;
	}
	else
	{
		for (int i = 0; i < sizeOfArrWithLowercase; i++)
		{
			if (arrWithLowercase[i] != arrWithUppercase[i] + 32)
			{
				areEqual = false;
			}
		}
	}

	if (areEqual == false)
	{
		cout << "No" << endl;
	}
	else
	{
		cout << "Yes" << endl;
	}

	return 0;
}
