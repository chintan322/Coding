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


vector<bool> vis;
vector<int> col;
bool bipart;

vvi adj;
vi components;

void color(int u, int curr){
    if(col[u] != -1 and col[u] !=curr){
        bipart = false;
        return;
    }
    col[u] = curr;
    if(vis[u])
        return;
    vis[u] = true;
    for(auto i:adj[u]){
        color(i,curr xor 1);
    }
}


int main(){
    bipart = true;
    int n,m;
    cin>>n>>m;
    adj = vvi(n);
    vis = vector<bool>(n,0);
    col=vi(n,-1);
    rep(i,0,m){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    rep(i,0,n){
        if(!vis[i]){
            color(i,0);
        }
    }
    if(bipart){
        cout<<"Graph is biparted"<<endl;
    }else{
        cout<<"Graph is not biparted"<<endl;
    }

    return 0;
}