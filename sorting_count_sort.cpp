#include<bits/stdc++.h>
using namespace std;

void countSort(int arr[],int n){
    int k=arr[0];
    for(int i=1;i<n;i++){
        k=max(k,arr[i]);        
    }    
    vector<int> count(k+1,0);    
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }
    for(int i=1;i<=k;i++){
        count[i]+=count[i-1];
    }
    int output[n];
    for(int i=n-1;i>=0;i--){
        output[--count[arr[i]]]=arr[i];
    }
    for(int i=0;i<n;i++){
        arr[i]=output[i];
    }
}


int main(){
    int a[]={10,16,7,14,5,3,12,9};
    countSort(a,8);
    for(int i=0;i<8; i++) cout<<a[i]<<" ";

    return 0;
}