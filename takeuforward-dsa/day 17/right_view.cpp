#include<bits/stdc++.h>
#include"binary_tree.cpp"

using namespace std;

void right_view(TreeNode* root, map<int, int>& ans, int pos=0){
    if(!root){
        return;
    }
    if(ans.find(pos)==ans.end()){
        ans[pos] = root->val;
    }
    right_view(root->right, ans, pos+1);
    right_view(root->left, ans, pos+1);
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    TreeNode* root = buildTree(arr, arr.size());
    map<int, int> ans;
    right_view(root, ans);
    for(auto it: ans){
        cout << it.second << " ";
    }
    return 0;
}