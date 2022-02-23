#include <iostream>

using namespace std;

const int COLS = 2;

int** splitArr(int* arr, int M)
{
	int sum = 0;

	for (int i = 0; i < M; i++)
	{
		sum += arr[i];
	}

	sum /= M;

	int** buffer = new int* [M];
	for (int i = 0; i < M; i++)
	{
		buffer[i] = new int[COLS];
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (j == 0)
			{
				buffer[i][j] = arr[i];
			}
			else
			{
				buffer[i][j] = sum;
			}
		}
	}

	return buffer;
}
