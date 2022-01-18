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
vi parent(N);
vi sz(N);

void make_set(int v){
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v){
    if(v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a != b){
        if(sz[a] < sz[b])
            swap(a,b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}


int main(){
    rep(i,0,N){
        make_set(i);
    }

    int n,m;
    cin>>n>>m;

    vector<vector<int>> edges;

    rep(j,0,m){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({w,u,v});        
    }
    sort(edges.begin(), edges.end());

    int cost = 0;
    for(auto e:edges){
        int w = e[0];
        int u = e[1];
        int v = e[2];
        int x = find_set(u);
        int y = find_set(v);
        if(x == y){
            continue;
        }else{
            cout<<u<<" "<<v<<endl;
            cost += w;
            union_sets(u,v);
        }
    }

    cout<<cost<<endl;

    return 0;
}