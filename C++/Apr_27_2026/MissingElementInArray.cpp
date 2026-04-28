#include <iostream>
using namespace std;

int main(){
    int arr[5]={1,3,5,2,0};
    int sum=0;
    int min,max;
    for (int i=0;i<5;i++){
        sum+=arr[i];
        for(int j=0;j<5;j++){
            if(arr[j]<min){
                min=arr[j];
            }
            if(arr[j]>max){
                max=arr[j];
            }
        }
    }
    int expectedsum=0;
    for(int i=min;i<=max;i++){
        expectedsum+=i;
    }
    int missingElement=expectedsum-sum;
    cout<<"The missing element in the array is: "<<missingElement  <<endl;
}