#include <iostream>
using namespace std;

unsigned long countSums(long* firstArray, int firstSize, long* secondArray,
    int secondSize, long* thirdArray, int thirdSize, int &counter)
{
    for (int i = 0; i < firstSize; i++)
    {
        for (int j = 0; j < secondSize; j++)
        {
            for (int k = 0; k < thirdSize; k++)
            {
                if (firstArray[i] + secondArray[j] == thirdArray[k])
                {
                    counter++;
                    cout << firstArray[i] << " " << secondArray[j] << " " << thirdArray[k] << endl;
                }
                else if (firstArray[i] + thirdArray[k] == secondArray[j])
                {
                    counter++;
                    cout << firstArray[i] << " " << secondArray[j] << " " << thirdArray[k] << endl;
                }
                else if (secondArray[j] + thirdArray[k] == firstArray[i])
                {
                    counter++;
                    cout << firstArray[i] << " " << secondArray[j] << " " << thirdArray[k] << endl;
                }
            }
        }
    }

    return counter;
}


int main()
{
    int size1, size2, size3;
    
    cin >> size1;
    
    long* arr1 = new long[size1];
    for (int i = 0; i < size1; i++)
    {
        cin >> arr1[i];
    }

    cin >> size2;

    long* arr2 = new long[size2];
    for (int i = 0; i < size2; i++)
    {
        cin >> arr2[i];
    }

    cin >> size3;

    long* arr3 = new long[size3];
    for (int i = 0; i < size3; i++)
    {
        cin >> arr3[i];
    }

    int counter = 0;

    countSums(arr1, size1, arr2, size2, arr3, size3, counter);

    cout << counter << endl;
}
