#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    cin.ignore();
    char arr[n+1];
    cin.getline(arr,n);
    cin.ignore();

    int i=0;
    int currLength = 0,maxLength=0;
    int st=0,maxst=0;
    while(1){

        if(arr[i]==' ' || arr[i]=='\0'){
            if(currLength>maxLength){
                maxLength = currLength;
                maxst = st;
            }
            currLength=0;
            st=i+1;
        }else{
            currLength++;
        }

        if(arr[i]=='\0') break;
        i++;
    }
    
    cout<<"Max length is "<<maxLength<<endl;
    for(int i=0;i<maxLength;i++){
        cout<<arr[i+maxst];
    }

    return 0;

}