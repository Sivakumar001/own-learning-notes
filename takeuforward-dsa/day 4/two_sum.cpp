#include<bits/stdc++.h>
using namespace std;
// using hashmap for the soln
// if target-arrind exist in hashmap return thats the pair
// sort and binary search (2nd method)

vector<int> two_sum(vector<int> arr, int target){
    unordered_map<int,int> sum_map;
    vector<int> ans;
    for(int i=0;i<arr.size();i++){
        if(sum_map.find(target-arr[i])!=sum_map.end()){
            ans.push_back(sum_map[target-arr[i]]);
            ans.push_back(i);
        }
        sum_map[target-arr[i]]=i;
    }

    map<int,int> s;
    for(auto it: arr){
        if(s.find(it)!=s.end()){
            cout << s[it] << "\t" << it;
        }
        s[target-it]=it;
    }

    for(auto val: s){
        cout << val.first << "\t" << val.second << "\n";
    }
    return ans;
}
int main(){
    vector<int> que={2,7,11,15};
    vector<int> ans = two_sum(que, 9);

    for(auto it: ans){
        cout << it;
    }
    return 0;
}