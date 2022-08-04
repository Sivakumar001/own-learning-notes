#include<bits/stdc++.h>
using namespace std;

int best_time_to_buy_stock(vector<int> &nums){
    int profit=0, n=nums.size(), j=0, max_profit=0;
    for(int i=1;i<n;i++){
        if(nums[j]<nums[i]){
            profit = nums[i]-nums[j];
            max_profit = max(max_profit, profit);
        }else{
            j=i;
        }
    }
    return max_profit;
}

int main(){
    vector<int> question={7,1,5,3,6,4};
    cout << best_time_to_buy_stock(question);
    return 0;
}