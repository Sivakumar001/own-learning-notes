#include<bits/stdc++.h>

using namespace std;

vector<int> remove_duplicate(vector<int> arr){
    int slow = 0;
    int fast = 0;
    while(fast<arr.size()){
        if(arr[fast]!=arr[slow]){
            slow++;
            arr[slow] = arr[fast];
        }
        fast++;
    }
    // while(slow<arr.size()){
    //     slow++;
    //     arr[slow]=0;
    // }
    return arr;
}
int main(){
    vector<int> arr = {1,1,3,3,3,3,3,3,4,4,4,4,4,6,6,6,6,6,7,7,7,7,8,8};
    vector<int> ans = remove_duplicate(arr);
    for(auto it: ans){
        cout << it << " ";
    }
    return 0;
}