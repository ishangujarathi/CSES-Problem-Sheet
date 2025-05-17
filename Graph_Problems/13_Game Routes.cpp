#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9 + 7;
 
int main() {
    ll n,m;
    cin>>n>>m;
 
    vector<vector<ll>>adj(n+1);
    vector<ll>indegree(n+1,0);
    for(ll i=0;i<m;i++){
        ll city1, city2;
        cin>>city1>>city2;
        adj[city1].push_back(city2);
        indegree[city2]++;
    }
 
    queue<ll>q;
    for(ll i=1;i<=n;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
 
    vector<ll>topoSort;
    while(!q.empty()){
        ll node = q.front();
        q.pop();
        topoSort.push_back(node);
 
        for(auto& it:adj[node]){
            indegree[it]--;
            if(indegree[it] == 0){
                q.push(it);
            }
        }
    }
 
    vector<ll>dp(n+1,0); //dp[v] = indicates the number of routes/ways to reach node v from node 1(source)
    dp[1] = 1; //one way to reach node 1 from node 1;
 
    for(auto& node:topoSort){
        for(auto& v:adj[node]){
            dp[v] = (dp[v] + dp[node]) % mod;
        }
    }
 
    cout<<dp[n]<<endl;
    return 0;
}
