#include <iostream>
using namespace std;

class Donar
{
    private:
        string name;
        string bloodGroup;

    public:

    static int totalDonors;
        
    void AddDonar()
        {
            cout<<"Enter donor's name: ";
            getline(cin, name);
            cin.ignore(); // To ignore the newline character after age input
            cout<<"Enter donor's blood group: ";
            getline(cin, bloodGroup);
            totalDonors++;
        }
    
    void displayDetails()
        {
            cout<<"\nDonor Details:\n";
            cout<<"Name: "<<name<<endl;
            cout<<"Blood Group: "<<bloodGroup<<endl;
        }

        string getBloodGroup()
        {
            return bloodGroup;
        }
        string getName()
        {
            return name;
        }
};