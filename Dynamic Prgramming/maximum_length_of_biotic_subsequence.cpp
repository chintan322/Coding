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
    vi a(n);
    rep(i,0,n){
        cin>>a[i];
    }

    vi forward(n,1), backward(n,1);
    rep(i,1,n){
        rep(j,0,i){
            if(a[i] > a[j]){
                forward[i] = max(forward[i], 1+ forward[j]);
            }
        }
    }
    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>=i;j--){
            if(a[i] > a[j]){
                backward[i] = max(backward[i], 1+ backward[j]);
            }
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        ans = max(ans,forward[i] + backward[i] - 1);
    }
    cout<<ans<<endl;

    return 0;
}