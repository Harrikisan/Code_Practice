#include <iostream>
using namespace std;

int main()
{
    // Array declaration and initialization without size
    int arr1[]={1,2,3,4,5};
    
    //Array declaration and initialization with size
    int n;
    cout<< "Enter the size of the array: ";
    cin>>n;
    int arr2[n];

    // Taking input for the array using cin
    for(int i=0; i<n; i++)
    {
        cout<<"Enter element "<<i+1<<": ";
        cin>>arr2[i];
    }

    // Printing the elements of the array
    cout<<"The elements in the array are: ";
    for(int i=0; i<n; i++)
    {
        cout<<arr2[i]<<" ";
    }


    //Printing sum of the elements in the array
    int sum=0;
    for(int i=0; i<n; i++)
    {
        sum+=arr2[i];
    }
    cout<<"\nSum of the elements in the array: "<<sum;

    //Reversing the array
    cout<<"\nReversed array: ";
    for(int i=n-1; i>=0; i--)
    {
        cout<<arr2[i]<<" ";
    }

    //count even and odd numbers in the array
    int evenCount=0, oddCount=0;
    for(int i=0; i<n; i++)
    {
        if(arr2[i]%2==0)
            evenCount++;
        else
            oddCount++;
    }
    cout<<"\nEven numbers in the array: "<<evenCount;
    cout<<"\nOdd numbers in the array: "<<oddCount;

    //Finding an element in the array
    int num;
    cout<<"\nEnter an element to search in the array: ";
    cin>>num;

    for(int i=0; i<n; i++)
    {
        if(arr2[i]==num)
        {
            cout<<"Element found at index: "<<i;
            break;
        }
        if(i==n-1)
            cout<<"Element not found in the array.";
    }

    return 0;
}