#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define first
#define second
#define setBits(x) builtin_popcount(x)

const int N = 1e3+2, MOD = 1e9+7; 

int main(){
    int n;cin>>n;
    vi arr(n);
    for(auto &i:arr){
        cin>>i;
    }
    vi jumps(n,MOD);
    if(arr[0] == 0){
        cout<<MOD<<" ";
        return 0;
    }
    jumps[0] = 0;
    rep(i,1,n){
        rep(j,0,i){
            if(i <= (j + arr[j])){
                jumps[i] = min(jumps[i],jumps[j]+1);
            }
        }
    }
    cout<<jumps[n-1];


    return 0;
}