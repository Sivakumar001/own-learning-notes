#include<bits/stdc++.h>
#include"../day 17/binary_tree.cpp"

using namespace std;

void postorder_traversal(TreeNode* root){
    if(!root)return;
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    cout << root->val;
}

TreeNode* create_bintreeHelper(unordered_map<int,int>& inorder_hash, vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd){
    if(inStart>inEnd || postStart>postEnd)return nullptr;

    TreeNode* root = new TreeNode(postorder[postEnd]);
    int curRootPos = inorder_hash[postorder[postEnd]];
    int no_of_left = curRootPos-inStart;

    root->left = create_bintreeHelper(inorder_hash, inorder, inStart, curRootPos-1, postorder, postStart, postStart+no_of_left-1);
    root->right = create_bintreeHelper(inorder_hash, inorder, curRootPos+1, inEnd, postorder, postStart+no_of_left, postEnd-1);

    return root;
}

TreeNode* create_bintree(vector<int>& inorder, vector<int>& postorder){
    unordered_map<int, int> inorder_hash;
    for(int i=0;i<inorder.size();i++){
        inorder_hash[inorder[i]] = i;
    }
    TreeNode* root = create_bintreeHelper(inorder_hash, inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);

    return root;
}
int main(){
    vector<int> inorder = {4,2,5,1,6,3,7};
    vector<int> postorder = {4,5,2,6,7,3,1};
    TreeNode* root = create_bintree(inorder, postorder);
    postorder_traversal(root);
    return 0;
}