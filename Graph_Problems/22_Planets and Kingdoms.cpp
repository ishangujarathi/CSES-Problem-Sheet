#include<bits/stdc++.h>
using namespace std;
#define ll long long

void DFStopoSort(ll city,vector<vector<ll>>&adj, vector<bool>&vis, stack<ll>&st){
    vis[city] = true;

    for(auto& it:adj[city]){
        if(!vis[it]){
            DFStopoSort(it,adj,vis,st);       
        }
    }
    st.push(city);
}

void DFStraversal(ll city, vector<vector<ll>>&revadj, vector<bool>&vis2, ll& kingdomCount, vector<ll>&kingdoms){
    vis2[city] = true;
    kingdoms[city] = kingdomCount;

    for(auto &it:revadj[city]){
        if(!vis2[it]){
            DFStraversal(it,revadj,vis2, kingdomCount, kingdoms);
        }
    }

}
int main() {
    ll n,m;
    cin>>n>>m;

    vector<vector<ll>>adj(n+1);
    for(ll i=0;i<m;i++){
        ll city1, city2;
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

    vector<vector<ll>>revadj(n+1);
    for(ll city=1;city<=n;city++){
        for(auto& it:adj[city]){
            revadj[it].push_back(city);
        }
    }

    vector<bool>vis2(n+1,false);
    ll kingdomCount = 0;
    vector<ll>kingdoms(n+1,0);
    while(!st.empty()){
        ll node = st.top();
        st.pop();

        if(!vis2[node]){
            kingdomCount++;
            DFStraversal(node,revadj,vis2,kingdomCount,kingdoms);
        }
    }

    cout<<kingdomCount<<endl;
    for(ll i=1;i<=n;i++){
        cout<<kingdoms[i]<<" ";
    }

    return 0;
}