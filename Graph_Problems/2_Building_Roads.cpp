// Time limit: 1.00 s
// Memory limit: 512 MB



// Byteland has n cities, and m roads between them. The goal is to construct new roads so that there is a route between any two cities.
// Your task is to find out the minimum number of roads required, and also determine which roads should be built.

// Input
// The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1,2,\dots,n.
// After that, there are m lines describing the roads. Each line has two integers a and b: there is a road between those cities.
// A road always connects two different cities, and there is at most one road between any two cities.

// Output
// First print an integer k: the number of required roads.
// Then, print k lines that describe the new roads. You can print any valid solution.
// Constraints

// 1 \le n \le 10^5
// 1 \le m \le 2 \cdot 10^5
// 1 \le a,b \le n

// Example
// Input:
// 4 2
// 1 2
// 3 4

// Output:
// 1
// 2 3


#include <bits/stdc++.h>
using namespace std;

void DFS(int city, vector<vector<int>>& adj, vector<bool>& vis, vector<int>& component) {
    vis[city] = true;
    component.push_back(city);
    for (auto& it : adj[city]) {
        if (!vis[it]) {
            DFS(it, adj, vis, component);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> vis(n + 1, false);
    vector<vector<int>> components;  // Finding all connected components
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vector<int> component;
            DFS(i, adj, vis, component);
            components.push_back(component);
        }
    }

    int count = components.size() - 1;
    cout << count << endl;

    for (int i = 1; i <= count; i++) {
        cout << components[i - 1][0] << " " << components[i][0] << endl;
    }

    return 0;
}

