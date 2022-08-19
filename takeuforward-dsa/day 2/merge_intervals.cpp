#include<bits/stdc++.h>
using namespace std;

// if first of new vct less than last vct then merge
// else put it as second pos in number table

vector<vector<int>> merge_intervals(vector<vector<int>> &intervals){
    vector<vector<int>> ans;
    if(intervals.size()==0){return ans;}
    
    sort(intervals.begin(), intervals.end());
    int n=intervals.size();
    
    vector<int> tempInterval=intervals[0];
    
    for(auto it: intervals){
        if(it[1]>=tempInterval[0]){
            tempInterval[1]=max(it[1], tempInterval[1]);
        }else{
            ans.push_back(tempInterval);
            tempInterval = it;
        }
    }
    ans.push_back(tempInterval);
    return ans;
}

int main(){
    vector<vector<int>> question = {{1,4},{4,5}};
    vector<vector<int>> ans = merge_intervals(question);
    for(auto it:ans){
        cout << it[0] << "\t" << it[1];
        cout << "\n";
    }

    return 0;
}