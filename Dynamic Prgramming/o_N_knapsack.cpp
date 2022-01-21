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
    int W;cin>>W;

    vi wt(n);
    vi val(n);
    rep(i,0,n){
        cin>>wt[i];
    }
    rep(i,0,n){
        cin>>val[i];
    }

    vi dp(W+1,0);

    rep(j,0,W+1){
        rep(i,0,n){
            if(j-wt[i] >= 0)
                dp[j] = max(dp[j], val[i] + dp[j-wt[i]]);
        }
    }
    cout<<dp[W];

    return 0;
}