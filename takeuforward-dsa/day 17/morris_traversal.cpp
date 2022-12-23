#include<bits/stdc++.h>
#include"binary_tree.cpp"

using namespace std;
// morris traversal for inorder and preorder without recursion or backtracking
vector<int> getInorder(TreeNode* root){
    vector<int> inorder;
    TreeNode* cur = root;
    while(cur!=nullptr){
        if(cur->left==NULL){
            inorder.push_back(cur->val);
            cur = cur->right;
        }
        else{
            TreeNode* pre = cur->left;
            while(pre->right && pre->right!=cur){
                pre = pre->right;
            }
            if(pre->right==NULL){
                pre->right = cur;
                cur = cur->left;
            }
            else{
                pre->right = nullptr;
                inorder.push_back(cur->val);  // the difference here
                cur = cur->right;
            }
        }
    }
    return inorder;
}

vector<int> getPreorder(TreeNode* root){
    vector<int> preorder;
    TreeNode* cur = root;
    while(cur!=nullptr){
        if(cur->left==NULL){
            preorder.push_back(cur->val);
            cur = cur->right;
        }
        else{
            TreeNode* pre = cur->left;
            while(pre->right && pre->right!=cur){
                pre = pre->right;
            }
            if(pre->right==NULL){
                pre->right = cur;
                preorder.push_back(cur->val);
                cur = cur->left;
            }
            else{
                pre->right = nullptr;
                cur = cur->right;
            }
        }
    }
    return preorder;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7};
    TreeNode* root = buildTree(arr, arr.size());
    vector<int> ans = getPreorder(root);
    for(auto it: ans){
        cout << it << " ";
    }
    return 0;
}
