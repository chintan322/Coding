// Given an array a[] of size n. For every i from 0 to n-1 output max(a[0], a[1],..., a[i]).

#include <iostream>
#include <math.h>
#include <climits>
using namespace std;


int main(){
    int mx=INT_MIN;
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];    
    }

    for(int i=0;i<n;i++){
        mx=max(mx,arr[i]);
        cout<<mx<<" ";
    }


    return 0;

}