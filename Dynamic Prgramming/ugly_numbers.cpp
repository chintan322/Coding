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



int main(){
    

    int n;
    cin>>n;

    int c2(0),c3(0),c5(0);
    vi dp(n+1);
    dp[0] = 1;
    for(int i = 1;i<=n;i++){
        dp[i] = min({2*dp[c2], 3*dp[c3], 5*dp[c5]});
        if(2 * dp[c2] == dp[i])
            c2++;
        if(3 * dp[c3] == dp[i])
            c3++;
        if(5 * dp[c5] == dp[i])
            c5++;
    }
    cout<<dp[n-1]<<endl;

    return 0;
}