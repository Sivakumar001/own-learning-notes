#include<bits/stdc++.h>

using namespace std;

void AllPermutation(vector<vector<int>> &answer, vector<int> &arr, int index=0){
    for(int i=index; i<arr.size(); i++){
        swap(arr[index], arr[i]);
        AllPermutation(answer, arr, i+1);
        swap(arr[index], arr[i]);
    }
    if(index==arr.size()){
        answer.push_back(arr);
    }
    return;
}
int main(void){
    vector<int> arr = {1,2,3};
    vector<vector<int>> answer;

    AllPermutation(answer, arr);

    for(auto itr: answer){
        for(auto it: itr){
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}