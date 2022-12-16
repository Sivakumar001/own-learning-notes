#include<bits/stdc++.h>
#include"../day 16/binary_tree.cpp"

using namespace std;

int getLeft(TreeNode* root){
    if(!root)return 0;
    return 1+getLeft(root->left);
}

int getRight(TreeNode* root){
    if(!root)return 0;
    return 1+getRight(root->right);
}

int count_complete(TreeNode* root){
    if(!root)return 0;
    int left = getLeft(root);
    int right = getRight(root);

    if(left==right){
        return (int)pow(2, left)-1;
    }
    return 1+count_complete(root->left)+count_complete(root->right);
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    TreeNode* root = buildTree(arr, arr.size());

    cout << count_complete(root);
}