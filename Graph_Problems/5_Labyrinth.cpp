#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool BFS(ll x, ll y, vector<vector<char>>& grid, string& res) {
    ll n = grid.size();
    ll m = grid[0].size();
    queue<pair<ll, ll>> q;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    q.push({x, y});
    vis[x][y] = true;

    vector<vector<pair<ll, ll>>> parent(n, vector<pair<ll, ll>>(m, {-1, -1}));
    vector<vector<char>> moves(n, vector<char>(m));
    vector<char> dir = {'U', 'R', 'D', 'L'};
    vector<ll> delrow = {-1, 0, 1, 0};
    vector<ll> delcol = {0, 1, 0, -1};

    while (!q.empty()) {
        ll row = q.front().first;
        ll col = q.front().second;
        q.pop();

        if (grid[row][col] == 'B') {
            vector<char> path;
            while (make_pair(row, col) != make_pair(x, y)) {
                char d = moves[row][col];
                path.push_back(d);
                pair<ll, ll> p = parent[row][col];
                row = p.first;
                col = p.second;
            }
            reverse(path.begin(), path.end());
            res = string(path.begin(), path.end());
            return true;
        }

        for (ll k = 0; k < 4; k++) {
            ll n_row = row + delrow[k];
            ll n_col = col + delcol[k];

            if (n_row >= 0 && n_row < n && n_col >= 0 && n_col < m && !vis[n_row][n_col] &&
                (grid[n_row][n_col] == '.' || grid[n_row][n_col] == 'B')) {
                vis[n_row][n_col] = true;
                q.push({n_row, n_col});
                parent[n_row][n_col] = {row, col};
                moves[n_row][n_col] = dir[k];
            }
        }
    }
    return false;
}

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    string res;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            if (grid[i][j] == 'A') {
                if (BFS(i, j, grid, res)) {
                    cout << "YES\n";
                    cout << res.size() << "\n";
                    cout << res << "\n";
                } else {
                    cout << "NO\n";
                }
                return 0;  
            }
        }
    }

    return 0;
}
