#include<bits/stdc++.h>
#include"../day 17/binary_tree.cpp"

using namespace std;

void inorder_traversal(TreeNode* root){
    if(!root)return;
    cout << root->val;
    inorder_traversal(root->left);
    inorder_traversal(root->right);
}

TreeNode* buildBinTree(unordered_map<int, int>& inorder_hash, vector<int>&preorder, int preStart, int preEnd, vector<int>&inorder, int inStart, int inEnd){
    if(preStart>preEnd || inStart>inEnd)return nullptr;

    TreeNode* root = new TreeNode(preorder[preStart]);
    int curRootPos = inorder_hash[preorder[preStart]];
    int nos_on_left = curRootPos-inStart;

    root->left = buildBinTree(inorder_hash, preorder, preStart+1, preStart+nos_on_left, inorder, inStart, curRootPos-1);

    root->right = buildBinTree(inorder_hash, preorder, preStart+nos_on_left+1, preEnd, inorder, curRootPos+1, inEnd);

    return root;
}

TreeNode* create_bintree(vector<int>& inorder, vector<int>& preorder){
    unordered_map<int, int> inorder_hash;

    for(int i=0;i<inorder.size();i++){
        inorder_hash[inorder[i]]=i;
    }

    TreeNode* root = buildBinTree(inorder_hash, preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);

    return root;
}

int main(){
    vector<int> inorder = {4,2,5,1,6,3,7};
    vector<int> preorder = {1,2,4,5,3,6,7};

    TreeNode* root = create_bintree(inorder, preorder);
    inorder_traversal(root);
    return 0;
}