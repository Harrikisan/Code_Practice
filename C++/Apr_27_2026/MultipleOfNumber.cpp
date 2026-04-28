#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    
    if(n%3 == 0) {
        cout << n << " is a multiple of 3." << endl;
    } else if (n%5 == 0) {
        cout << n << " is a multiple of 5." << endl;
    } else if (n%3 == 0 && n%5 == 0) {
        cout << n << " is a multiple of both 3 and 5." << endl;
    } else {
        cout << n << " is not a multiple of 3 or 5." << endl;
    }

    return 0;
}