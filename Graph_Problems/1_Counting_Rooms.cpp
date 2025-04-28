// Time limit: 1.00 s Memory limit: 512 MB

// You are given a map of a building, and your task is to count the number of its rooms. The size of the map is n \times m squares, and each square is either floor or wall. You can walk left, right, up, and down through the floor squares.
// Input
// The first input line has two integers n and m: the height and width of the map.
// Then there are n lines of m characters describing the map. Each character is either . (floor) or # (wall).
// Output
// Print one integer: the number of rooms.
// Constraints

// 1 \le n,m \le 1000

// Example
// Input:
// 5 8
// ########
// #..#...#
// ####.#.#
// #..#...#
// ########

// Output:
// 3

#include<bits/stdc++.h>
using namespace std;

void DFS(int row, int col, vector<vector<char>>&grid, vector<vector<bool>>&vis){
    int n = grid.size();
    int m = grid[0].size();
    vis[row][col] = true;
    vector<int>delrow = {-1,0,1,0};
    vector<int>delcol = {0,1,0,-1};
    for(int k=0;k<4;k++){
        int n_row = row + delrow[k];
        int n_col = col + delcol[k];

        if(n_row >= 0 && n_row < n && n_col >= 0 && n_col < m && !vis[n_row][n_col] && grid[n_row][n_col] == '.'){
            DFS(n_row,n_col,grid,vis);
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>>grid(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }

    vector<vector<bool>>vis(n,vector<bool>(m,false));
    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == '.' && !vis[i][j]){
                DFS(i,j,grid,vis);
                count++;
            }
        }
    }
    cout<<count<<endl;
}