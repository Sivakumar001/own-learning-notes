#include<bits/stdc++.h>
#include"binary_tree.cpp"

using namespace std;

// using recursion
void preorder_traversal(TreeNode* root, vector<int>& vct){
    if(root==nullptr){
        return;
    }
    vct.push_back(root->val);
    preorder_traversal(root->left, vct);
    preorder_traversal(root->right, vct);
}

//using stack
vector<int> preorder_traversal(TreeNode* root){
    vector<int> ans;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
        TreeNode* tmp = st.top();
        st.pop();
        ans.push_back(tmp->val);
        if(tmp->right!=nullptr)st.push(tmp->right);
        if(tmp->left!=nullptr)st.push(tmp->left);
    }
    return ans;
}

int main(){
    vector<int> arr = {1,2,3};
    TreeNode* n = buildTree(arr, arr.size());
    vector<int> ans = preorder_traversal(n);
    for(auto it: ans){
        cout << it << " ";
    }
}