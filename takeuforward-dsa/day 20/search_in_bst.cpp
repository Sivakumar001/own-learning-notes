#include<bits/stdc++.h>
#include"../day 17/binary_tree.cpp"

using namespace std;

TreeNode* search_bst(TreeNode* root, int target){
    while(root && root->val!=target){
        root = root->val>target? root->left:root->right;
    }
    return root;
}

int main(){
    vector<int> arr = {8,5,12,4,7,10,14};
    TreeNode* root = buildTree(arr, arr.size());
    int target = 100;
    TreeNode* ans = search_bst(root, target);
    cout << (ans? ans->val:-1);
}