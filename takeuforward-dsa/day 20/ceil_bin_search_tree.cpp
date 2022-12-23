#include<bits/stdc++.h>
#include"../day 17/binary_tree.cpp"

using namespace std;

int ceil_bintree(TreeNode* root, int key){
    int ceil = -1;
    while(root){
        if(root->val==key){
            ceil=root->val;
            return ceil;
        }
        if(root->val<key){
            root = root->right;
        }
        else{
            ceil = root->val;
            root = root->left;
        }
    }
    return ceil;
}

int main(){
    vector<int> arr = {8,5,12,4,7,10,14};
    int key = 11;
    TreeNode* root = buildTree(arr, arr.size());
    cout << ceil_bintree(root, key);
}