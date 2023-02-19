#include<bits/stdc++.h>

using namespace std;

void floodfill(vector<vector<int>> &grid,
    vector<vector<int>> &vis,
    int x, int y, int init_color, int color)
    {
        vis[x][y] = 1;
        grid[x][y] = color;
        vector<int> prow = {0,1,0,-1};
        vector<int> pcol = {1,0,-1,0};
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0;i<4;i++){
            int c_row = x+prow[i];
            int c_col = y+pcol[i];
            if(
                (c_row>=0 && c_row<n) &&
                (c_col>=0 && c_col<m) &&
                !vis[c_row][c_col] &&
                grid[c_row][c_col]==init_color)
                {
                    floodfill(grid, vis, c_row, c_col, init_color, color);
                }
        }
}
int main(){
    vector<vector<int>> grid = {
        {1,1,1,1},
        {0,1,0,0},
        {2,1,3,0},
        {0,1,2,2}
    };
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));

    floodfill(grid, vis, 0, 2, 1, 2);
    for(auto i:grid){
        for(auto it: i){
            cout << it << " ";
        }
        cout << "\n";
    }
}