#include<bits/stdc++.h>
using namespace std;

int best_time_to_buy_stock(vector<int> &nums){
    int profit=0, n=nums.size(), buy=0, max_profit=0;

    for(int sell=1;sell<n;sell++){
        //check whether the user gains profit
        if(nums[buy]<nums[sell]){
            profit = nums[sell]-nums[buy];
            max_profit = max(max_profit, profit);
        }else{
            // if sell cost is less than buy cost then
            // buy on the sell day to gain max profit
            buy=sell;
        }
    }
    return max_profit;
}

int main(){
    vector<int> question={7,1,5,3,6,4};
    cout << best_time_to_buy_stock(question);
    return 0;
}