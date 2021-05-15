#include<bits/stdc++.h>
using namespace std;


int main(){
    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(3);

    for(auto i:v) cout<<i<<endl;

    vector<int> v2(3,322);
    for(auto i:v2) cout<<i<<endl;

    sort(v.begin(), v.end());
    for(auto i:v) cout<<i<<endl;

    return 0;
}