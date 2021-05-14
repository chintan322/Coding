//  Find a unique number in array where all numbers except one, are present twice.

#include<iostream>
using namespace std;

int unique(int arr[],int n){
    int xorsum=0;
    for(int i=0;i<n;i++){
        xorsum=xorsum ^ arr[i];
    }
    return xorsum;
}

int getBit(int n,int pos){
    return ((n & (1<<pos))!=0);
}

void unique2num(int arr[],int n){
    int xorsum=0;
    for(int i=0;i<n;i++){
        xorsum=xorsum ^ arr[i];
    }
    int tempXor=xorsum;
    int setbit=0;
    int pos=0;
    while(setbit!=1){
        setbit = xorsum & 1;
        pos++;
        xorsum = xorsum >>1;
    }

    int newXor=0;
    for(int i=0;i<n;i++){        
        if(getBit(arr[i],pos-1)){
            newXor= newXor ^ arr[i];
        }
    }
    cout<<newXor<<endl;
    cout<<(tempXor^newXor)<<endl;

}

int setBit(int n,int pos){
    return (n | 1<<pos);
}

int unique3(int arr[],int n){
    int result=0;

    for(int i=0;i<64;i++){
        int sum=0;
        for(int j=0;j<n;j++){
            if(getBit(arr[j],i)){
                sum++;
            }
        }
        if(sum%3!=0){
            result = setBit(result,i);
        }
    }

    return result;
}




int main(){
    int arr[]={1,2,3,4,1,2,3,1,2,3};
    cout<<unique3(arr,10)<<endl;
    return 0;
}