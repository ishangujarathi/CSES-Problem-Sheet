#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF  = 1e18;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m,q;
    cin>>n>>m>>q;

    vector<vector<ll>> dist(n+1,vector<ll>(n+1,INF));
    for(ll i=1;i<=n;i++){
        dist[i][i] = 0;
    }

    for(ll i=0;i<m;i++){
        ll city1,city2,cost;
        cin>>city1>>city2>>cost;
        dist[city1][city2] = min(dist[city1][city2],cost);
        dist[city2][city1] = min(dist[city2][city1],cost);
    }


    for(ll k=1;k<=n;k++){
        for(ll row=1;row<=n;row++){
            for(ll col=1;col<=n;col++){
                if(dist[row][k] < INF && dist[k][col] < INF){
                    dist[row][col] = min(dist[row][col], dist[row][k] + dist[k][col]);
                }  
            }
        }
    }

    while(q--){
        ll city1,city2;
        cin>>city1>>city2;
        if(dist[city1][city2] == INF){
            cout<<-1<<endl;
        }
        else{
            cout<<dist[city1][city2]<<endl;
        }
    }
    return 0;
}
