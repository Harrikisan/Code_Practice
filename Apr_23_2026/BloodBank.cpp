#include <iostream>
#include "Donar.cpp"
#include "main.cpp"
using namespace std;

class BloodBank
{
public:
    string bloodGroup;
    int units;
    static int totalUnits;

    BloodBank(string bg, int u): bloodGroup(bg), units(u)
    {
        totalUnits += u;
    }
};