#include<bits/stdc++.h>
#include"binary_tree.cpp"

int diameter_tree(TreeNode* n, int& diameter){
    if(n==nullptr){
        return 0;
    }
    int left = diameter_tree(n->left, diameter);
    int right = diameter_tree(n->right, diameter);
    diameter = max(diameter, left+right);
    return 1 + max(left, right);
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,0,11,12,13,14,15, 13,20};

    TreeNode* n = buildTree(arr, arr.size());
    int max_diameter = 0;
    diameter_tree(n, max_diameter);
    cout << max_diameter;
}