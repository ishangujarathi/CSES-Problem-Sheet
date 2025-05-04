#include<bits/stdc++.h>
using namespace std;
#define ll long long

//We will use Dijkstra's Algorithm, but with a slight twist! We will maintain additional state for every node, that is cost to reach node withoit applying discouunt coupon and cost to reach the node using discount coupon and lastly we will return the minimum of the two!

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m;
    cin>>n>>m;

    vector<vector<pair<ll,ll>>>adj(n+1);
    for(ll i=0;i<m;i++){
        ll src,dest,cost;
        cin>>src>>dest>>cost;
        adj[src].push_back({dest,cost});
    }

    //cost[node][0] = without applying coupon
    //cost[node][1] = with applying coupon
    vector<vector<ll>>cost(n+1,vector<ll>(2,LLONG_MAX));  //(nx2) cost vector to store additional discount state
    cost[1][0] = 0; //cost to reach source node without applying coupon is 0
    cost[1][1] = 0; //cost to reach source node with applying coupon is also 0

    priority_queue<vector<ll>,vector<vector<ll>>, greater<vector<ll>>>pq;  //{cost, node,discount state};
    pq.push({0,1,0});
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();

        ll curprice = it[0];
        ll curnode = it[1];
        ll discount_state = it[2];

        if(curprice > cost[curnode][discount_state]){
            continue;
        }

        for(auto& it:adj[curnode]){
            ll nextnode = it.first;
            ll nextprice = it.second;

            if(cost[nextnode][discount_state] > curprice + nextprice){   //withput applying coupon
                cost[nextnode][discount_state] = curprice + nextprice;
                pq.push({cost[nextnode][discount_state],nextnode, discount_state});
            }

            if(discount_state == 0){   //applying coupon discount
                if(cost[nextnode][1] > curprice + nextprice / 2){
                    cost[nextnode][1] = curprice + nextprice / 2;
                    pq.push({cost[nextnode][1], nextnode,1});
                }
            }
        }
    }

    cout<<min(cost[n][0], cost[n][1])<<endl;  //minimum cost to reach the destination city either by applying coupon or not applying

}
