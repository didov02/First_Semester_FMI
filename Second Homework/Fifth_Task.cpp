#include <iostream>
using namespace std;

const int LEAP_YEAR_IN_SECONDS = 31622400;
const int NORMAL_YEAR_IN_SECONDS = 31536000;
const int ODD_MONTH_IN_SECONDS = 2678400;
const int EVEN_MONTH_IN_SECONDS = 2592000;
const int LEAP_FEBRURAY_IN_SECONDS = 2505600;
const int NORMAL_FEBRURAY_IN_SECONDS = 2419200;
const int DAY_IN_SECONDS = 86400;
const int HOUR_IN_SECONDS = 3600;
const int MINUTE_IN_SECONDS = 60;

void PrintDaysAndMonths(int number)
{
	if (number < 10)
	{
		cout << "0" << number << ".";
	}
	else
	{
		cout << number << ".";
	}
}
void PrintHoursAndMinutes(int number)
{
	if (number < 10)
	{
		cout << "0" << number << ":";
	}
	else
	{
		cout << number << ":";
	}
}

int main()
{
	unsigned int input;
	cin >> input;
	int year = 1970;
	int month = 1;
	int day = 0;
	int hour = 0;
	int minutes = 0;
	int seconds = 0;

	while ((int)input - LEAP_YEAR_IN_SECONDS > 0 || (int)input - NORMAL_YEAR_IN_SECONDS > 0)
	{
		if (year % 4 == 0 && year % 100 != 0)
		{
			input -= LEAP_YEAR_IN_SECONDS;
		}
		else
		{
			input -= NORMAL_YEAR_IN_SECONDS;
		}
		year++;
	}

	if (year % 4 == 0 && year % 100 != 0)
	{
		while (((int)input - ODD_MONTH_IN_SECONDS >= 0 || (int)input - EVEN_MONTH_IN_SECONDS >= 0)
			&& (int)input - LEAP_FEBRURAY_IN_SECONDS >= 0)
		{
			if (month == 2)
			{
				input -= LEAP_FEBRURAY_IN_SECONDS;
			}
			else if (month % 2 == 0)
			{
				input -= EVEN_MONTH_IN_SECONDS;
			}
			else
			{
				input -= ODD_MONTH_IN_SECONDS;
			}
			month++;
		}
	}
	else
	{
		while ((int)input - ODD_MONTH_IN_SECONDS >= 0 || (int)input - EVEN_MONTH_IN_SECONDS >= 0
			|| (int)input - LEAP_FEBRURAY_IN_SECONDS >= 0)
		{
			if (month == 2)
			{
				input -= NORMAL_FEBRURAY_IN_SECONDS;
			}
			else if (month % 2 == 0)
			{
				input -= EVEN_MONTH_IN_SECONDS;
			}
			else
			{
				input -= ODD_MONTH_IN_SECONDS;
			}
			month++;
		}
	}

	while ((int)input - DAY_IN_SECONDS >= 0)
	{
		input -= DAY_IN_SECONDS;
		day++;
	}
	if (day == 0)
	{
		day = 1;
	}

	while ((int)input - HOUR_IN_SECONDS >= 0)
	{
		input -= HOUR_IN_SECONDS;
		hour++;
	}

	while ((int)input - MINUTE_IN_SECONDS >= 0)
	{
		input -= MINUTE_IN_SECONDS;
		minutes++;
	}

	seconds = input;

	PrintDaysAndMonths(day);
	PrintDaysAndMonths(month);
	cout << year << " ";
	PrintHoursAndMinutes(hour);
	PrintHoursAndMinutes(minutes);
	if (seconds < 10)
	{
		cout << "0" << seconds << endl;
	}
	else
	{
		cout << seconds << endl;
	}

	return 0;
}
