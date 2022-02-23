#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

int ArraySize(const char arr[])
{
	int counter = 0;
	while (arr[counter] != '\0')
	{
		counter++;
	}

	return counter;
}

int longestSubstrWithUniqueSymbolsLength(const char str[])
{
	int arrSize = ArraySize(str);
	int bestSize = 0;


	for (int i = 0; i < arrSize; i++)
	{
		char currentArray[MAX_SIZE] = { '\0' };

		for (int k = i; k < arrSize; k++)
		{
			char currentSymbol = str[k];
			int currentArraySize = ArraySize(currentArray);
			bool containSymbol = false;
			if (currentArraySize == 0)
			{
				currentArray[0] = currentSymbol;
			}
			else
			{
				for (int j = 0; j < currentArraySize; j++)
				{
					if (currentArray[j] == currentSymbol)
					{
						containSymbol = true;
						break;
					}
				}

				if (containSymbol == false)
				{
					currentArray[currentArraySize] = currentSymbol;
				}
				else if (containSymbol == true)
				{
					int arraySize = ArraySize(currentArray);

					if (bestSize < arraySize)
					{
						bestSize = arraySize;
					}

					break;
				}
			}
		}
	}

	return bestSize;
}

int main()
{
	char input[MAX_SIZE];
	cin >> input;
	int counter = longestSubstrWithUniqueSymbolsLength(input);
	cout << counter;

	return 0;
}
