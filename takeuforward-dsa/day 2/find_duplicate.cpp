#include<bits/stdc++.h>
using namespace std;

int duplicate_number(vector<int> &nums){
    //floyd tortoise and hare algorithm
    int slow=0,fast=0;
    while(true){
        slow = nums[slow];
        fast = nums[nums[fast]];
        if(slow==fast){break;}
    }
    fast=0;
    while(slow!=fast){
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

int main(){
    vector<int> question={1,3,4,2,2};
    cout << duplicate_number(question);
    return 0;
}