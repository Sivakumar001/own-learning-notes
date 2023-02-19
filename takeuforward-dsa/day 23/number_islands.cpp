#include<bits/stdc++.h>

using namespace std;
class solution{
    public:
        void bfs(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &vis){
            vis[i][j]=1;
            queue<pair<int, int>> q;
            q.push({i,j});

            while(!q.empty()){
                int crow = q.front().first;
                int ccol = q.front().second;
                q.pop();

                for(int i=-1;i<=1;i++){
                    for(int j=-1;j<=1;j++){
                        int nrow = crow+i;
                        int ncol = ccol+j;

                        if( (nrow>=0 && nrow<grid.size()) &&
                            (ncol>=0 && ncol<grid[0].size()) &&
                            !vis[nrow][ncol] &&
                            grid[nrow][ncol]==1)
                        {
                            vis[nrow][ncol]=1;
                            q.push({nrow, ncol});
                        }
                    }
                }
            }
        }
        int numberIslands(vector<vector<int>> grid){
            int n = grid.size();
            int m = grid[0].size();
            int count=0;
            vector<vector<int>> vis(n, vector<int>(m, 0));
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(!vis[i][j] && grid[i][j]==1){
                        count++;
                        bfs(grid, i, j, vis);
                    }
                }
            }
            return count;
        }
};

int main(){
    vector<vector<int>> grid{
    {1, 1, 0, 1, 1},
    {1, 0, 0, 0, 0},
    {0, 0, 0, 0, 1},
    {1, 1, 0, 1, 1}};

    solution obj;
    cout << obj.numberIslands(grid);
}