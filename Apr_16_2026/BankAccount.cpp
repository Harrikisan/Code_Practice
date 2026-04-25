#include <iostream>
using namespace std;

class BankAccount
{
private:
    string accNumber;
    double balance;

public:
    static int totalAccounts;

    BankAccount() : accNumber(""), balance(0) {}

    BankAccount(string accNumber, double balance)
    {
        this->accNumber = accNumber;
        this->balance = balance;

        cout << "Account Number: " << accNumber << ", Balance: " << balance << endl;
        totalAccounts++;
    }

    void Deposit()
    {
        cout << "Enter amount to deposit: ";
        double amount;
        cin >> amount;
        balance += amount;
        cout << "Deposited: " << amount << ", New Balance: " << balance << endl;
    }

    void getBalance()
    {
        cout << "Current Balance: " << balance << endl;
    }

    string getAccountNumber()
    {
        return accNumber;
    }
};

int BankAccount::totalAccounts = 0;

int main()
{
    cout << "Welcome to the Bank Account Management System!" << endl;

    BankAccount accounts[100];

    while (true)
    {
        int choice;
        cout << "\n1: Create account\n2: Deposit\n3: Check balance\n4: Total accounts\n5: Exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string accNumber;
            double balance;

            cout << "Enter account number: ";
            cin >> accNumber;

            cout << "Enter initial balance: ";
            cin >> balance;

            accounts[BankAccount::totalAccounts] = BankAccount(accNumber, balance);
            break;
        }

        case 2:
        {
            string accNum;
            cout << "Enter account number: ";
            cin >> accNum;

            for (int i = 0; i < BankAccount::totalAccounts; i++)
            {
                if (accounts[i].getAccountNumber() == accNum)
                {
                    accounts[i].Deposit();
                    break;
                }
            }
            break;
        }

        case 3:
        {
            string accNum;
            cout << "Enter account number: ";
            cin >> accNum;

            for (int i = 0; i < BankAccount::totalAccounts; i++)
            {
                if (accounts[i].getAccountNumber() == accNum)
                {
                    accounts[i].getBalance();
                    break;
                }
            }
            break;
        }

        case 4:
        {
            cout << "Total accounts: " << BankAccount::totalAccounts << endl;
            break;
        }

        case 5:
            return 0;

        default:
            cout << "Invalid choice\n";
        }
    }
}