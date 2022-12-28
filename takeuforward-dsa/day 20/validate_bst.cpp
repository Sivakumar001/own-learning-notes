#include<bits/stdc++.h>
#include"bst.cpp"

using namespace std;

bool validate_bst(TreeNode* root, int minima = INT_MIN, int maxima = INT_MAX){
    if(!root)return true;
    if(root->val < minima || root->val > maxima)return false;
    return validate_bst(root->left, minima, root->val) && validate_bst(root->right, root->val, maxima);
}

int main(){
    vector<int> arr = {100, 32, 23, 18, 84, 22, 89};
    binary_search_tree bst;
    // TreeNode* root = buildTree(arr, arr.size());
    bst.insert_node(arr);
    TreeNode* root = bst.root;
    if(validate_bst(root)){
        cout << "this is a valid binary search tree";
    }
    else{
        cout << "no it isnt a bst";
    }
}