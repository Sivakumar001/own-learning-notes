#include<bits/stdc++.h>

using namespace std;

void findPermutation(vector<vector<int>> &answer, vector<int> &arr, int start=0){
    if(start==arr.size()){
        answer.push_back(arr);
        return;
    }
    for(int i=start; i<arr.size();i++){ 
        swap(arr[start], arr[i]);
        findPermutation(answer, arr, i+1);
        swap(arr[start], arr[i]);
    }
    return;
}
int main(){
    vector<int> arr={1,2,3,4};
    vector<vector<int>> answer;
    findPermutation(answer, arr);
    for(auto itr: answer){
        for(auto it: itr){
            cout << it;
        }cout << endl;
    }
    return 0;
}