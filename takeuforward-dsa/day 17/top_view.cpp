#include<bits/stdc++.h>
#include"..\day 16\binary_tree.cpp"

using namespace std;

vector<int> top_viewtree(TreeNode* root){
    vector<int> ans;
    map<int, int> mpset;
    queue<pair<TreeNode*, int>> que;
    que.push({root, 0});
    while(!que.empty()){
        TreeNode* tmp = que.front().first;
        int pos = que.front().second;
        que.pop();
        if(mpset.find(pos)==mpset.end()){
            mpset[pos] = tmp->val;
        }
        if(tmp->left){
            que.push({tmp->left, pos-1});
        }
        if(tmp->right){
            que.push({tmp->right, pos+1});
        }
    }
    for(auto it: mpset){
        ans.push_back(it.second);
    }
    return ans;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    TreeNode* n = buildTree(arr, arr.size());
    vector<int> ans=top_viewtree(n);
    for(auto it: ans){
        cout << it << " ";
    }
    return 0;
}