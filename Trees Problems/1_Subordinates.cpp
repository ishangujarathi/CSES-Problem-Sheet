#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll DFS(ll curnode, vector<vector<ll>>&tree, vector<ll>&ans){
    ll count = 0;
    for(auto& child:tree[curnode]){
        count += 1 + DFS(child,tree,ans);
    }
    ans[curnode] = count;
    return count;
}
int main(){
    ll n;
    cin>>n;

    vector<vector<ll>>tree(n+1);
    for(ll i=2;i<=n;i++){
        ll boss;
        cin>>boss; 
        tree[boss].push_back(i);  //ith employee reports to the given boss
    }

    vector<ll>ans(n+1,0);
    DFS(1,tree,ans);
    for(ll i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }

    return 0;

}