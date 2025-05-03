#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
void dijkstra(ll source,   vector<vector<pair<ll,ll>>>&adj, vector<ll>&distance){
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>>pq;
    pq.push({0,source});
    distance[source] = 0;
    while(!pq.empty()){
        ll len = pq.top().first;
        ll city = pq.top().second;
        pq.pop();
 
        if(len > distance[city]){
            continue;
        }
 
        for(auto& it:adj[city]){
            ll nextcity = it.first;
            ll cost = it.second;
            if(distance[nextcity] > len + cost){
                distance[nextcity] = len + cost;
                pq.push({distance[nextcity], nextcity});
            }
        }
    }
 
}
int main() {
    ll n,m;
    cin>>n>>m;
 
    vector<vector<pair<ll,ll>>> adj(n + 1);
    for(ll i=0;i<m;i++){
        ll src,dest,len;
        cin>>src>>dest>>len;
        adj[src].push_back({dest,len});
    }
 
    vector<ll>distance(n+1,LLONG_MAX);
    dijkstra(1,adj,distance);
    for(ll city=1;city<=n;city++){
        cout<<distance[city]<<" ";
    }
    cout<<endl;
    return 0;
 
}