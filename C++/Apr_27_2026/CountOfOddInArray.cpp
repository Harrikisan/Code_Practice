#include <iostream>
using namespace std;

void countOfOddInArray(int arr[],int size){
    int count = 0;
    for(int i=0; i<size; i++){
        if(arr[i] % 2 != 0){
            count++;
        }
    }
    cout<<"The number of odd elements in the array is: "<<count<<endl;
}

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cout<<"Enter element "<<i+1<<": ";
        cin>>arr[i];
    }
    countOfOddInArray(arr, n);
    return 0;
}
    
