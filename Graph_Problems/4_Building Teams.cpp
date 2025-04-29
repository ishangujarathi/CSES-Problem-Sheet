#include<bits/stdc++.h>
using namespace std;
#define ll long long

//The below is a Classical Problem of Bipartite Graph

bool BFS(int source, unordered_map<ll,vector<ll>>&adj, vector<ll>&color){
    queue<ll>q;
    q.push(source);
    color[source] = 1;

    while(!q.empty()){
        ll node = q.front();
        q.pop();

        for(auto& it:adj[node]){
            if(color[it] == -1){
                color[it] = 3 - color[node];
                q.push(it);
            }
            else if(color[it] == color[node]){
                return false;
            }
        }
    }

    return true;
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

    vector<ll>color(n+1,-1);
    for(ll i=1;i<=n;i++){
        if(color[i] == -1){
            if(!BFS(i,adj,color)){
                cout<<"IMPOSSIBLE"<<endl;
                return 0;
            }
        }
    }

    for(ll i=1;i<=n;i++){
        cout<<color[i]<<" ";
    }
    cout<<endl;
    return 0;

}