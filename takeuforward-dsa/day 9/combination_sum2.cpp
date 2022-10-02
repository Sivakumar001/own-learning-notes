#include<bits/stdc++.h>

using namespace std;

void findCombinationSum2(vector<vector<int>> &ans, vector<int> &candidates, vector<int> &dummy, int target, int index=0){
    if(target==0){
        ans.push_back(dummy);
        return;
    }
    
    for(int i=index; i<candidates.size();i++){
        if(i>index && candidates[i]==candidates[i-1])continue;
        if(candidates[i]>target)break;
        dummy.push_back(candidates[i]);
        findCombinationSum2(ans, candidates, dummy, target-candidates[i], i+1);
        dummy.pop_back();
    }
    return;
}

int main(){
    vector<int> candidates={10,1,2,7,6,1,5};
    int target = 8;
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> answer;
    vector<int> dummy;
    findCombinationSum2(answer, candidates, dummy, target);
    for(auto it: answer){
        for(auto itr: it){
            cout << itr << " ";
        }cout << endl;
    }
    return 0;
}