#include <iostream>

using namespace std;

const int maxSizeForStr = 1000;
const int maxSizeForText = 4000;

int ArrSize(char array[])
{
    int counter = 0;
    while (array[counter] != '\0')
    {
        counter++;
    }

    return counter;
}

int main()
{
    char text[maxSizeForText], str1[maxSizeForStr], str2[maxSizeForStr];
    cin.getline(text, maxSizeForText);
    cin.getline(str1, maxSizeForStr);
    cin.getline(str2, maxSizeForStr);

    int textSize = ArrSize(text);
    int str1Size = ArrSize(str1);
    int str2Size = ArrSize(str2);

    int finalCounter = 0;

    char saved[maxSizeForText];

    for (int i = 0; i < textSize; i++)
    {
        int tmpCounterForStr1 = 0;
        if (text[i] == str1[0])
        {
            for (int j = i; j < str1Size + i; j++)
            {
                if (text[j] == str1[tmpCounterForStr1])
                {
                    tmpCounterForStr1++;
                }
                else
                {
                    break;
                }
            }
        }

        if (tmpCounterForStr1 == str1Size)
        {
            finalCounter++;

            int savedCounter = 0;
            bool textToBeSaved = false;
            if (i + str1Size < textSize)
            {
                textToBeSaved = true;
                for (int p = i + str1Size; p < textSize; p++)
                {
                    saved[savedCounter] = text[p];
                    savedCounter++;
                }
                saved[savedCounter] = '\0';
            }

            int tmpCounterForStr2 = 0;
            for (int k = i; k < str2Size + i; k++)
            {
                text[k] = str2[tmpCounterForStr2];
                tmpCounterForStr2++;
            }
            text[tmpCounterForStr2 + i] = '\0';

            if (textToBeSaved == true)
            {
                int tmpCounterForSaved = 0;
                int savedSize = ArrSize(saved);
                textSize = ArrSize(text);
                for (int m = textSize; m < textSize + savedSize; m++)
                {
                    text[m] = saved[tmpCounterForSaved];
                    tmpCounterForSaved++;
                }
                int lastIndex = savedSize + textSize;
                text[lastIndex] = '\0';
            }
            
            textSize = ArrSize(text);
        }
    }

    cout << finalCounter << endl;

    cout << text << endl;
}
