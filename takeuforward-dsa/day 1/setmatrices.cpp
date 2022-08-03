#include<bits/stdc++.h>
using namespace std;


void set_matrices(vector<vector<int>> &given_matrix){
    bool flag = false;

    for(int i=0;i<3;i++){
        if(given_matrix[i][0]==0){flag=true;}
        for(int j=1;j<3;j++){
            if(given_matrix[i][j]==0){
                given_matrix[0][j] = given_matrix[i][0] = 0;
            }
        }
    }

    for(int row=2; row>=0; row--){
        for(int col=2; col>=1; col--){
            if(given_matrix[row][0]==0 || given_matrix[0][col]==0){
                given_matrix[row][col]=0;
            }
        }
        if(flag){
            given_matrix[row][0]=0;
        }
    }
}

int main(){
    vector<vector<int>> matrix = {
        {0,1,1},
        {1,1,1},
        {0,1,1}};
    set_matrices(matrix);
    for(int i=0;i<3;i++){
        cout << "\n";
        for(int j=0;j<3;j++){
            cout << matrix[i][j];
        }
    }
}