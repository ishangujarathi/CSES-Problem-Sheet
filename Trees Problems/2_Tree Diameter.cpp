#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n;
    cin>>n;

    vector<vector<ll>>tree(n+1);
    for(ll i=1;i<=n;i++){
        ll node1, node2;
        cin>>node1>>node2;
        tree[node1].push_back(node2);
        tree[node2].push_back(node1);
    }
    

}