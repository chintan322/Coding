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
vi a;

int dp[N][N];

int Solve(int i,int j){
    if(i==j) return a[i];
    if(i>j) return 0;
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int l = a[i] + min(Solve(i+2,j),Solve(i+1,j-1));
    // A[i...j], rem coins = A[i+1..j]
    int r = a[j] + min(Solve(i,j-2),Solve(i+1,j-1));
    dp[i][j] =  max(l,r);
    return dp[i][j];
}

int main(){
    rep(i,0,N){
        rep(j,0,N){
            dp[i][j] = -1;
        }
    }
    int n;cin>>n;
    a = vi(n);
    rep(i,0,n){
        cin>>a[i];
    }
    cout<<Solve(0,n-1);

    return 0;
}