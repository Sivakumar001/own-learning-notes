#include<bits/stdc++.h>

using namespace std;

void combination_sum(vector<vector<int>> &ans, vector<int> &dummy, int arr[], int n, int target, int index=0){
    if(index==n){
        if(target==0){
            ans.push_back(dummy);
        }
        return;
    }
    if(arr[index]<=target){
        dummy.push_back(arr[index]);
        combination_sum(ans, dummy, arr, n , target-arr[index], index);
        dummy.pop_back();
    }
    combination_sum(ans, dummy, arr, n, target, index+1);
    return;
}

int main(){
    int arr[] = {2,1,3,4};
    vector<vector<int>> answer;
    vector<int> dummy;
    int n = sizeof(arr)/sizeof(int);
    int target=5;
    combination_sum(answer, dummy, arr, n, target);
    for(auto itr: answer){
        cout << "{";
        for(auto it: itr){
            cout << it << ",";
        }cout << "}" << endl;
    }
    return 0;
}