#include<bits/stdc++.h>
#include"bst.cpp"

using namespace std;

int ceil_bintree(TreeNode* root, int key){
    int ceil = -1;
    while(root){
        if(root->val==key){
            ceil=root->val;
            return ceil;
        }
        if(root->val<key){
            root = root->right;
        }
        else{
            ceil = root->val;
            root = root->left;
        }
    }
    return ceil;
}

int main(){
    vector<int> arr = {8,5,12,4,7,10,14};
    binary_search_tree bst;
    bst.insert_node(arr);
    int key = 11;
    cout << ceil_bintree(bst.root, key);
}