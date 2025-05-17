#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9 + 7;
 
void dijkstra(ll source, vector<vector<pair<ll,ll>>>&adj,vector<ll>&cost,vector<ll>&count,vector<ll>&minFlights,vector<ll>&maxFlights){
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>>pq;
    pq.push({0,source}); //{cost, sourcenode}
    cost[source] = 0;
    count[source] = 1; //1 way to reach the source node
 
    while(!pq.empty()){
        ll price = pq.top().first;
        ll curcity = pq.top().second;
        pq.pop();
 
        if(price > cost[curcity]){
            continue;
        }
 
        for(auto& it:adj[curcity]){
            ll nextcity = it.first;
            ll nextprice = it.second;
            if(cost[nextcity] > price + nextprice){
                cost[nextcity] = price + nextprice;
                count[nextcity] = count[curcity];   //new shortest path found, so number of ways to reach next city will be equal to number of ways to reach curcity
                minFlights[nextcity] = minFlights[curcity] + 1;  //to reach nextcity, we need to traverse an edge(i.e take a flight) so flights/edges traversed till curcity + 1
                maxFlights[nextcity] = maxFlights[curcity] + 1;  //to reach nextcity, we need to traverse an edge(i.e take a flight) so flights/edges traversed till curcity + 1
                pq.push({cost[nextcity],nextcity});
            }
 
            else if(cost[nextcity] == price + nextprice){
                count[nextcity] = (count[nextcity] + count[curcity]) % mod;  //another route with same shortest cost found
                minFlights[nextcity] = min(minFlights[nextcity], minFlights[curcity] + 1);
                maxFlights[nextcity] = max(maxFlights[nextcity], maxFlights[curcity] + 1); 
            }
        }
    }
}
int main() {
    ll n,m;
    cin>>n>>m;
    
    vector<vector<pair<ll,ll>>>adj(n+1);
    for(ll i=0;i<m;i++){
        ll city1,city2,cost;
        cin>>city1>>city2>>cost;
        adj[city1].push_back({city2,cost});
    }
 
    vector<ll>cost(n+1,LLONG_MAX);
    vector<ll>count(n+1,0); //count to keep track of minimum cost routes, count[i] = number of minimum path routes to reach city i
    vector<ll>minFlights(n+1,LLONG_MAX); // minFlights[i] = minimum number of edges (flights) used to reach city i using the shortest cost path from the source
    vector<ll>maxFlights(n+1,0); // maxFlights[i] = maximum number of edges (flights) used to reach city i using the shortest cost path from the source
    minFlights[1] = 0; //no flight req to reach source city 1
    maxFlights[1] = 0; //no flight req to reach source city 1
    dijkstra(1,adj,cost,count,minFlights,maxFlights);
    cout<<cost[n]<<" "<<count[n]<<" "<<minFlights[n]<<" "<<" "<<maxFlights[n]<<endl;
    
}