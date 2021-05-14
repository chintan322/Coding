#include<iostream>
using namespace std;

bool Sorted(int arr[],int n){    

    if(n==1) return true;
    bool restArray = Sorted(arr+1,n-1);
    return (arr[0]<arr[1] && restArray);
}

int main(){
    int arr[]={1,6,3,4,5};
    cout<<Sorted(arr,5)<<endl;
    return 0;
}