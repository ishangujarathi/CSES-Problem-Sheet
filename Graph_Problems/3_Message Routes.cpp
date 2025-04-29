#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool BFS(int source, unordered_map<ll,vector<ll>>&adj, vector<ll>&route, ll n){
    queue<ll>q;
    vector<bool>vis(n+1,false);
    vector<ll>parent(n+1,-1);
    q.push(source);
    vis[source] = true;
    while(!q.empty()){
        ll node = q.front();
        q.pop();

        if(node == n){
            while(node != -1){
                route.push_back(node);
                node = parent[node];
            }
            reverse(route.begin(),route.end());
            return true;
        }

        for(auto& it:adj[node]){
            if(!vis[it]){
                q.push(it);
                vis[it] = true;
                parent[it] = node;
            }
        }
    }
    return false;
}
int main(){
    ll n,m;
    cin>>n>>m;
    unordered_map<ll,vector<ll>>adj;
    for(ll i=0;i<m;i++){
        ll node1,node2;
        cin>>node1>>node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }


    vector<ll>route;
    if(BFS(1,adj,route,n)){   //in unweighted graph, BFS will always give the shortest path from source to target node
        cout<<route.size()<<endl;
        for(auto& r:route){
            cout<<r<<" ";
        }
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;

}