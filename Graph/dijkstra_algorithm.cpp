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
const int inf = 1e7;

int main(){  
    int n,m;
    cin>>n>>m;
    vector<int> dist(n+1,inf);
    vector<vector<pair<int,int>>> graph(n+1);

    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }

    int source;
    cin>>source;
    dist[source] = 0;

    set<pair<int,int>> s;
    
    // {wt, vertex}
    s.insert({0,source});

    while(!s.empty()){
        auto x = *(s.begin());
        s.erase(x);
        for(auto it : graph[x.second]){
            if(dist[it.first] > dist[x.second] + it.second){
                // pair<int,int> pp = make_pair(dist[it.first],it.first);

                s.erase({dist[it.first],it.first});
                dist[it.first] = dist[x.second] + it.second;
                s.insert({dist[it.first],it.first});
            }
        }
    }
    for(int i = 1; i<=n;i++){
        if(dist[i] < inf){
            cout<<dist[i]<<" ";
        }else{
            cout<<-1<<" ";
        }
    }

    return 0;
}