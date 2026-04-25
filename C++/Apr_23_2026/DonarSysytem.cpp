#include <iostream>
using namespace std;

#define MAX_DONORS 100

class Donar {
private:
    string name;
    string bloodGroup;

public:
    static int totalDonors;

    void AddDonar() {
        cout << "Enter donor's name: ";
        getline(cin, name);

        cout << "Enter donor's blood group: ";
        getline(cin, bloodGroup);

        totalDonors++;
    }

    void displayDetails() {
        cout << "\nDonor Details:\n";
        cout << "Name: " << name << endl;
        cout << "Blood Group: " << bloodGroup << endl;
    }

    string getBloodGroup() {
        return bloodGroup;
    }

    string getName() {
        return name;
    }
};

int Donar::totalDonors = 0;

class BloodBank {
public:
    string bloodGroup;
    int units;
    static int totalUnits;

    BloodBank() {}

    BloodBank(string bg, int u) {
        bloodGroup = bg;
        units = u;
        totalUnits += u;
    }
};

int BloodBank::totalUnits = 0;

Donar donors[MAX_DONORS];
BloodBank bloodBank[MAX_DONORS];

int bloodEntryCount = 0;

void getDonerWithSpecifiedBloodGroup(string bloodGroup) {
    cout << "Donors with blood group " << bloodGroup << ":\n";

    for (int i = 0; i < Donar::totalDonors; i++) {
        if (donors[i].getBloodGroup() == bloodGroup) {
            cout << "Name: " << donors[i].getName() << endl;
        }
    }
}

void DonateBlood() {
    string name;
    int units;

    cout << "Enter donor name: ";
    cin >> name;

    for (int i = 0; i < Donar::totalDonors; i++) {
        if (donors[i].getName() == name) {
            donors[i].displayDetails();

            cout << "Enter units of blood to donate: ";
            cin >> units;

            bloodBank[bloodEntryCount++] =
                BloodBank(donors[i].getBloodGroup(), units);

            cout << "Thank you for donating " << units << " units of blood.\n";
            return;
        }
    }

    cout << "Donor not found!\n";
}

void getBloodUnits(string bloodGroup, int unitsNeeded) {
    int availableUnits = 0;

    for (int i = 0; i < bloodEntryCount; i++) {
        if (bloodBank[i].bloodGroup == bloodGroup) {
            availableUnits += bloodBank[i].units;
        }
    }

    if (availableUnits >= unitsNeeded) {
        cout << "Blood is available. " << availableUnits << " units in stock.\n";
    } else {
        cout << "Blood is NOT available. Only "
             << availableUnits << " units in stock.\n";
    }
}

int main() {
    cout << "Welcome to the Blood Bank Management System\n";

    while (true) {
        cout << "\n1. Add Donor\n"
             << "2. Display Donor Details\n"
             << "3. Search Donor by Blood Group\n"
             << "4. Donate Blood\n"
             << "5. Get Total Units of Blood\n"
             << "6. Exit\n";

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                donors[Donar::totalDonors].AddDonar();
                break;

            case 2: {
                string name;
                cout << "Enter donor name: ";
                cin >> name;

                for (int i = 0; i < Donar::totalDonors; i++) {
                    if (donors[i].getName() == name) {
                        donors[i].displayDetails();
                        break;
                    }
                }
                break;
            }

            case 3: {
                string bloodGroup;
                cout << "Enter blood group: ";
                cin >> bloodGroup;

                getDonerWithSpecifiedBloodGroup(bloodGroup);
                break;
            }

            case 4:
                DonateBlood();
                break;

            case 5: {
                string bloodGroup;
                int units;

                cout << "Enter blood group needed: ";
                cin >> bloodGroup;

                cout << "Enter units needed: ";
                cin >> units;

                getBloodUnits(bloodGroup, units);
                break;
            }

            case 6:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }
}