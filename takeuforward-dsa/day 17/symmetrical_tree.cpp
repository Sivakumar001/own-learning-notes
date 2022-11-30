#include<bits/stdc++.h>
#include"../day 16/binary_tree.cpp"

using namespace std;

bool isSymmetricHelper(Node* left, Node* right){
    if(!left || !right){
        return left==right;
    }
    if(left->val!=right->val)return false;
    return isSymmetricHelper(left->right, right->left) && isSymmetricHelper(left->left, right->right);
}

bool isSymmetric(Node* root){
    return !root || isSymmetricHelper(root->left, root->right);
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7};
    Node* root = buildTree(arr, arr.size());
    if(isSymmetric(root)){
        cout << "Yes its symmetric";
    }
    else{
        cout << "No not symmetric";
    }
    return 0;
}