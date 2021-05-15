// Permutation from element from the array(duplicates allowed)
#include<bits/stdc++.h>
using namespace std;

void helper(vector<int> a, vector<vector<int>> &ans,int idx){
    if(idx == a.size()){
        ans.push_back(a);
        return;
    }
    for(int i=idx; i<a.size(); i++){
        if(i != idx and a[i] == a[idx]) continue;
        swap(a[i],a[idx]);
        helper(a,ans,idx+1);
    }
}

vector<vector<int>> permutation(vector<int> a){
    sort(a.begin(), a.end());
    vector<vector<int>> ans;
    helper(a,ans,0);
    return ans;
}


int main(){
    
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    vector<vector<int>> res = permutation(a);
    // sort(a.begin(), a.end());
    // do{
    //     ans.push_back(a);
    // }while(next_permutation(a.begin(),a.end()));
    for(auto v: res){
        for(auto i:v){
            cout<<i<<" ";
        }cout<<endl;
    }



    return 0;
}