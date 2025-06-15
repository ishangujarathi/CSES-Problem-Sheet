#include<bits/stdc++.h>
using namespace std;
#define ll long long

//This is a classic problme of Binary Lifting in Trees!!
//TC -> Pre-computation of parent vector/table = n*log(n) and for each query(q), binary_lift function takes O(logn), i.e qlog(n)
//Total TC = O(nlogn + qlogn) = (n+q)log(n);
//SC -> O(nlogn) for storing parent vector/table
       

ll binary_lift(ll node, ll k, vector<vector<ll>>&parent, ll log){
    for(ll i=0;i<log;i++){
        if(k & (1ll << i)){
            node = parent[node][i];
            if(node == 0){
                return -1;
            }
        }
    }
    return node;
}
int main() {
    ll n,q;
    cin>>n>>q;

    ll log = 0;
    while((1ll << log) <= n){
        log++;
    }

    vector<vector<ll>>parent(n+1,vector<ll>(log,0)); //parent[node][log] gives the ancestral node of [node] at 2^[log] levels above it
    for(ll i=2;i<=n;i++){
        cin>>parent[i][0]; //immediate parent/boss
    }

    for(ll i=1;i<log;i++){
        for(ll node=1;node<=n;node++){
            parent[node][i] = parent[parent[node][i-1]][i-1];
        }
    }

    while(q--){
        ll node,k;
        cin>>node>>k;
        cout<<binary_lift(node,k,parent,log)<<endl;
    }

    return 0;

}