#include <iostream>
using namespace std;

int ArmstrongNumber(int num)
{
    int originalNum = num;
    int sum = 0;
    while (num != 0)
    {
        int digit = num % 10;
        sum += digit * digit * digit;
        num /= 10;
    }

    return sum == originalNum;
}

int main()
{
    int num;

    cout << "Enter an integer: ";
    cin >> num;

    if (ArmstrongNumber(num))
    {
        cout << num << " is an Armstrong number." << endl;
    }
    else
    {
        cout << num << " is not an Armstrong number." << endl;
    }

    return 0;
}