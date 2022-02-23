#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double x, y;
    cin >> x >> y;
    int wholeCircleRadius = 4;
    int centre = 0;
    int smallRadius = 0, bigRadius = 0;
    if ((x > 0 && x < 4) && (y > 0 && y < 4))//1st quadrant
    {
        smallRadius = 1;
        centre = 2;
       
        int firstSideSecondPower;
        if (x <= centre)
        {
            firstSideSecondPower = (centre - x) * (centre - x);
        }
        else
        {
            firstSideSecondPower = (x - centre) * (x - centre);
        }
        int secondSideSecondPower = y * y;
        int thirdSideSecondPower = firstSideSecondPower + secondSideSecondPower;
        if (thirdSideSecondPower < smallRadius * smallRadius)
        {
            cout << "Black" << endl;
        }
        else if (thirdSideSecondPower > smallRadius * smallRadius)
        {
            cout << "White" << endl;
        }
        else
        {
            cout << "Undefined" << endl;
        }
        
    }
    else if ((x > -4 && x < 0) && (y > 0 && y < 4))//2nd quadrant
    {
        smallRadius = 1;
        bigRadius = 2;
        centre = -2;

        int firstSideSecondPower = (x - centre) * (x - centre);
        int secondSideSecondPower = y * y;
        int thirdSideSecondPower = firstSideSecondPower + secondSideSecondPower;

        if (thirdSideSecondPower > smallRadius * smallRadius &&
            thirdSideSecondPower < bigRadius * bigRadius)
        {
            cout << "Black" << endl;
        }
        else if (thirdSideSecondPower<smallRadius * smallRadius ||
            thirdSideSecondPower>bigRadius * bigRadius)
        {
            cout << "White" << endl;
        }
        else
        {
            cout << "Undefined" << endl;
        }
       
    }
    else if ((x > -4 && x < 0) && (y > -4 && y < 0))//3rd quadrant
    {
        if (x * x + y * y >= wholeCircleRadius * wholeCircleRadius)
        {
            cout << "White" << endl;
        }
        else 
        {
            smallRadius = 1;
            centre = -2;

            int firstSideSecondPower = (x - centre) * (x - centre);
            int secondSideSecondPower = y * y;
            int thirdSideSecondPower = firstSideSecondPower + secondSideSecondPower;

            if (thirdSideSecondPower < smallRadius * smallRadius)
            {
                cout << "White" << endl;
            }
            else if (thirdSideSecondPower > smallRadius * smallRadius)
            {
                cout << "Black" << endl;
            }
            else
            {
                cout << "Undefined" << endl;
            }

        }
        
    }
    else if ((x > 0 && x < 4) && (y > -4 && y < 0))//4th quadrant
    {
        if (x * x + y * y >= wholeCircleRadius * wholeCircleRadius)
        {
            cout << "White" << endl;
        }
        else
        {
            smallRadius = 1;
            bigRadius = 2;
            centre = 2;
            int firstSideSecondPower;
            if (x <= centre)
            {
                firstSideSecondPower = (centre - x) * (centre - x);

            }
            else
            {
                firstSideSecondPower = (x - centre) * (x - centre);
            }
            int secondSideSecondPower = y * y;
            int thirdSideSecondPower = firstSideSecondPower + secondSideSecondPower;

            if (thirdSideSecondPower > smallRadius * smallRadius &&
                thirdSideSecondPower < bigRadius * bigRadius)
            {
                cout << "White" << endl;
            }
            else if (thirdSideSecondPower<smallRadius * smallRadius ||
                thirdSideSecondPower>bigRadius * bigRadius)
            {
                cout << "Black" << endl;
            }
            else
            {
                cout << "Undefined" << endl;
            }
        }

    }
    else if ((x > 4 || x < -4) || (y > 4 || y < -4))
    {
        cout << "Outside" << endl;
    }
    else if (x == 4 || x == -4 || x == 0 ||
         y == 4 || y == -4 || y == 0)
    {
        cout << "Undefined" << endl;
    }
}
