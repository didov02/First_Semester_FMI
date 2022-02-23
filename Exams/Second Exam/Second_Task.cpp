#include <iostream>
using namespace std;


void encode(char word1[5],char word2[5],char word3[4])
{
    int checkedIndex[50];
    int counter = 0;
    bool isIndexChecked = false;

    for (int i = 0; i < 5; i++)
    {
        char firstLetter = word1[i];
        char secondLetter = word2[i];
        for (int j = 0; j < 4; j++)
        {
            char checkingLetter = word3[j];
            if (checkingLetter == firstLetter)
            {
                for (int k = 0; k < counter; k++)
                {
                    if (checkedIndex[k] == j)
                    {
                        isIndexChecked = true;
                        break;
                    }
                }

                if (isIndexChecked == true)
                {
                    break;
                }
                checkingLetter = secondLetter;
                checkedIndex[counter] = j;
                counter++;
            }
        }
    }

    cout << word3;
}

int main()
{
    char firstWord[5];
    cin >> firstWord;

    char secondWord[5];
    cin >> secondWord;

    char thirdWord[4];
    cin >> thirdWord;

    encode(firstWord, secondWord, thirdWord);

    return 0;
}
