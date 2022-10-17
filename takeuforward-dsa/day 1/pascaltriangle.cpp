#include<bits/stdc++.h>
using namespace std;
// creating pascal triangle
// set first and last number in array as 1
// now calculate the inside values by toparr + toparr-1 values
// to get specific arr you can use permutation too

vector<vector<int>> pascal_triangle(int rows){
    vector<vector<int>> ans(rows);
    int res=1;
    // loop through n rows
    for(int n=0; n<rows; n++){
        ans[n].resize(n+1);
        ans[n][0] = ans[n][n] = 1;
        // set first and last as 1
        // inbetween arr values equal toparr+ toparr-1 values
        for(int k=1; k<n; k++){
            ans[n][k] = ans[n-1][k-1]+ans[n-1][k];
        }
    }
    return ans;
}

vector<int> specific_array(int rowLength){
    // identify a specific row of pascal's triangle
    // can use combination in this problem
    int res;
    vector<int> ans(rowLength+1, 0);
    res = ans[0]=1;
    for(int i=0; i<rowLength; i++){
        res *= (rowLength-i);
        res /= (i+1);
        ans[i+1]=res;
    }
    return ans;
}

int main(){
    int rows=0;
    cin >> rows;
    vector<vector<int>> answer;
    vector<int> ans = specific_array(rows);
    answer = pascal_triangle(rows);
    for(auto it: ans){
        cout << it;
    }
    cout << "\n";
    for(auto it: answer){
        for(auto itr : it){
            cout << itr;
        }
        cout << "\n";
    }
}