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

const int N = 1e5+2, MOD = 1e9+7;

// int friends(int n){
//     if(n==0) return 0;
//     if(n == 1){
//         return 1;
//     }
//     return friends(n-1) + ((n-1) * friends(n-2));
// }

int main(){
    

    int n;
    cin>>n;

    vi dp(n+1,1);

    dp[0] = 1;
    dp[1] = 1;
    rep(i,2,n+1){
        dp[i] = dp[i-1] + (i-1)*dp[i-2];
    }
    cout<<dp[n];


    // cout<<friends(n)<<endl;
    return 0;
}