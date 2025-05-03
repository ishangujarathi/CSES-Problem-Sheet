#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool isCycle(ll source, vector<vector<ll>>&adj,vector<bool>&vis,vector<ll>&parent,vector<ll>&route){
    vis[source] = true;
    for(auto& it:adj[source]){
        if(!vis[it]){
            vis[it] = true;
            parent[it] = source;
            if(isCycle(it,adj,vis,parent,route)){
                return true;
            }
        }
        else if(it != parent[source]){
            route.push_back(it);
            ll curnode = source;
            while(curnode != it){
                route.push_back(curnode);
                curnode = parent[curnode];
            }
            route.push_back(it);  //in order to complete the cycle
            reverse(route.begin(),route.end());
            return true;
        }
    }
    return false;
}
int main() {
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>>adj(n+1);
    for(ll i=0;i<m;i++){
        ll city1, city2;
        cin>>city1>>city2;
        adj[city1].push_back(city2);
        adj[city2].push_back(city1);
    }

    vector<bool>vis(n+1,false);
    vector<ll>parent(n+1,-1);

    vector<ll>route;
    for(ll city=1;city<=n;city++){
        if(!vis[city]){
            if(isCycle(city,adj,vis,parent,route)){
                cout<<route.size()<<endl;
                for(auto& it:route){
                    cout<<it<<" ";
                }
                cout<<endl;
                return 0;
            }
        }
    }

    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
