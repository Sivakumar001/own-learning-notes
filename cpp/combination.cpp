#include<bits/stdc++.h>

using namespace std;

void findCombination(vector<int> &arr, vector<vector<int>> &answer,
 vector<int> &ds, int total_included, int index=0, int included=0){
    for(int i=index; i<arr.size();i++){
        ds.push_back(arr[i]);
        findCombination(arr, answer, ds, total_included, i+1, included+1);
        ds.pop_back();
    }
    if(included==total_included){
        answer.push_back(ds);
    }
    return;
}

int main(){
    vector<int> arr = {1,2,3};
    vector<vector<int>> answer;
    vector<int> ds;
    sort(arr.begin(), arr.end());
    findCombination(arr, answer, ds, 3);
    for(auto itr: answer){
        for(auto it: itr){
            cout << it;
        }cout << endl;
    }
    return 0;
}