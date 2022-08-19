#include<bits/stdc++.h>
using namespace std;

int longest_subarr_ksum(vector<int> &arr, int target){
    unordered_map<int, int> un_map;
    int sum = 0, max_len=0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        if(sum-target==0){
            max_len = max(max_len, i+1);
        }else{
            if(un_map.find(sum-target)!=un_map.end()){
                max_len = max(max_len, (i-un_map[sum-target]));
            }
            else{
                un_map[sum]=i;
            }
        }
    }
    return max_len;
}

int main(){
    vector<int> mat = {2,1,1,1,1,5,4,-1,2,1,-5,4};
    cout << longest_subarr_ksum(mat, 6);
    return 0;
}