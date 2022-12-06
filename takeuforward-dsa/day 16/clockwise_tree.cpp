#include<bits/stdc++.h>
#include"binary_tree.cpp"

using namespace std;

bool isLeaf(TreeNode* root)
{
    return !root->left && !root->right;
}

void addLeftSide(TreeNode*root, vector<int>& vct)
{
    TreeNode* cur = root->left;
    while(cur){
        if(!isLeaf(cur))vct.push_back(cur->val);
        if(cur->left){
            cur = cur->left;
        }
        else{
            cur = cur->right;
        }
    }
}

void addLeaves(TreeNode* root, vector<int>& vct){
    if(isLeaf(root)){
        vct.push_back(root->val);
        return;
    }
    if(root->left)addLeaves(root->left, vct);
    if(root->right)addLeaves(root->right, vct);
}

void addRightSide(TreeNode* root, vector<int>& vct){
    TreeNode* cur = root->right;
    vector<int> st;
    while(cur){
        if(!isLeaf(root))st.push_back(cur->val);
        if(cur->right){
            cur = cur->right;
        }
        else{
            cur = cur->left;
        }
    }
    for(int i=st.size()-1;i>=0;i--){
        vct.push_back(st[i]);
    }
}

vector<int> rotate_anticlockwise(TreeNode* root){
    vector<int> ans;
    if(root==nullptr)return ans;
    if(!isLeaf(root))ans.push_back(root->val);
    addLeftSide(root, ans);
    addLeaves(root, ans);
    addRightSide(root, ans);
    return ans;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10,11,12,13};
    TreeNode* n = buildTree(arr, arr.size());
    vector<int> ans = rotate_anticlockwise(n);
    for(auto it: ans){
        cout << it << " ";
    }
}