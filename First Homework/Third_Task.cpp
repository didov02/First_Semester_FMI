#include <iostream>
using namespace std;

int main()
{
	int tabsNumber, salary;
	cin >> tabsNumber;
	cin >> salary;

	bool noSalary = false;
	bool wrongInput = false;

	for (int i = 0; i < tabsNumber; i++)
	{
		if (salary <= 0)
		{
			noSalary = true;
			cout << "You have lost your salary." << endl;
			break;
		}

		char currentTab;
		cin >> currentTab;

		if (currentTab == 'f' || currentTab == 'F')
		{
			salary -= 150;
		}
		else if (currentTab == 'i' || currentTab == 'I')
		{
			salary -= 100;
		}
		else if (currentTab == 'r' || currentTab == 'R')
		{
			salary -= 50;
		}
		else if (currentTab == 'd' || currentTab == 'D')
		{
			salary -= 0;
		}
		else
		{
			wrongInput = true;
			break;
		}

	}
	
	if (wrongInput == true)
	{
		cout << "-1";
		return -1;
	}

	if (noSalary == false)
	{
		cout << salary << endl;
	}

	return 0;

}
