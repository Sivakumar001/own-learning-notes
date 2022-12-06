#include<bits/stdc++.h>
#include"../day 16/binary_tree.cpp"

using namespace std;

bool findPath(TreeNode* root, vector<int>& paths, int value){
    if(!root)return false;
    paths.push_back(root->val);
    if(root->val==value){
        return true;
    }
    if(findPath(root->left, paths, value)){return true;}
    if(findPath(root->right, paths, value)){return true;}
    paths.pop_back();
    return false;
}
int main(){
    vector<int> arr = {1,2,3,4,5,6,7};
    TreeNode* n = buildTree(arr, arr.size());
    vector<int> dp;
    int val = 7;
    findPath(n, dp, val);
    for(auto it: dp){
        cout << it << " ";
    }
    return 0;
}