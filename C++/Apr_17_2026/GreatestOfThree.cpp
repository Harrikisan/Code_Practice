#include <iostream>
using namespace std;

int GreatestOfThree(int a, int b, int c)
{
    if (a >= b && a >= c)
        return a;
    else if (b >= a && b >= c)
        return b;
    else
        return c;
}

int main()
{
    int num1, num2, num3;

    cout << "Enter three integers: ";
    cin >> num1 >> num2 >> num3;

    int greatest = GreatestOfThree(num1, num2, num3);
    
    cout << "The greatest number is: " << greatest << endl;

    return 0;
}