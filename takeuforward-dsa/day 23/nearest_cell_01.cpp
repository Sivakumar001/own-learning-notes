#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> nearest_cell(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>> connectors;
    vector<vector<int>> visited(n, vector<int>(m, 0));
    vector<vector<int>> near_cell(n, vector<int>(m, 0));
    int count = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                visited[i][j]=1;
                connectors.push({i, j});
            }
        }
    }

    while(!connectors.empty()){
        int size = connectors.size();
        for(int i=0;i<size;i++){
            int row = connectors.front().first;
            int col = connectors.front().second;
            connectors.pop();
            near_cell[row][col] = count;
            vector<int> pos_row = {0, -1, 0,1};
            vector<int> pos_col = {-1,0,1,0};
            for(int i=0;i<4;i++){
                int n_row = row+pos_row[i];
                int n_col = col+pos_col[i];
                if( (n_row>=0 && n_row<n) &&
                    (n_col>=0 && n_col<m) &&
                    (grid[n_row][n_col]==0) &&
                    (!visited[n_row][n_col]))
                    {
                        visited[n_row][n_col] = 1;
                        connectors.push({n_row, n_col});
                    }
            }
        }
        count++;
    }
    return near_cell;
}

int main(){
    vector<vector<int>> grid = {
        {0,0,0,0},
        {0,1,0,0},
        {1,0,1,0}
    };
    
    vector<vector<int>> ans = nearest_cell(grid);
    for(auto r: ans){
        for(auto c: r){
            cout << c << " ";
        }
        cout << "\n";
    }
}