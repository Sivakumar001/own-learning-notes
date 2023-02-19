#include<bits/stdc++.h>

using namespace std;

int rotten_oranges(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> oranges;
    int time=0, cnt_fresh=0, cnt_visited=0;

    vector<int> possible_r = {0, 1, 0, -1};
    vector<int> possible_c = {1, 0, -1, 0};

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                oranges.push({{i, j}, 0});
                visited[i][j]=1;
            }
            else if(grid[i][j]==1){
                cnt_fresh++;
            }
        }
    }

    while(!oranges.empty()){
        int size = oranges.size();
        while(size--){
            int r,c,t;
            r = oranges.front().first.first;
            c = oranges.front().first.second;
            t = oranges.front().second;
            oranges.pop();
            time = max(time, t);

            for(int i=0;i<4;i++){
                int cur_r = r+possible_r[i];
                int cur_c = c+possible_c[i];
                if(
                    (cur_r>=0 && cur_r<n) &&
                    (cur_c>=0 && cur_c<m) &&
                    !visited[cur_r][cur_c] &&
                    grid[cur_r][cur_c]==1
                    )
                    {
                        cnt_visited++;
                        visited[cur_r][cur_c]=1;
                        oranges.push({{cur_r, cur_c}, t+1});
                    }
                }
            }
        }
    if(cnt_fresh!=cnt_visited)return -1;
    return time;
}

int main(){
    vector<vector<int>> grid = {
        {0,1,2},
        {0,1,2},
        {2,1,1}
    };

    cout << rotten_oranges(grid);
}