#include<bits/stdc++.h>

using namespace std;

int rotten_oranges(vector<vector<int>> &matrix){
    int n = matrix.size(), m=matrix[0].size();
    int visited[n][m];
    // {{r, c}, t}
    queue<pair<pair<int, int> , int>> rotting_queue;
    int fresh=0;
    // create a visited matrix to store rotten oranges
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==2){
                rotting_queue.push({{i, j},0});
                visited[i][j]=2;
            }
            else{
                visited[i][j]=0;
            }
            if(matrix[i][j]==1)fresh++;
        }
    }
    // 4 possiblity check for the given cell
    int nxtRow[]={-1,0,1,0};
    int nxtCol[]={0,-1,0,1};
    int max_time=0;
    int getRotten=0;

    while(!rotting_queue.empty()){
        int row=rotting_queue.front().first.first;
        int col=rotting_queue.front().first.second;
        int time=rotting_queue.front().second;
        max_time = max(max_time, time);
        for(int i=0;i<4;i++){
            int nRow=row+nxtRow[i];
            int nCol=col+nxtCol[i];
            // within cells and given mat=1 also not visited
            if((nRow>=0 && nRow<n && nCol>=0 && nCol<m) &&
                (matrix[nRow][nCol]==1)&&
                (visited[nRow][nCol]==0)){
                    rotting_queue.push({{nRow, nCol}, time+1});
                    visited[nRow][nCol]=2;
                    getRotten++;
            }
        }
        rotting_queue.pop();
    }

    if(fresh!=getRotten){
        return -1;
    }

    return max_time;
}

int main(){
    vector<vector<int>> matrix={
        {2,1,1},
        {1,1,1},
        {0,1,0}
    };

    int ans= rotten_oranges(matrix);
    cout << ans;
    return 0;
}