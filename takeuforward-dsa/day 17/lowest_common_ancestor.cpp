#include<bits/stdc++.h>
#include"../day 16/binary_tree.cpp"

using namespace std;

Node* findCommonAncestor(Node* root, int x, int y, int& common){
    if(root==NULL || root->val==x || root->val==y){
        return root;
    }
    Node* left = findCommonAncestor(root->left, x, y, common);
    Node* right = findCommonAncestor(root->right, x, y, common);

    if(!left){
        return right;
    }
    else if(!right){
        return left;
    }
    else{
        common = root->val;
        return root;
    }
}

int main(){
    vector<int> arr = {1,2,3,4,5,6};
    Node* root = buildTree(arr, arr.size());
    int common_ancestor = 0;
    int x=4, y=5;
    findCommonAncestor(root, x, y, common_ancestor);
    cout << common_ancestor;
}