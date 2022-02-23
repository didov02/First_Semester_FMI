#include <iostream>
using namespace std;

const int MAX_SIZE = 100;
const int CONVERTING_NUMBER = 32;
const int z_IN_DEC = 122;
const int a_IN_DEC = 97;
const int Z_IN_DEC = 90;
const int A_IN_DEC = 65;

int ArraySize(char arr[])
{
	int counter = 0;
	while (arr[counter] != '\0')
	{
		counter++;
	}

	return counter;
}

void ReturnTheWordWithBigLetter(char arr[], int currentSize)
{
	arr[currentSize] = arr[currentSize] - CONVERTING_NUMBER;
	cout << arr << " ";
	arr[currentSize] = arr[currentSize] + CONVERTING_NUMBER;
}

void ReturnTheWordWithSmallLetter(char arr[], int currentSize)
{
	arr[currentSize] = arr[currentSize] + CONVERTING_NUMBER;
	cout << arr << " ";
	arr[currentSize] = arr[currentSize] - CONVERTING_NUMBER;
}

bool CheckIfItIsALetter(char input)
{
	if ((input >= a_IN_DEC && input <= z_IN_DEC) || (input >= A_IN_DEC && input <= Z_IN_DEC))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void CurrentOutput(char arr[], char letter, int arrSize)
{
	int position = 0;
	for (int i = 0; i < arrSize; i++)
	{
		if (arr[i] == letter)
		{
			position = i;
			break;
		}
	}

	if (letter >= a_IN_DEC && letter <= z_IN_DEC)
	{
		ReturnTheWordWithBigLetter(arr, position);
	}
	else if (letter >= A_IN_DEC && letter <= Z_IN_DEC)
	{
		ReturnTheWordWithSmallLetter(arr, position);
	}
}

void ChangeWholeArray(char arr[], int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		if (arr[i] >= a_IN_DEC && arr[i] <= z_IN_DEC)
		{
			arr[i] -= CONVERTING_NUMBER;
		}
		else if (arr[i] >= A_IN_DEC && arr[i] <= Z_IN_DEC)
		{
			arr[i] += CONVERTING_NUMBER;
		}
	}

	cout << arr;
}

void FinalOutput(char arr[], int arrSize)
{
	cout << arr << " ";

	char checkedLetters[MAX_SIZE] = { '\0' };
	int counter = 0;//for checkedLetters

	char biggestLetter = NULL;

	for (int i = 0; i < arrSize; i++)
	{
		for (int j = 0; j < arrSize; j++)
		{
			bool isLetter = CheckIfItIsALetter(arr[j]);

			if (isLetter == true)
			{
				if (arr[j] > biggestLetter)
				{
					bool isThere = false;// do we have the letter in checkedLetters

					for (int i = 0; i < counter; i++)
					{
						if (checkedLetters[i] == arr[j])
						{
							isThere = true;
							break;
						}
					}

					if (isThere == false)
					{
						biggestLetter = arr[j];
					}
				}
			}
		}

		if (biggestLetter != NULL)
		{
			checkedLetters[counter] = biggestLetter;
			counter++;
			CurrentOutput(arr, biggestLetter, arrSize);
		}
		biggestLetter = NULL;
	}

	if (counter > 1)
	{
		ChangeWholeArray(arr, arrSize);
	}
}

int main()
{
	char* input = new char[MAX_SIZE];
	cin.getline(input, MAX_SIZE);
	int inputSize = ArraySize(input);
	FinalOutput(input, inputSize);

	delete[] input;

	return 0;
}
