#include<bits/stdc++.h>

using namespace std;

string common_prefix(vector<string> arr){
    int ans_len = arr[0].size();
    for(int i=1;i<arr.size();i++){
        int pre=0;
        while(pre<arr[0].size() && pre<arr[i].size() && arr[0][pre]==arr[i][pre]){
            pre++;
        }
        ans_len = min(ans_len, pre);
    }
    return arr[0].substr(0, ans_len);
}
int main(){
    vector<string> arr = {"flower", "flow", "flight"};
    cout << common_prefix(arr);
}