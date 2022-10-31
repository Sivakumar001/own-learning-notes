#include<bits/stdc++.h>
using namespace std;
// kadanae algo or sliding window
// if the max of sum is lesser than the iterator itself
// throw the subarr collection and start at current itr
// this method is called sliding window

int kadanae_algo(vector<int> &nums){
    int cur_sum=0,max_sum=0;
    for(int i=0;i<nums.size();i++){
        cur_sum = max(nums[i], cur_sum+nums[i]);
        max_sum = max(max_sum, cur_sum);
    }
    return max_sum;
}

// what is this complication
pair<vector<int>, int> kandane_algorithm(vector<int> &nums){
    int n=nums.size(), sum=0, i, j=0, k=0, max_sum=INT16_MIN;
    pair<vector<int>, int> ans_pair = make_pair(nums, max_sum);
    if(nums.size()==1){return ans_pair;}

    for(i=0;i<n;i++){
        // sum += nums[i];
        // if(sum<nums[i]){
        //     j=i;
        //     sum=nums[i];
        // }
        sum = max(nums[i], sum+nums[i]);
        if(sum==nums[i]){
            j=i;
        }
        max_sum = max(max_sum, sum);
        if(max_sum==sum){
            k=i;
        }
    }
    vector<int> ans(nums.begin()+j, nums.begin()+k+1);

    return ans_pair = make_pair(ans, max_sum);
}
// 1,-3,2,1,-1
// -2,1,-3,4,-1,2,1,-5,4

int main(){
    vector<int> question = {-2,1,-3,4,-1,2,1,-5,4};
    pair<vector<int>, int> answer;
    answer = kandane_algorithm(question);
    for(auto it: answer.first){
        cout << it << " ";
    }
    cout << "\n" << answer.second;
    return 0;
}