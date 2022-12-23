#include<bits/stdc++.h>
#include"../day 17/binary_tree.cpp"

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
    vector<int> arr = {8,5,12,4,7,10,14};
    int target = 11;
    TreeNode* root = buildTree(arr, arr.size());
    cout << floor_bintree(root, target);
}