#include<bits/stdc++.h>
#include"../day 16/binary_tree.cpp"

using namespace std;

void preorder_traversal(TreeNode* root){
    if(!root)return;
    cout << root->val << " ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void childSum(TreeNode* root){
    if(!root)return;
    int child=0;
    if(root->left){
        child += root->left->val;
    }
    if(root->right){
        child+= root->right->val;
    }

    if(child>=root->val){
        root->val = child;
    }
    else{
        if(root->left){
            root->left->val = child;
        }
        else if(root->right){
            root->right->val = child;
        }
    }
    childSum(root->left);
    childSum(root->right);
}

int main(){
    vector<int> arr = {10,3,2,4,2,6,3};
    TreeNode* root = buildTree(arr, arr.size());
    childSum(root);
    preorder_traversal(root);
    return 0;
}