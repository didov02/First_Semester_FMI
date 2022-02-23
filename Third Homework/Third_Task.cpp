#include <iostream>
using namespace std;

int main()
{
    int a, b, maxPasswords;
    cin >> a;
    cin >> b;
    cin >> maxPasswords;
    int passwordsCounter = 0;

    char A = (char)35;
    char B = (char)64;
    int x = 0;
    int y = 0;

    for (int i = 1; i <= a; i++)
    {
        x = i;
        for (int j = 1; j <= b; j++)
        {
            if (passwordsCounter >= maxPasswords)
            {
                return -1;
            }

            y = j;
            cout << A << B << x << y << B << A << "|";

            if (A > 55)
            {
                A = 35;
            }
            if (B > 96)
            {
                B = 64;
            }

            passwordsCounter++;
            A++;
            B++;
        }
    }

    return 0;
}
