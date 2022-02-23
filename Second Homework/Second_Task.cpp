#include <iostream>
using namespace std;

int reverse(int num)
{
    int reminder, reversedNum = 0;
    while (num != 0)
    {
        reminder = num % 10;
        reversedNum = reversedNum * 10 + reminder;
        num /= 10;
    }
    
    return reversedNum;
}

bool isPalindrom(int n)
{
    if (n >= -99 && n <= 99)
    {
        return false;
    }
    else
    {
        int absN = abs(n);
        int reversedAbsN = reverse(absN);
        if (absN == reversedAbsN)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

int main()
{
    int number;
    cin >> number;
    
    if (number<1 || number>pow(10, 9))
    {
        cout << "-1";
        return -1;
    }

    bool isNumberPalindrom = isPalindrom(number);
    if (isNumberPalindrom == true)
    {
        cout << number << endl;
        return 0;
    }

    int lessThanOurNumber = number - 1;//for numbers < number
    int biggerThanOurNumber = number + 1;//for numbers > number

    while (true)
    {
        bool isBiggerNumPalindrom = isPalindrom(biggerThanOurNumber);
        bool isLessNumPalindrom = isPalindrom(lessThanOurNumber);

        if (isBiggerNumPalindrom == true && isLessNumPalindrom == false)
        {
            cout << biggerThanOurNumber << endl;
            break;
        }
        else if(isLessNumPalindrom == true)
        {
            cout << lessThanOurNumber << endl;
            break;
        }

        lessThanOurNumber--;
        biggerThanOurNumber++;
    }

    return 0;
}
