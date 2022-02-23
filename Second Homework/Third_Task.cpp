
#include <iostream>
using namespace std;

int WhileFunc(int num, int &res, int &count)//used in order to make result equal to number
{
	while (res < num)
	{
		res++;
		count++;
	}
	return res, count;
}

int main()//we are going to convert the calculator and make our result equal to the given number
{
	int number, result;
	cin >> number >> result;
	int counter = 0;
	if (result < number)
	{
		WhileFunc(number, result, counter);
	}
	else if (result % 2 == 0)
	{
		if (result / 2 < number)
		{
			result /= 2;
			counter++;
			WhileFunc(number, result, counter);
		}
		else
		{
			result /= 2;
			counter++;
			if (result % 2 != 0)
			{
				result++;
				counter++;
			}
			if (result < number)
			{
				WhileFunc(number, result, counter);
			}
			else if (result > number)
			{
				while (result > number)
				{
					result /= 2;
					counter++;
				}

				if (result != number)
				{
					WhileFunc(number, result, counter);
				}
			}

		}
	}
	else
	{
		result++;
		counter++;
		result /= 2;
		counter++;
		if (result < number)
		{
			WhileFunc(number, result, counter);
		}
		else if (result > number)
		{
			if (result % 2 != 0)
			{
				result++;
				counter++;
			}
			result /= 2;
			counter++;
			if (result < number)
			{
				WhileFunc(number, result, counter);
			}
			else if (result > number)
			{
				while (result != number)
				{
					if (result % 2 != 0)
					{
						result++;
						counter++;
					}
					result /= 2;
					counter++;
					if (result < number)
					{
						WhileFunc(number, result, counter);
					}
				}
			}
		}

	}

	cout << counter << endl;
	return 0;
}
