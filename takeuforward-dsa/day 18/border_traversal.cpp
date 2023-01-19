#include<bits/stdc++.h>
#include"../day 17/binary_tree.cpp"

using namespace std;

bool isLeaf(TreeNode* root){
    // true if left and right are null
    return !root->left && !root->right;
}

void left_border(TreeNode* root ,vector<int>& ans_arr){
    TreeNode* cur = root;
    while(cur){
        if(!isLeaf(cur))ans_arr.push_back(cur->val);
        if(cur->left){
            cur = cur->left;
        }
        else{
            cur = cur->right;
        }
    }
}

void leaf_nodes(TreeNode* root, vector<int>& ans_arr){
    if(isLeaf(root)){
        ans_arr.push_back(root->val);
        return;
    }
    if(root->left)leaf_nodes(root->left, ans_arr);
    if(root->right)leaf_nodes(root->right, ans_arr);
}

void right_border(TreeNode* root ,vector<int>& ans_arr){
    TreeNode* cur = root->right;
    vector<int> tmp;
    while(cur){
        if(!isLeaf(cur))tmp.push_back(cur->val);
        if(cur->right){
            cur = cur->right;
        }
        else{
            cur = cur->left;
        }
    }
    for(int i=tmp.size()-1;i>=0;i--){
        ans_arr.push_back(tmp[i]);
    }
}

vector<int> boundary_traversal(TreeNode* root){
    vector<int> ans_arr;
    if(!root)return ans_arr;

    left_border(root, ans_arr);
    leaf_nodes(root, ans_arr);
    right_border(root, ans_arr);

    return ans_arr;
}
int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    TreeNode* root = buildTree(arr, arr.size());
    vector<int> ans = boundary_traversal(root);
    for(auto itr: ans){
        cout << itr << " ";
    }
}