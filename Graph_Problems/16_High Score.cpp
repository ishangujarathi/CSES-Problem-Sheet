#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF  = 1e18;
//Standard Bellman Ford Algoruthm + BFS ALgorithm to detect cycle and check whether we can reach the last node from nodes involved in cycle or not
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m;
    cin>>n>>m;

    vector<vector<pair<ll,ll>>>adj(n+1);
    for(ll i=0;i<m;i++){
        ll src,dest,score;
        cin>>src>>dest>>score;
        adj[src].push_back({dest,score});
    }

    vector<ll>dist(n+1, -INF);  //dist[i] represents the maximum score to reach ith room from room 1
    dist[1] = 0;

    for(ll count=1;count<=n-1;count++){    //Standard Bellman Ford Algorithm (to relax the edges Nodes - 1 times)
        for(ll node=1;node<=n;node++){
            for(auto& it:adj[node]){
                ll node1 = node; 
                ll node2 = it.first;
                ll scr = it.second;
                if(dist[node1] != -INF && dist[node1] + scr > dist[node2]){
                    dist[node2] = dist[node1] + scr;
                }
            }
        }
    }

    vector<bool>inCycle(n+1, false);
    for(ll node=1;node<=n;node++){  //Standard Bellman Ford Algorithm to detect (positive/negative cycles)
        for(auto& it:adj[node]){
            ll node1 = node;
            ll node2 = it.first;
            ll scr = it.second;
            if(dist[node1] != -INF && dist[node1] + scr > dist[node2]){
                inCycle[node2] = true; // if we can reach node2 from node1, then node2 is in cycle as Positive Cycle is Detected
            }
        }
    }

    queue<ll>q;
    vector<bool>vis(n+1,false);   
    for(ll nodes=1;nodes<=n;nodes++){  
        if(inCycle[nodes]){   //whichever nodes are involved inCycle, that is forming a cycle, we will do a BFS from that nodes to see whether we can reach the last node or not
            q.push(nodes);
            vis[nodes] = true;
        }
    }

    while(!q.empty()){   //Standard BFS Algorithm to check whether we can reach the last node or node from nodes involved in cycle
        ll node = q.front();
        q.pop();

        if(node == n){   //if we are able to reach the last node from nodes involved into cycle, then we can say that we can reach the last node with maximum score(infinetly maximum score possible cuz we can loop infinetly into cycle and then reach the last node)
            cout<<-1<<endl;
            return 0;
        }
        for(auto& it:adj[node]){
            if(!vis[it.first]){
                vis[it.first] = true;
                q.push(it.first);
            }
        }
    }

    cout<<dist[n]<<endl;   //returning the maximum score to reach the last node from first node
    return 0;
}
