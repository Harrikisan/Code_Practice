#include <iostream>
#include "Donar.cpp"
#include "BloodBank.cpp"
using namespace std;

#define MAX_DONORS 100

int total=Donar::totalDonors;
int units=BloodBank::totalUnits;

BloodBank bloodBank[100];

void getDonerWithSpecifiedBloodGroup(string bloodGroup) {
    cout << "Donors with blood group " << bloodGroup << ":\n";
    for (int i = 0; i < total; i++) {
        if (donors[i].getBloodGroup() == bloodGroup) {
            cout << "Name: " << donors[i].getName() << endl;
        }
    }
}

void DonateBlood()
    {
        string name;
        int units;
        cout << "Enter donor name: ";
        cin >> name;
        for (int i = 0; i < total; i++)
        {
            if (donors[i].getName() == name)
            {
                donors[i].displayDetails();
                cout << "Enter units of blood to donate: ";
                cin >> units;
                cout << "Thank you for donating " << units << " units of blood.\n";
                bloodBank[total] = BloodBank(donors[i].getBloodGroup(), units);
                break;
            }
        }
    }

void getBloodUnits(string bloodGroup, int unitsNeeded)
    {
        int availableUnits = 0;
        for (int i = 0; i < total; i++)
        {
            if (bloodBank[i].bloodGroup == bloodGroup)
            {
                availableUnits += bloodBank[i].units;
            }
        }
        if (availableUnits >= unitsNeeded)
        {
            cout << "Blood is available. " << availableUnits << " units in stock.\n";
        }
        else
        {
            cout << "Blood is not available. Only " << availableUnits << " units in stock.\n";
        }
    }

int main(){

    Donar donors[MAX_DONORS];

    

    cout<<"Welcome to the Blood Bank Management System\n";
    while(true){
        cout<<"\n1. Add Donor\n2. Display Donor Details\n3. Search Donor by Blood Group\n4. Donate Blood\n5.Get Total Units of Blood\n7.Exit\n";
        int choice;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                donors[total].AddDonar();
                break;
            case 2:
                string name;
                cout<<"Enter doner name";
                cin>>name;
                for (int i = 0; i < total; i++) {
                    if (donors[i].getName() == name) {
                        donors[i].displayDetails();
                        break;
                   }
                }
                break;
            case 3:{
                string bloodGroup;
                cout<<"Enter blood group to search: ";
                getline(cin, bloodGroup);
                getDonerWithSpecifiedBloodGroup(bloodGroup);
                break;
            }
                
            case 4:{
                DonateBlood();
                break;
            }
                
            case 5:{
                string bloodGroup;
                int units;
                cout<<"Enter bloodgroup needed: \n";
                cin>>bloodGroup;
                cout<<"Enter number of units needed: \n";
                cin>>units;
                getBloodUnits(bloodGroup, units);
                break;
            }  
            default:
                cout<<"Invalid choice. Please try again.\n";
        }
    }
}