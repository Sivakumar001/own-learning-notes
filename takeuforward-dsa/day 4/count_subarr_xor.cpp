#include<vector>
#include<unordered_map>
#include<iostream>

using namespace std;

int count_subarr_xor_k(vector<int> &nums, int target){
    unordered_map<int,int> un_map;
    int curr=0,count=0;
    for(int i=0;i<nums.size();i++){
        curr = curr^nums[i];
        if(curr==target){
            count++;
        }
        if(un_map.find(curr^target)!=un_map.end()){
            count+=un_map[curr^target];
        }
        un_map[curr]++;
    }
    return count;
}
int main(){
    vector<int> mat = {4, 2, 2, 6, 4};
    cout << count_subarr_xor_k(mat, 6);
    return 0;
}