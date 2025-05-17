#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> edges;
    for (ll i = 0; i < m; i++) {
        ll node1, node2, weight;
        cin >> node1 >> node2 >> weight;
        edges.push_back({node1, node2, weight});
    }

    vector<ll> distance(n + 1, INF);
    distance[1] = 0;
    vector<ll> parent(n + 1, -1);

    for (ll count = 1; count <= n - 1; count++) {
        for (auto& edge : edges) {
            ll src = edge[0];
            ll dest = edge[1];
            ll wt = edge[2];
            if (distance[src] != INF && distance[dest] > distance[src] + wt) {
                distance[dest] = distance[src] + wt;
                parent[dest] = src;
            }
        }
    }

    ll nodeincycle = -1;
    for (auto& edge : edges) {
        ll src = edge[0];
        ll dest = edge[1];
        ll wt = edge[2];
        if (distance[src] != INF && distance[dest] > distance[src] + wt) {
            parent[dest] = src;
            nodeincycle = dest;
            break;
        }
    }

    if (nodeincycle == -1) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;

        for (ll i = 0; i < n; i++) {
            nodeincycle = parent[nodeincycle];
        }

        vector<ll> cycle;
        ll current = nodeincycle;
        cycle.push_back(current);
        current = parent[current];

        while (current != nodeincycle) {
            cycle.push_back(current);
            current = parent[current];
        }

        cycle.push_back(nodeincycle);
        reverse(cycle.begin(), cycle.end());

        for (auto& it : cycle) {
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}
