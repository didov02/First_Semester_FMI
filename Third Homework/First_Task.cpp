#include <iostream>
using namespace std;

int ArraySize(const char arr[])
{
	int counter = 0;
	while (arr[counter] != '\0')
	{
		counter++;
	}

	return counter;
}

bool FirstCase(const char arr1[], const char arr2[], int size)//when first array's size is bigger than second array's size
{
	int corrections = 0;
	bool isCorrect = true;
	int j = 0;

	for (int i = 0; i < size; i++)
	{
		if (arr1[i] != arr2[j])
		{
			if (arr1[i + 1] == arr2[j])
			{
				i++;
				corrections++;
			}
			else
			{
				isCorrect = false;
				break;
			}
		}

		if (corrections == 2)
		{
			isCorrect = false;
			break;
		}

		j++;
	}

	return isCorrect;
}

bool SecondCase(const char arr1[], const char arr2[], int size)//when second array's size is bigger than first array's size
{
	int corrections = 0;
	bool isCorrect = true;
	int j = 0;

	for (int i = 0; i < size; i++)
	{
		if (arr2[i] != arr1[j])
		{
			if (arr2[i + 1] == arr1[j])
			{
				i++;
				corrections++;
			}
			else
			{
				isCorrect = false;
				break;
			}
		}

		if (corrections == 2)
		{
			isCorrect = false;
			break;
		}

		j++;
	}

	return isCorrect;
}

bool ThirdCase(const char arr1[], const char arr2[], int size)//when first array's size is equal to second array's size
{
	int corrections = 0;
	bool isCorrect = true;
	for (int i = 0; i < size; i++)
	{
		if (arr1[i] != arr2[i])
		{
			corrections++;
		}

		if (corrections == 2)
		{
			isCorrect = false;
			break;
		}
	}

	if (corrections == 0)
	{
		isCorrect = false;
	}

	return isCorrect;
}

bool isCorrect(const char sequence[][20], int sequenceSize)
{
	bool isCorrect = true;
	for (int i = 0; i < sequenceSize - 1; i++)
	{
		int firstWordSize = ArraySize(sequence[i]);
		int secondWordSize = ArraySize(sequence[i + 1]);

		if (firstWordSize > secondWordSize)
		{
			bool check = FirstCase(sequence[i], sequence[i + 1], secondWordSize);
			if (check == false)
			{
				isCorrect = false;
				break;
			}
		}
		else if (secondWordSize > firstWordSize)
		{
			bool check = SecondCase(sequence[i], sequence[i + 1], firstWordSize);
			if (check == false)
			{
				isCorrect = false;
				break;
			}
		}
		else if (firstWordSize == secondWordSize)
		{
			bool check = ThirdCase(sequence[i], sequence[i + 1], firstWordSize);
			if (check == false)
			{
				isCorrect = false;
				break;
			}
		}
	}

	return isCorrect;
}

int main()
{
	int N;
	cin >> N;
	if (N < 2 || N>50)
	{
		cout << "-1" << endl;
		return -1;
	}

	cin.get();
	char input[50][20];
	for (int i = 0; i < N; i++)
	{
		cin.getline(input[i], 20);
	}

	bool check = isCorrect(input, N);
	cout << boolalpha << check;
}
