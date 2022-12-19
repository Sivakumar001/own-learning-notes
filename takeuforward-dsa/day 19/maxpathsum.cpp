#include<bits/stdc++.h>
#include"../day 17/binary_tree.cpp"

using namespace std;

int max_path_sum(TreeNode* root, int& sum){
    if(root==nullptr){
        return 0;
    }

    int left = max(0, max_path_sum(root->left, sum));
    int right = max(0, max_path_sum(root->right, sum));
    sum = max(sum, (root->val+left+right));
    return root->val+max(left, right);
}

int main(){
    vector<int> arr = {1,2,-1,4,5,6};
    TreeNode* n = buildTree(arr, arr.size());
    int max_sum = 0;
    max_path_sum(n, max_sum);
    cout << max_sum;
    return 0;
}