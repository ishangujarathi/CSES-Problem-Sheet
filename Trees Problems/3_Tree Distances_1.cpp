#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
pair<ll,vector<ll>> findFarthestNode(ll node, vector<vector<ll>>&tree, ll n){
    queue<ll>q;
    q.push(node);
 
    vector<ll>dist(n+1,-1);
    dist[node] = 0;
    ll farthestNode = node;
    while(!q.empty()){
        ll curnode = q.front();
        q.pop();
 
        farthestNode = curnode;
 
        for(auto& it:tree[curnode]){
            if(dist[it] == -1){
                dist[it] = dist[curnode] + 1;
                q.push(it);
            }
        }
    }
 
    return {farthestNode,dist};
}
 
int main() {
    ll n;
    cin>>n;
 
    vector<vector<ll>>tree(n+1);
    for(ll i=1;i<n;i++){
        ll node1,node2;
        cin>>node1>>node2;
        tree[node1].push_back(node2);
        tree[node2].push_back(node1);
    }
 
    auto[farthestNodeA, distA] = findFarthestNode(1,tree,n); //used to find farthest node (one end of the diameter) from node 1 and distA stores minimum distance of all other nodes from node 1
    auto[farthestNodeB, distB] = findFarthestNode(farthestNodeA,tree,n);  //used to find other end of the diameter from previously found other end of the diameter and distB stores minimum distance of all nodes from previously found one end of the diameter
    auto [_, distC] = findFarthestNode(farthestNodeB, tree, n); //used to find minimum distance from the other end of the diameter found in 2nd BFS call and dist C stores minimum distance of all nodes from that end of the diameter
 
    for(ll i=1;i<=n;i++){
        cout<<max(distB[i],distC[i])<<endl;  //since we have to find for each node the maximum distance to all other nodes, so maximum distance from each node is to either ends of the diameter so returning max(distB[i],distC[i]);
    }
    return 0;
}