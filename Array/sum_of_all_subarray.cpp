// Given an array a[] of size n. Output sum of each subarray of the given array.

#include <iostream>
#include <math.h>
#include <climits>
using namespace std;


int main(){    
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];    
    }

    int curr=0;
    for(int i=0;i<n;i++){
        curr=0;
        for(int j=i;j<n;j++){
            curr+=arr[j];
            cout<<curr<<endl;
        }
    }


    return 0;

}