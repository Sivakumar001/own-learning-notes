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
        // 1, tmp[1]3>2it[0] , 6
        if(tempInterval[1]>=it[0]){
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
    vector<vector<int>> question = {{1,3},{2,5},{8,10}};
    vector<vector<int>> ans = merge_intervals(question);
    for(auto it:ans){
        cout << it[0] << "\t" << it[1];
        cout << "\n";
    }

    return 0;
}