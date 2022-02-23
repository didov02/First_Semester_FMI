#include <iostream>

using namespace std;

const int firstSize = 0;

bool firstRuleForHacksaw(int* arr, int maxSize, int startingSize)
{
    if (startingSize % 2 == 0 && startingSize == firstSize)
    {
        if (arr[startingSize] > arr[startingSize + 1])
        {
            return false;
        }
    
        firstRuleForHacksaw(arr, maxSize, startingSize + 1);
    }
    else if (startingSize == maxSize -1)
    {
        return true;
    }
    else
    {
        if (startingSize % 2 == 0)
        {
            if (arr[startingSize] > arr[startingSize + 1] || arr[startingSize] > arr[startingSize - 1])
            {
                return false;
            }

            firstRuleForHacksaw(arr, maxSize, startingSize + 1);
        }
        else
        {
            if (arr[startingSize] < arr[startingSize + 1] || arr[startingSize] < arr[startingSize - 1])
            {
                return false;
            }

            firstRuleForHacksaw(arr, maxSize, startingSize + 1);
        }
    }
}

bool secondRuleForHacksaw(int* arr, int maxSize, int startingSize)
{
    if (startingSize % 2 == 0 && startingSize == firstSize)
    {
        if (arr[startingSize] < arr[startingSize + 1])
        {
            return false;
        }

        secondRuleForHacksaw(arr, maxSize, startingSize + 1);
    }
    else if (startingSize == maxSize - 1)
    {
        return true;
    }
    else
    {
        if (startingSize % 2 == 0)
        {
            if (arr[startingSize] < arr[startingSize + 1] || arr[startingSize] < arr[startingSize - 1])
            {
                return false;
            }

            secondRuleForHacksaw(arr, maxSize, startingSize + 1);
        }
        else
        {
            if (arr[startingSize] > arr[startingSize + 1] || arr[startingSize] > arr[startingSize - 1])
            {
                return false;
            }

            secondRuleForHacksaw(arr, maxSize, startingSize + 1);
        }
    }
}

int main()
{
    int n;
    cin >> n;

    int* array = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    if (n < 3 || n>1000)
    {
        cout << "-1";
        return -1;
    }

    int startingIndex = 0;

    bool isFirstRuleCorrect = firstRuleForHacksaw(array, n, startingIndex);
    bool isSecondRuleCorrect = secondRuleForHacksaw(array, n, startingIndex);

    if (isFirstRuleCorrect == true || isSecondRuleCorrect == true)
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }

    delete[] array;

    return 0;
}
