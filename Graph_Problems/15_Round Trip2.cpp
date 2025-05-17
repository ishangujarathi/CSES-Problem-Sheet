#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
bool isCycle(ll node, vector<vector<ll>>&adj, vector<bool>&vis, vector<bool>&inRec, vector<ll>&parent, vector<ll>&routes){
    vis[node] = true;
    inRec[node] = true;
 
    for(auto& it:adj[node]){
        if(!vis[it]){
            parent[it] = node;
            if(isCycle(it,adj,vis,inRec,parent,routes)){
                return true;
            }
        }
        else if(inRec[it]){
            ll cur_node = node;
            routes.push_back(it);
            while(cur_node != it){
                routes.push_back(cur_node);
                cur_node = parent[cur_node];
            }
            routes.push_back(it);
            reverse(routes.begin(),routes.end());
            return true;
        }
    }
 
    inRec[node] = false;
    return false;
}
int main() {
    ll n, m;
    cin>>n>>m;
 
    vector<vector<ll>>adj(n+1);
    for(ll i=0;i<m;i++){
        ll city1, city2;
        cin>>city1>>city2;
        adj[city1].push_back(city2);
    }
 
    vector<bool>vis(n+1,false);
    vector<bool>inRec(n+1,false);
    vector<ll>parent(n+1,-1);
    vector<ll>routes;
    for(ll i=1;i<=n;i++){
        if(!vis[i] && isCycle(i,adj,vis,inRec,parent,routes)){
            cout<<routes.size()<<endl;
            for(auto& route:routes){
                cout<<route<<" ";
            }
 
            cout<<endl;
            return 0;
        }
    }
 
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
   
}