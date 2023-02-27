#include<bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &grid, vector<vector<int>> &vis, 
        vector<pair<int, int>> & islands, int i, int j, int base_r, int base_c){
            vis[i][j]=1;
            islands.push_back({i-base_r, j-base_c});
            int n = grid.size();
            int m = grid[0].size();
            vector<int> pos_r = {-1, 0, 1, 0};
            vector<int> pos_c = {0, -1, 0, 1};
            for(int i=0;i<4;i++){
                int n_row = i+pos_r[i];
                int n_col = j+pos_c[i];
                if((n_row>=0 && n_row<n) &&
                    (n_col>=0 && n_col<m) &&
                    (!vis[n_row][n_col]) &&
                    (grid[n_row][n_col]==1)){
                        dfs(grid, vis, islands, n_row, n_col, base_r, base_c);
                    }
            }
}

int number_of_distinct(vector<vector<int>> &grid){
    set<vector<pair<int, int>>> distinct_islands;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && grid[i][j]==1){
                vector<pair<int, int>> islands;
                dfs(grid, vis, islands, i, j, i, j);
                distinct_islands.insert(islands);
            }
        }
    }

    for(auto itr: distinct_islands){
        for(auto it: itr){
            cout << it.first << " " << it.second << " ";
        }
        cout << "\n";
    }
    return distinct_islands.size();
}

int main(){
    vector<vector<int>> grid = {
        {1,1,0,1,1},
        {1,0,0,0,0},
        {0,0,0,0,1},
        {1,1,0,1,1}
    };
    cout << number_of_distinct(grid);
}