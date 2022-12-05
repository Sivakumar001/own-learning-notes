#include<bits/stdc++.h>
#include"../day 16/binary_tree.cpp"

using namespace std;

vector<int> getInorder(Node* root){
    vector<int> inorder;
    Node* cur = root;
    while(cur!=nullptr){
        if(cur->left==NULL){
            inorder.push_back(cur->val);
            cur = cur->right;
        }
        else{
            Node* pre = cur->left;
            while(pre->right && pre->right!=cur){
                pre = pre->right;
            }
            if(pre->right==NULL){
                pre->right = cur;
                cur = cur->left;
            }
            else{
                pre->right = nullptr;
                inorder.push_back(cur->val);
                cur = cur->right;
            }
        }
    }
    return inorder;
}

vector<int> getPreorder(Node* root){
    vector<int> preorder;
    Node* cur = root;
    while(cur!=nullptr){
        if(cur->left==NULL){
            preorder.push_back(cur->val);
            cur = cur->right;
        }
        else{
            Node* pre = cur->left;
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
    Node* root = buildTree(arr, arr.size());
    vector<int> ans = getPreorder(root);
    for(auto it: ans){
        cout << it << " ";
    }
    return 0;
}
