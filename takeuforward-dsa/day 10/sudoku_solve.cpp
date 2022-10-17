#include<bits/stdc++.h>

using namespace std;

bool isValid(vector<vector<string>> &sudoku_board, int row, int col, int val){
    for(int i=0;i<sudoku_board.size();i++){
        if(sudoku_board[row][i]==to_string(val)){return false;}
        if(sudoku_board[i][col]==to_string(val)){return false;}
        if(sudoku_board[3*(row/3)+i/3][3*(col/3)+i%3]==to_string(val)){return false;}
    }
    return true;
}

bool solve(vector<vector<string>> &sudoku_board){
    for(int row=0; row<sudoku_board.size(); row++){
        for(int col=0; col<sudoku_board[0].size(); col++){
            // Parse through array
            // find empty space here
            if(sudoku_board[row][col]=="."){
                // compare with the elements 1to9
                for(int i=1;i<10;i++){
                    if(isValid(sudoku_board, row, col, i)){
                        sudoku_board[row][col]=to_string(i);
                        if(solve(sudoku_board)==true){
                            return true;
                        }
                        else{
                            sudoku_board[row][col]=".";
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main(){
    vector<vector<string>> sudoku_board={
        {"5","3",".",".","7",".",".",".","."},
        {"6",".",".","1","9","5",".",".","."},
        {".","9","8",".",".",".",".","6","."},
        {"8",".",".",".","6",".",".",".","3"},
        {"4",".",".","8",".","3",".",".","1"},
        {"7",".",".",".","2",".",".",".","6"},
        {".","6",".",".",".",".","2","8","."},
        {".",".",".","4","1","9",".",".","5"},
        {".",".",".",".","8",".",".","7","9"}
        };
    solve(sudoku_board);

    for(auto itr: sudoku_board){
        for(auto it: itr){
            cout << it << " ";
        }cout << endl;
    }
    return 0;
}