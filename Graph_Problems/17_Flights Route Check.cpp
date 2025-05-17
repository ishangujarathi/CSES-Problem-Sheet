#include<bits/stdc++.h>
using namespace std;
#define ll long long    
//This is a standard problem of implementing Kosaraju's Algorithm, to check whether the graph is strongly connected component or not and if yes to calculate the number of strongly connected components.
//Strongly Connected Components are the maximal subgraphs such that every vertex is reachable from every other vertex in the subgraph.
 
//3 Simple Steps of Kosaraju's Algorithm:
//1- Firstly we need to have a proper topological sorting order of the graph, which can be done using DFS traversal.
//2 - Secondly we need to reverse all the edges of the graph and construct a new graph with all reversed edges.
//3 - Lastly we need to do a DFS traversal on the reversed graph in the order of the topological sorting order we got in step 1. The number of times we do a DFS traversal on the reversed graph will give us the number of strongly connected components.
void DFStopoSort(ll node, vector<vector<ll>>&adj, vector<bool>&vis, stack<ll>&st){
    vis[node] = true;
 
    for(auto& it:adj[node]){
        if(!vis[it]){
            DFStopoSort(it,adj,vis,st);
        }
    }
 
    st.push(node);
}
 
void DFStraversal(ll node, vector<vector<ll>>&revadj, vector<bool>&vis2){
    vis2[node] = true;
 
    for(auto& it:revadj[node]){
        if(!vis2[it]){
            DFStraversal(it,revadj,vis2);
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
 
    stack<ll>st;
    vector<bool>vis(n+1,false);
    for(ll i=1;i<=n;i++){
        if(!vis[i]){
            DFStopoSort(i,adj,vis,st);
        }
    }
 
    vector<vector<ll>>revadj(n+1);
    for(ll node=1;node<=n;node++){
        for(auto& it:adj[node]){
            revadj[it].push_back(node);
        }
    }
 
    ll stronglyConnectedComponents = 0;
    vector<ll>nodes;
    vector<bool>vis2(n+1,false);
 
    while(!st.empty()){
        ll node = st.top();
        st.pop();
 
        if(!vis2[node]){
            DFStraversal(node,revadj,vis2);
            stronglyConnectedComponents++;
            nodes.push_back(node);
        }
    }
 
    if(stronglyConnectedComponents == 1){   //this indiacated entire graph is strongly connected component and we can go from any vertex to any other vertex
        cout<<"YES"<<endl;
    }
    else{ 
         cout<<"NO"<<endl;     //graph is not strongly connected component
         if (nodes.size() >= 2){
            cout << nodes[1] << " " << nodes[0] << endl;
         }     
    }
 
    return 0;
}