#include<bits/stdc++.h>
#include"bst.cpp"

using namespace std;

TreeNode* search_bst(TreeNode* root, int target){
    while(root && root->val!=target){
        root = root->val>target? root->left:root->right;
    }
    return root;
}

int main(){
    vector<int> arr = {8,5,12,4,7,10,14};
    binary_search_tree bst;
    bst.insert_node(arr);
    int target = 10;
    TreeNode* ans = search_bst(bst.root, target);
    cout << (ans? ans->val:-1);
}