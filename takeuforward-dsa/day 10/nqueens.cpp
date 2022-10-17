#include<bits/stdc++.h>

using namespace std;


void Nqueen(vector<vector<string>> &answer,
            vector<string> &board,
            vector<bool> &colcheck,
            vector<bool> &upperdiagonal,
            vector<bool> &lowerdiagonal,
            int col=0){

    if(col==board.size()){
        answer.push_back(board);
        return;
    }

    for(int row=0; row<board.size();row++){
        if(colcheck[row]==0 &&
           upperdiagonal[row+col]==0 &&
           lowerdiagonal[(board.size() -1)+col-row]==0){

            colcheck[row]=1;
            upperdiagonal[row+col]=1;
            lowerdiagonal[(board.size()-1)+col-row]=1;

            board[row][col]='Q';

            Nqueen(answer, board, colcheck, upperdiagonal, lowerdiagonal, col+1);

            board[row][col]='.';

            colcheck[row]=0;
            upperdiagonal[row+col]=0;
            lowerdiagonal[(board.size()-1)+col-row]=0;
        }
    }
}

int main(void){
    int number=4;
    string s(number, '.');
    vector<string> board(number, s);
    vector<vector<string>> answer;
    vector<bool> colcheck(number, 0);
    vector<bool> upperdiagonal((2*number)-1, 0);
    vector<bool> lowerdiagonal((2*number)-1, 0);

    Nqueen(answer, board, colcheck, upperdiagonal, lowerdiagonal);

    for(auto it: answer){
        for(auto itr: it){
            cout << itr << endl;
        }
        cout << endl;
    }
    return 0;
}