#include<bits/stdc++.h>
using namespace std;


vector<int> stockspan(vector<int> prices){
    vector<int> ans;
    stack<pair<int,int>> st;
    int max_v=1;
    for(int i=0;i<prices.size();i++){
        int t=1;
        while(!st.empty() && st.top().first <= prices[i]){
            t+=st.top().second ;
            st.pop();
        }
        st.push(make_pair(prices[i],t));
        ans.push_back(t);
        max_v = max(max_v,t);
    }
    return ans;
}

int main(){
    vector<int> a = {100,80,60,70,60,75,85};
    vector<int> res = stockspan(a);
    for(auto i:res){
        cout<<i<<" ";
    }cout<<endl;
    return 0;
}