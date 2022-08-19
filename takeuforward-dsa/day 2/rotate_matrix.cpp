#include<bits/stdc++.h>
using namespace std;

// to rotate a matrix transpose the matrix
// and reverse the rows
// you rotated by 90deg

void rotate_matrix(vector<vector<int>> &nums){
    //transpose
    int n=nums.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){break;}
            swap(nums[i][j], nums[j][i]);
        }
    }
    // reverse rows
    for(int i=0;i<n;i++){
        reverse(nums[i].begin(), nums[i].end());
    }
}

int main(){
    vector<vector<int>> matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    rotate_matrix(matrix);

    for(auto it: matrix){
        for(auto itr: it){
            cout << itr << "\t";
        }
        cout << "\n";
    }
    return 0;
}