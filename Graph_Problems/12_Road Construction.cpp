#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>parent;
vector<ll>ranks;
 
 
ll find(ll node){
    if(node == parent[node]){
        return node;
    }
 
    return parent[node] = find(parent[node]);
}
 
void Unionset(ll node1, ll node2, vector<ll>& size){
 
    ll parent_node1 = find(node1);
    ll parent_node2 = find(node2);
 
    if(parent_node1 == parent_node2){
        return;
    }
 
    else if(ranks[parent_node1] > ranks[parent_node2]){
        parent[parent_node2] = parent_node1;
        size[parent_node1] += size[parent_node2];  //as parent_node1 is thw new parent, we need to add the size of parent_node2 to parent_node1 as it has been now merged into parent_node1
    }
 
    else if(ranks[parent_node1] < ranks[parent_node2]){
        parent[parent_node1] = parent_node2;
        size[parent_node2] += size[parent_node1];  //as parent_node2 is thw new parent, we need to add the size of parent_node1 to parent_node2 as it has been now merged into parent_node2
    }
 
    else{
        parent[parent_node2] = parent_node1;
        ranks[parent_node1]++;
        size[parent_node1] += size[parent_node2];
    }
}
int main() {
    ll n,m;
    cin>>n>>m;
 
    parent.resize(n+1);
    ranks.resize(n+1,0);
 
    for(ll i=1;i<=n;i++){
        parent[i] = i;  //initially every node is a parent of itself, or belongs to it's own independent component
    }
 
    ll maxSize = 1;
    ll componentCount = n; //initiall every node is an independent component
    vector<ll>size(n+1,1); //to keep a track of component size
 
    for(ll i=0;i<m;i++){
        ll city1,city2;
        cin>>city1>>city2;
 
        ll parent_city1 = find(city1);
        ll parent_city2 = find(city2);
 
        if(parent_city1 != parent_city2){
            Unionset(city1, city2, size);
            componentCount--;   //as city1 and city2 are now merged into one component
            ll newParent = find(city1);  //finding the new parent of the merged component
            maxSize = max(maxSize, size[newParent]);  //updating maxsize every time we merge two components
        }
 
        cout<<componentCount<<" "<<maxSize<<endl;
    }
 
    return 0;
 
}