#include<iostream>
using namespace std;

void Primesieve(int n){
    int prime[n+1]={0};
    for(int i=2;i<=n;i++){
        if(prime[i]==0){
            for(int j=i*i;j<=n;j+=i){
                prime[j] = 1;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(!prime[i]) cout<<i<<" ";
    }
}

void SmallestPrimesieve(int n){

    int spf[n+1]={0};    
    for(int i=2;i<=n;i++){
        spf[i] = i;
    }
    for(int i=2;i<=n;i++){
        if(spf[i]==i){
            for(int j=i*i;j<=n;j+=i){
                if(spf[j] == j){
                    spf[j] = i;
                }
            }
        }
    }
    while(n!=1){
        cout<<spf[n]<<" ";
        n=n/spf[n];
    }
}


int main(){
    int n;
    cin>>n;
    SmallestPrimesieve(n);
    return 0;
}