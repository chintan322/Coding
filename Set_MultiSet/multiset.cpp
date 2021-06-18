#include<bits/stdc++.h>
using namespace std;

int main(){
    multiset<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(3);
    s.insert(3);
    s.insert(3);
    for(auto i: s){
        cout <<i<<" ";
    }
    cout << endl;
    cout<<s.size()<<endl;
    // s.erase(3); // to delete all occurance of 3
    s.erase(s.find(3)); // to delete only one occurance of 3
    for(auto i: s){
        cout <<i<<" ";
    }
    return 0;
}