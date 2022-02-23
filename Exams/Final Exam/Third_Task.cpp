#include <iostream>

using namespace std;

const int MAX_SIZE = 20;
const int TAB = 9;
const int SPACE = 32;

int ArraySize(char* arr)
{
	int counter = 0;
	while (arr[counter] != '\0')
	{
		counter++;
	}

	return counter;
}

bool isValid(char symbol)
{
	if (symbol != TAB && symbol != SPACE)
	{
		return true;
	}

	return false;
}

bool CheckIsItSmall(char symbol)
{
	if (symbol >= 97 && symbol <= 122)
	{
		return true;
	}

	return false;
}

int maxWord(char* str)
{
	int strSize = ArraySize(str);

	int max_word = 0;
	int maxWordsCounter = 0;

	for (int i = 0; i < strSize; i++)
	{
		char* currentWord = new char[MAX_SIZE];
		int counter = 0;
		int temp = i;
		for (int j = temp; j < strSize; j++)
		{
			if (!isValid(str[j]))
			{
				break;
			}

			currentWord[counter++] = str[j];
			i++;
		}
		currentWord[counter] = '\0';

		int smallLetters = 0;

		if (maxWordsCounter < counter)
		{
			maxWordsCounter = counter;

			for (int i = 0; i < counter; i++)
			{
				if (CheckIsItSmall(currentWord[i]))
				{
					smallLetters++;
				}
			}

			max_word = counter * smallLetters;
		}

		delete[] currentWord;
	}

	return max_word;
}
