#include<bits/stdc++.h>

using namespace std;

void bfs(vector<vector<int>> &grid, vector<vector<int>> &vis, int r, int c){
    int n = grid.size();
    int m = grid[0].size();
    vector<int> pos_r = {0, -1, 0, 1};
    vector<int> pos_c = {-1, 0, 1, 0};
    queue<pair<int, int>> islands;
    islands.push({r, c});

    while(!islands.empty()){
        int row = islands.front().first;
        int col = islands.front().second;
        islands.pop();
        for(int i=0;i<4;i++){
            int n_row = row+pos_r[i];
            int n_col = col+pos_c[i];
            if((n_row>=0 && n_row<n) &&
            (n_col>=0 && n_col<m) &&
            (!vis[n_row][n_col]) &&
            (grid[n_row][n_col]==1)){
                vis[n_row][n_col] = 1;
                islands.push({n_row, n_col});
            }
        }
    }
}

int number_of_enclaves(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int ans = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0 || i==n-1 || j==0 || j==n-1){
                if(grid[i][j]==1 && !vis[i][j]){
                    vis[i][j]=1;
                    bfs(grid, vis, i, j);
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1 && !vis[i][j]){
                ans++;
            }
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> grid = {
        {0,0,0,1,1},
        {0,0,1,1,0},
        {0,1,0,0,0},
        {0,1,1,0,0},
        {0,0,0,1,1}
    };

    cout << number_of_enclaves(grid);
}