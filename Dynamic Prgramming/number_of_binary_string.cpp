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
    vi fib(n+2,0);
    fib[0] = 1;
    fib[1] = 1;
    rep(i,2,n+2){
        fib[i] = fib[i-1] + fib[i-2];
    }
    cout<<fib[n+1]<<endl;

    return 0;
}