#include<bits/stdc++.h>
using namespace std;
// dutch national flag algorithm
// two pointer approach

void sort012(vector<int> &nums){
    if(nums.size()==1){return;}
    int low=0, high=nums.size()-1, i=0;
    for(i=0; i<=high; i++){
        if(nums[i]==2){
            swap(nums[high], nums[i]);
            high--;
        }
        
        if(nums[i]==0){
            swap(nums[low], nums[i]);
            low++;
        }
    }
}
int main(){
    vector<int> ans = {0};
    sort012(ans);
    for(auto it: ans){
        cout << it << "\t";
    }
    return 0;
}