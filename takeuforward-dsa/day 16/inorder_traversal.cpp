#include<bits/stdc++.h>
#include"binary_tree.cpp"

using namespace std;
// using recursion
void inorder_traversal(Node* root, vector<int> &arr){
    if(root==nullptr){
        return;
    }
    inorder_traversal(root->left, arr);
    arr.push_back(root->val);
    inorder_traversal(root->right, arr);
}

//using stack
vector<int> inorder_traversal(Node* root){
    vector<int> ans;
    stack<Node*> st;
    while(true){
        if(root!=nullptr){
            st.push(root);
            root = root->left;
        }
        else{
            if(st.empty())break;
            root = st.top();
            ans.push_back(root->val);
            root = root->right;
            st.pop();
        }
    }
    return ans;
}

int main(){
    int arr[] = {1,2,3};
    Node* n = buildTree(arr,3);
    vector<int> ans = inorder_traversal(n);
    // inorder_traversal(n, ans);
    for(auto it: ans){
        cout << it << " ";
    }
}