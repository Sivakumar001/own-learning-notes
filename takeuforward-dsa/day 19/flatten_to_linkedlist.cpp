#include<bits/stdc++.h>
#include"..\day 17\binary_tree.cpp"

using namespace std;

TreeNode* flatten_to_linked_list(TreeNode* root){
    TreeNode* cur = root;
    while(cur){
        if(cur->left!=nullptr){
            TreeNode* pre = cur->left;
            while(pre->right){
                pre = pre->right;
            }
            pre->right = cur->right;
            cur->right = cur->left;
        }
        cur = cur->right;
    }
    return root;
}

int main(){
    vector<int> arr = {12,5,3,6,7,11,34,23,35};
    TreeNode* root = buildTree(arr, arr.size());
    TreeNode* ans = flatten_to_linked_list(root);
    while(ans){
        cout << ans->val << " ";
        ans = ans->right;
    }
}