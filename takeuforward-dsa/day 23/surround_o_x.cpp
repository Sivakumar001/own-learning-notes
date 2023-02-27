#include<bits/stdc++.h>
#include <vector>

using namespace std;

void dfs(vector<vector<char>> &grid, vector<vector<int>> &vis, int r, int c, int n, int m){
    vis[r][c] = 1;
    vector<int> pos_row = {0, -1, 0, 1};
    vector<int> pos_col = {-1,0, 1, 0};
    for(int i=0;i<4;i++){
        int n_row = r+pos_row[i];
        int n_col = c+pos_col[i];
        if((n_row>=0 && n_row<n) &&
            (n_col>=0 && n_col<m) &&
            (grid[n_row][n_col]=='o') &&
            (!vis[n_row][n_col])){
                dfs(grid, vis, n_row, n_col, n, m);
            }
    }
}

vector<vector<char>> surround_square(vector<vector<char>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for(int i=0;i<m;i++){
        if(!vis[0][i] && grid[0][i]=='o'){
            dfs(grid, vis, 0, i, n, m);
        }
        if(!vis[n-1][i]&& grid[0][i]=='o'){
            dfs(grid, vis, n-1, i, n,m);
        }
    }
    for(int i=0;i<n;i++){
        if(!vis[i][0]&& grid[0][i]=='o'){
            dfs(grid, vis, i, 0, n, m);
        }
        if(!vis[i][n-1]&& grid[0][i]=='o'){
            dfs(grid, vis, i, n-1, n, m);
        }
    }

    vector<vector<char>> ans = grid;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && grid[i][j]=='o'){
                ans[i][j]='x';
            }
        }
    }
    return ans;
}

int main(){
    vector<vector<char>> grid = {
        {'o','x','x','o'},
        {'x','o','o','x'},
        {'x','x','x','x'},
        {'o','o','x','x'}
    };

    vector<vector<char>> ans = surround_square(grid);

    for(auto r: ans){
        for(auto c: r){
            cout << c << " ";
        }
        cout << "\n";
    }
}