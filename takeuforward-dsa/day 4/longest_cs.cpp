#include<bits/stdc++.h>
using namespace std;

// based on finding first number
// create a set of question
// find the first iteration in the vct from set
// from that find max value
// 100->
// 200->
// 1->2->3->4->
int longest_consecutive_sequence(vector<int> &nums){
    set<int> numSet(nums.begin(), nums.end());
    int lcs=0;
    for(auto iter: nums){
        // check whether if current itr is first seq number
        if(numSet.find(iter-1)==numSet.end()){
            int length=1;
            // go untill seq is continues
            while(numSet.find(iter+length)!=numSet.end()){
                length++;
            }
            lcs = max(lcs, length);
        }
    }
    return lcs;
}

int main(){
    vector<int> question={100,1,200,2,4,3};
    cout << longest_consecutive_sequence(question);
    return 0;
}