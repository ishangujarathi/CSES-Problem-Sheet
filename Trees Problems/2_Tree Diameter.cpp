#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
pair<int,int>findFarthestNode(int sourceNode, vector<vector<ll>>&tree, ll n){
    queue<pair<ll,ll>>q; //{node,distance};
    vector<bool>vis(n+1,false);
    q.push({sourceNode, 0});
    vis[sourceNode] = true;
    int farthestNode = sourceNode;
    int diameter = 0;
    while(!q.empty()){
        int curnode = q.front().first;
        int curdist = q.front().second;
        q.pop();
 
        farthestNode = curnode;
        diameter = curdist;
 
        for(auto& it:tree[curnode]){
            if(!vis[it]){
                vis[it] = true;
                q.push({it,curdist+1});
            }
        }
    }
    return {farthestNode, diameter};
}
int findTreeDiameter(ll n, vector<vector<ll>>&tree){
    auto [farthestNode,__] = findFarthestNode(1,tree,n);
    auto [_,diameter] = findFarthestNode(farthestNode, tree, n);
    return diameter;
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
 
    ll diameter = findTreeDiameter(n, tree);
    cout << diameter << endl;
    return 0;
}