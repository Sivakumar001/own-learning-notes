#include<bits/stdc++.h>
#include"binary_tree.cpp"

using namespace std;

// using recursion
void preorder_traversal(Node* root, vector<int>& vct){
    if(root==nullptr){
        return;
    }
    vct.push_back(root->val);
    preorder_traversal(root->left, vct);
    preorder_traversal(root->right, vct);
}

//using stack
vector<int> preorder_traversal(Node* root){
    vector<int> ans;
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        Node* tmp = st.top();
        st.pop();
        ans.push_back(tmp->val);
        if(tmp->right!=nullptr)st.push(tmp->right);
        if(tmp->left!=nullptr)st.push(tmp->left);
    }
    return ans;
}

int main(){
    int arr[] = {1,2,3};
    Node* n = buildTree(arr, 3);
    vector<int> ans = preorder_traversal(n);
    for(auto it: ans){
        cout << it << " ";
    }
}