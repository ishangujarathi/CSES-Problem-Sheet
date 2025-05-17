#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
bool static comparator(vector<ll>&v1, vector<ll>&v2){
    return v1[2] < v2[2];
}
 
vector<ll>parent;
vector<ll>ranks;
 
ll find(ll node){
    if(node == parent[node]){
        return node;
    }
    return parent[node] = find(parent[node]);
}
 
void unionSet(ll u, ll v){
    ll parent_u = find(u);
    ll parent_v = find(v);
 
    if(parent_u == parent_v){
        return;
    }
 
    else if(ranks[parent_u] > ranks[parent_v]){
        parent[parent_v] = parent_u;
    }
 
    else if(ranks[parent_v] > ranks[parent_u]){
        parent[parent_u] = parent_v;
    }
 
    else{
        parent[parent_v] = parent_u;
        ranks[parent_u]++;
    }
}
ll kruskal(vector<vector<ll>>&adj, ll& n){
    ll mincost = 0;
    ll edgescount = 0;
    for(auto& it:adj){
        ll city1 = it[0];
        ll city2 = it[1];
        ll cost = it[2];
 
        ll parent_city1 = find(city1);
        ll parent_city2 = find(city2);
 
        if(parent_city1 != parent_city2){
            unionSet(city1,city2);
            mincost += cost;
            edgescount++;
        }
    }
 
    if(edgescount != n-1){
        return -1;
    }
 
    return mincost;
}
int main() {
    ll n,m;
    cin>>n>>m;
 
    vector<vector<ll>>adj;
    parent.resize(n+1);
    ranks.resize(n+1,0);
 
    for(ll i=1;i<=n;i++){
        parent[i] = i;
    }
 
    for(ll i=0;i<m;i++){
        ll city1,city2,cost;
        cin>>city1>>city2>>cost;
        adj.push_back({city1,city2,cost});
    }
 
    sort(adj.begin(),adj.end(),comparator);
 
    ll result = kruskal(adj,n);
    if(result == -1){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        cout<<result<<endl;
    }
 
}
