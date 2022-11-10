#include<bits/stdc++.h>

using namespace std;

int celebrity_find(vector<vector<int>> &arr){
    stack<int> stk;
    for(int i=0;i<arr.size();i++){
        stk.push(i);
    }
    while(stk.size()!=1){
        int A = stk.top();
        stk.pop();
        int B = stk.top();
        stk.pop();

        if(arr[A][B]==1){
            stk.push(B);
        }
        if(arr[B][A]==1){
            stk.push(A);
        }
    }
    return stk.top();
}

int main(){
    vector<vector<int>> arr = {
        {0,0,1,0},
        {0,0,1,0},
        {0,0,0,0},
        {0,0,1,0}
    };

    cout << celebrity_find(arr);
    return 0;
}