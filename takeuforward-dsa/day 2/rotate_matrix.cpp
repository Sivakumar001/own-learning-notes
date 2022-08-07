#include<bits/stdc++.h>
using namespace std;

void rotate_matrix(vector<vector<int>> &nums){
    //transpose
    int n=nums.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){break;}
            swap(nums[i][j], nums[j][i]);
        }
    }
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