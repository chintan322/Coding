#include<bits/stdc++.h>
using namespace std;

class student{
    public:
    string name;
    int age;
    bool gender;

    void printInfo(){
        cout<<"Name : "<<name<<endl<<"Age : "<<age<<endl<<"Gender is : "<<gender<<endl;
        
    }
};

int main(){

    student arr[3];
    for(int i=0;i<3;i++){
        cin>>arr[i].name>>arr[i].age>>arr[i].gender;        
    }

    for(int i=0;i<3;i++){
        arr[i].printInfo();
    }

    return 0;
}