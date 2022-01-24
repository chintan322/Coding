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

int LCS(string &s1,string &s2,string &s3,int i,int j,int k) {

    if(i == 0 || j == 0 || k == 0) return 0;

    if(s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1]){
        return 1 + LCS(s1,s2,s3,i-1,j-1,k-1);
    }else{
        int l = LCS(s1,s2,s3,i-1,j,k);
        int r = LCS(s1,s2,s3,i,j-1,k-1);
        int p = LCS(s1,s2,s3,i,j,k-1);
        return max({l,r,p});
    }
}

int main(){
    

    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    cout<<LCS(s1,s2,s3,s1.size(),s2.size(),s3.size())<<endl;


    return 0;
}