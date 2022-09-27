#include<bits/stdc++.h>

using namespace std;

void subset_sum(int arr[], int n, vector<int> &sum, int summation=0, int i=0){
    if(i==n){
        sum.push_back(summation);
        return;
    }
    subset_sum(arr, n, sum, summation, i+1);
    summation += arr[i];
    subset_sum(arr, n, sum, summation, i+1);
    return;
}

int main(){
    int n=3;
    int arr[] = {5,2,1};
    vector<int> ans;
    subset_sum(arr, n, ans);
    for(auto itr: ans){
        cout << itr << " ";
    }
    cout<< endl;
    return 0;
}