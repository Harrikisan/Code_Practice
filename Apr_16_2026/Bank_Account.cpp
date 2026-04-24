#include <iostream>
using namespace std;

int accounts = 0;

class BankAccount
{
public:
    int accountNumber;
    int balance;

    BankAccount() {}
    BankAccount(int accNum, int bal) : accountNumber(accNum), balance(bal)
    {
        cout << "Bank account created with account number: " << accountNumber << " and initial balance: " << balance << endl;
        accounts++;
    }
    void deposit(int accnum, int amount)
    {
        this->balance += amount;
        cout << "Deposited " << amount << " to account number " << accnum << ". New balance: " << balance << endl;
    }
};

int main()
{
    BankAccount acc[100];
    cout << "Welcome to the Bank Account Management System!" << endl;
    while (true)
    {
        cout << "\n1. Create a new bank account" << endl;
        cout << "2. Deposit money into an account" << endl;
        cout << "3. Exit" << endl;
        cout << "Please select an option: ";
        int choice;
        cin >> choice;

        if (choice == 1)
        {
            int accNum, bal;
            cout << "Enter account number: ";
            cin >> accNum;
            cout << "Enter initial balance: ";
            cin >> bal;
            acc[accounts] = BankAccount(accNum, bal);
            accounts++;
            cout << "Account created successfully!" << endl;
        }
        else if (choice == 2)
        {
            int accNum, amount;
            cout << "Enter account number: ";
            cin >> accNum;
            for (int i = 0; i < accounts; i++)
            {
                if (acc[i].accountNumber == accNum)
                {
                    cout << "Enter amount to deposit: ";
                    cin >> amount;
                    acc[i].deposit(accNum, amount);
                    cout << "Deposit successful!" << endl;
                    break;
                }
                else if (i == accounts - 1)
                {
                    cout << "Account not found. Please try again." << endl;
                }
            }
        }
        else if (choice == 3)
        {
            cout << "Thank you for using the Bank Account Management System. Goodbye!" << endl;
            break;
        }
        else
        {
            cout << "Invalid option. Please try again." << endl;
        }
    }
}