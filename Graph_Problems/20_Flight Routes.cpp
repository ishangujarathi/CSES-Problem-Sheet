#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n,m,k;
    cin>>n>>m>>k;

    vector<vector<pair<ll,ll>>>adj(n+1);
    for(ll i=0;i<m;i++){
        ll city1,city2,cost;
        cin>>city1>>city2>>cost;
        adj[city1].push_back({city2,cost});
    }

    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>, greater<pair<ll,ll>>>pq;
    pq.push({0,1});  //{cost, city}
    vector<vector<ll>>cost(n+1);  //index represents city, each index is a vector of costs to reach that city
    while(!pq.empty()){
        ll price = pq.top().first;
        ll city = pq.top().second;
        pq.pop();

        if(cost[city].size() == k){   //if we already have k costs, we don't need to push more costs for this city
            continue;
        }

        cost[city].push_back(price);

        for(auto& it:adj[city]){
            ll newPrice = price + it.second;
            ll newCity = it.first;
            pq.push({newPrice, newCity});
        }
    }
    for(auto& c:cost[n]){
        cout<<c<<endl;
    }
}
 
