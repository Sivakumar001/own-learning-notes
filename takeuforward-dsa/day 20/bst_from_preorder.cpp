#include<bits/stdc++.h>
#include"bst.cpp"


using namespace std;

TreeNode* create_helper(vector<int>& arr, int& i, int ub){
    if(i==arr.size() || arr[i]>ub)return nullptr;
    TreeNode* root = new TreeNode(arr[i]);
    i++;
    root->left = create_helper(arr, i, root->val);
    root->right = create_helper(arr, i, ub);
    return root;
}


TreeNode* create_bst(vector<int> arr){
    int i=0;
    return create_helper(arr, i, INT_MAX);
}

void postorder(TreeNode* root){
    if(!root)return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val;
}

int main(){
    vector<int> arr = {8,5,1,7,10,12};
    TreeNode* root = create_bst(arr);
    postorder(root);
}