#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

bool AreThereEqualElements(int arr[], int size)
{
	bool equalElements = false;
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] == arr[j])
			{
				equalElements = true;
				break;
			}
		}

		if (equalElements == true)
		{
			break;
		}
	}

	return equalElements;
}

int longestDist(const int arr[], const int arrSize)
{
	int index = 0;
	bool stopper = false;
	for (int i = 0; i < arrSize; i++)
	{
		for (int j = arrSize - 1; j > i; j--)
		{
			if (arr[i] == arr[j])
			{
				stopper = true;
				index = i;
				break;
			}
		}

		if (stopper == true)
		{
			break;
		}
	}

	return index;
}

int main()
{
	int size;
	cin >> size;

	int input[MAX_SIZE];
	for (int i = 0; i < size; i++)
	{
		cin >> input[i];
	}

	if (size > 100)
	{
		cout << "-1" << endl;
		return -1;
	}
	else if (size < 2)
	{
		cout << "-2" << endl;
		return -1;
	}

	bool equalElements = AreThereEqualElements(input, size);
	if (equalElements == false)
	{
		cout << "-1" << endl;
		return -1;
	}

	int indexOfFirstEqualElement = longestDist(input, size);
	cout << indexOfFirstEqualElement << endl;

	return 0;
}
