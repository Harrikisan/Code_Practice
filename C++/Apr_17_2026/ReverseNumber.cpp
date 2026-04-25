#include <iostream>
using namespace std;

int ReverseNumber(int num)
{
    int reversedNum = 0;

    while (num != 0)
    {
        int digit = num % 10;
        reversedNum = reversedNum * 10 + digit;
        num /= 10;
    }

    return reversedNum;
}

int main()
{
    int num, reversedNum = 0;

    cout << "Enter an integer: ";
    cin >> num;

    reversedNum = ReverseNumber(num);
    
    cout << "Reversed number: " << reversedNum << endl;

    return 0;
}