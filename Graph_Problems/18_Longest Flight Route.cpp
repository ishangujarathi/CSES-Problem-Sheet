#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
void DFStopoSort(ll node, vector<vector<ll>>&adj, vector<bool>&vis, stack<ll>&st){
    vis[node] = true;
 
    for(auto& it:adj[node]){
        if(!vis[it]){
            DFStopoSort(it,adj,vis,st);
        }
    }
 
    st.push(node);
}
int main() {
    ll n,m;
    cin>>n>>m;
 
    vector<vector<ll>>adj(n+1);
    for(ll i=0;i<m;i++){
        ll city1,city2;
        cin>>city1>>city2;
        adj[city1].push_back(city2);
    }
 
    vector<bool>vis(n+1,false);
    stack<ll>st;
    for(ll city=1;city<=n;city++){
        if(!vis[city]){
            DFStopoSort(city,adj,vis,st);
        }
    }
 
    vector<ll>dist(n+1,LLONG_MIN);
    vector<ll>parent(n+1,-1);
    dist[1] = 0;
 
    while(!st.empty()){
        ll node = st.top();
        st.pop();
 
        if(dist[node] == LLONG_MIN){
            continue;
        }
 
        for(auto& it:adj[node]){
            if(dist[node] + 1 > dist[it]){
                dist[it] = dist[node] + 1;
                parent[it] = node;
            }
        }
    }
 
    if(dist[n] == LLONG_MIN){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        vector<ll>path;
        ll curnode = n;
        while(curnode != -1){
            path.push_back(curnode);
            curnode = parent[curnode];
        }
        reverse(path.begin(),path.end());
        cout<<path.size()<<endl;
        for(auto& it:path){
            cout<<it<<" ";
        }
        cout<<endl;
    }
 
    return 0;
 
}