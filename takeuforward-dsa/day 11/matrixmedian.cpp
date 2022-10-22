#include<bits/stdc++.h>

using namespace std;

int find_count(vector<int> matrix, int target){
    int low=0,high=matrix.size()-1;

    while(low<=high){
        int mid = (low+high)>>1;
        if(matrix[mid]>target){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}

int matrix_median(vector<vector<int>> &matrix){
    int low=1;
    int high=1e9;
    int n = matrix.size();
    int m = matrix[0].size();
    while(low<=high){
        int count = 0;
        int mid = (low+high) >> 1;
        for(int i=0;i<n;i++){
            count+=find_count(matrix[i], mid);
        }
        if(count<=(n*m)/2){
            low=mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return low;
}

int main(){
    vector<vector<int>> matrix ={
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };
    cout << matrix_median(matrix);
    return 0;
}