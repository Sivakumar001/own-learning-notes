#include<bits/stdc++.h>

using namespace std;

void rat_maze(vector<vector<int>> &maze, vector<string> &answers, string &ds, int row=0, int col=0){
    if(row<0 || row==maze.size() || col<0 || col==maze[0].size()){
        ds.pop_back();
        return;
    }

    if(maze[row][col]==0 || maze[row][col]==2){
        ds.pop_back();return;
    }

    if(row==maze.size()-1 && col==maze.size()-1){
        answers.push_back(ds);
        return;
    }

    maze[row][col]=2;
    rat_maze(maze, answers, ds+='D', row+1, col);
    rat_maze(maze, answers, ds+='R', row, col+1);
    rat_maze(maze, answers, ds+='U', row-1, col);
    rat_maze(maze, answers, ds+='L', row, col-1);
    ds.pop_back();
    maze[row][col]=1;
    return;
}

int main(){
    vector<vector<int>> maze = {
        {1, 0},
        {1, 1},
    };

    vector<string> answers;
    string ds;

    rat_maze(maze, answers, ds);
    for(auto itr: answers){
        cout << itr << endl;
    }
    return 0;
}