#include<iostream>
using namespace std;

int Sum(int n){
    if(n==0) return 0;
    int prevSum = Sum(n-1);
    return n+prevSum;
}

int Power(int n,int p){
    if(p==0) return 1;
    return n*Power(n,p-1);
}

int Factorial(int n){
    if(n==0) return 1;
    return n*Factorial(n-1);
}

int main(){
    int n;
    cin>>n;
    // cout<<Sum(n);
    // cout<<Power(n,p);
    cout<<Factorial(n)<<endl;
    return 0;
}