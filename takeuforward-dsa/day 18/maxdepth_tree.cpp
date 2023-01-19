#include<bits/stdc++.h>
#include"../day 17/binary_tree.cpp"

using namespace std;

int max_depth(TreeNode* n){
    if(n==nullptr){
        return 0;
    }
    int left = max_depth(n->left);
    int right = max_depth(n->right);

    return 1 + max(left, right);
}


int main(){
    vector<int> arr= {1,2,3,4,5,6, 7, 8, 9};
    TreeNode* n = buildTree(arr, arr.size());
    cout << max_depth(n);
}