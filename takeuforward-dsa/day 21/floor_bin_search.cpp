#include<bits/stdc++.h>
#include"bst.cpp"

using namespace std;

int floor_bintree(TreeNode* root, int target){
    int floor = -1;
    while(root){
        if(root->val==target){
            floor = target;
            return floor;
        }
        if(root->val>target){
            root = root->left;
        }
        else{
            floor = root->val;
            root = root->right;
        }
    }
    return floor;
}

int main(){
    vector<int> arr = {13,12,17,20,10,9,8,7,3,2,1};
    int target = 11;
    binary_search_tree bst;
    bst.insert_node(arr);
    cout << floor_bintree(bst.root, target);
}