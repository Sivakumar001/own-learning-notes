#include<bits/stdc++.h>

using namespace std;
bool isQueenSafe(vector<string> &board, int row, int col){
    int duprow=row;
    int dupcol=col;

    while(duprow>=0 && dupcol>=0){
        if(board[duprow][dupcol]=='Q')return false;
        duprow--;
        dupcol--;
    }

    duprow=row;
    dupcol=col;

    while(dupcol>=0){
        if(board[duprow][dupcol]=='Q')return false;
        dupcol--;
    }

    duprow=row;
    dupcol=col;

    while(duprow<board.size() && dupcol>=0){
        if(board[duprow][dupcol]=='Q')return false;
        duprow++;
        dupcol--;
    }

    return true;
}

void Nqueen(vector<vector<string>> &answer, vector<string> &board, int total_queen, int col=0){
    if(col==board.size()){
        answer.push_back(board);
        return;
    }
    for(int row=0; row<board.size();row++){
        if(isQueenSafe(board, row, col)){
            board[row][col] = 'Q';
            Nqueen(answer, board, total_queen, col+1);
            board[row][col] = '.';
        }
    }
}

int main(void){
    int number=5;
    vector<string> board(number);
    string s(number, '.');
    for(int i=0;i<number;i++){
        board[i]=s;
    }
    vector<vector<string>> answer;
    Nqueen(answer, board, number);
    for(auto it: answer){
        for(auto itr: it){
            cout << itr << endl;
        }
        cout << endl;
    }
    return 0;
}