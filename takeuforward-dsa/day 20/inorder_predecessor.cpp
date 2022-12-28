#include<bits/stdc++.h>
#include"bst.cpp"

using namespace std;

TreeNode* get_predecessor(TreeNode* root, int target){
    TreeNode* ans = nullptr;
    while(root){
        if(root->val > target){
            root = root->left;
        }
        else{
            ans = root;
            root = root->right;
        }
    }
    return ans;
}

TreeNode* get_sucessor(TreeNode* root, int target){
    TreeNode* ans = nullptr;
    while(root){
        if(root->val > target){
            ans = root;
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {8,5,1,7,10,12};
    binary_search_tree bst;
    bst.insert_node(arr);
    cout << get_predecessor(bst.root, 4)->val << endl;
    cout << get_sucessor(bst.root, 4)->val << endl;
}