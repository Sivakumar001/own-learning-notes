#include<bits/stdc++.h>

using namespace std;

void subset_sum2(vector<vector<int>> &ans, int arr[], int n, vector<int> &dummy, int index=0){
    ans.push_back(dummy);
    for(int i=index;i<n;i++){
        if(i!=index && arr[i]==arr[i-1])continue;
        dummy.push_back(arr[i]);
        subset_sum2(ans, arr, n, dummy, i+1);
        dummy.pop_back();
    }
    return;
}

int main(){
    int arr[] = {1,2,2};
    int n = sizeof(arr)/sizeof(int);
    sort(arr, arr+n);
    vector<vector<int>> ans;
    vector<int> ds;
    subset_sum2(ans, arr, n, ds);
    for(auto itr: ans){
        for(auto it: itr){
            cout << it << " ";
        }cout << endl;
    }
    return 0;
}