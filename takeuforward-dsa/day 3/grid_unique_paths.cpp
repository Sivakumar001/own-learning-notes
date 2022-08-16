#include<bits/stdc++.h>
using namespace std;

// DP and recursion
int unique_path(int m, int n, vector<vector<int>> &dp, int i, int j){
    if(i>=m || j>=n){return 0;}
    if(i==m-1 && j==n-1){return 1;}

    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    else{
        return dp[i][j] = unique_path(m, n, dp, i+1, j)+unique_path(m, n, dp, i, j+1);
    }
}


// combination problem 
int unique_path(int m, int n){
    double result = 1.0;
    int N = m+n-2;
    int r = m-1;
    for(int i=1;i<=r;i++){
        result = result*(N-r+i)/i;
    }
    return result;
}
int main(){
    vector<vector<int>> dp(2, vector<int>(2, -1));
    int count = unique_path(2,2, dp, 0,0);
    int ans = unique_path(2,2);
    cout << ans;
    cout << count;
    return 0;
}