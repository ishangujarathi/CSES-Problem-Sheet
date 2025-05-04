#include<bits/stdc++.h>
using namespace std;
#define ll long long

//Standard Topological Sorting Problem, which I solved using Kahn's Algorithms(BFS). Only applicable on Directed Acyclic Graphs!!

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m;
    cin>>n>>m;
    vector<vector<ll>>adj(n+1);
    vector<ll>indegree(n+1,0);
    for(ll i=0;i<m;i++){
        ll course1,course2;
        cin>>course1>>course2;
        adj[course1].push_back(course2);
        indegree[course2]++;
    }

    queue<ll>q;
    for(ll i=1;i<=n;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    vector<ll>toposort;
    while(!q.empty()){
        ll node = q.front();
        q.pop();
        toposort.push_back(node);

        for(auto& it:adj[node]){
            indegree[it]--;
            if(indegree[it] == 0){
                q.push(it);
            }
        }
    }

    if(toposort.size() != n){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        for(auto& it:toposort){
            cout<<it<<" ";
        }
    }

    cout<<endl;
    return 0;
}
