#include<bits/stdc++.h>
using namespace std;
// use first row and column as store space
// create a boolean to store the value of column to avoid intersection of first element

void set_matrices(vector<vector<int>> &matrix){
    bool colRow=0;
        int row=matrix.size()-1,col=matrix[0].size()-1;
        
        for(int i=0;i<matrix.size();i++){
            if(matrix[i][0]==0)colRow=1;
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    matrix[0][j]=matrix[i][0]=0;
                }
            }
        }
        
        for(row=matrix.size()-1;row>=0;row--){
            for(col=matrix[0].size()-1;col>=1;col--){
                if(matrix[0][col]==0 || matrix[row][0]==0){
                    matrix[row][col]=0;
                }
            }
            if(colRow)matrix[row][0]=0;
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