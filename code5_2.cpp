#include <iostream>
// #include <cmath>
#include <math.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    // Code for Prime or NonPrime
    // bool flag=0;
    // for(int i=2; i<=sqrt(n);i++){
    //     if(n%i==0){
    //         cout<<"Non Prime"<<endl;
    //         flag=1;
    //         break;
    //     }
    // }
    // if(!flag){
    //     cout<<"Prime"<<endl;
    // }


    // Reverse the number
    // int reverse=0;
    // while(n>0){
    //     int last = n%10;
    //     reverse = reverse*10+ last;
    //     n/=10;
    // }
    // cout<<reverse<<endl;

    int copy=n;
    int sum=0;
    while(n>0){
        int last = n%10;        

        cout<<sum<<" "<<pow(last,3)<<endl;
        sum=sum + pow(last,3);
        cout<<sum<<endl<<endl;
        n=n/10;
    }
    cout<<sum<<" "<<copy<<endl;
    if(copy==sum){
        cout<<"Armstrong number"<<endl;
    }else{
        cout<<"NO"<<endl;
    }

    return 0;

}