#include<bits/stdc++.h>
#include"bst.cpp"

using namespace std;

TreeNode* findLCA(TreeNode* root, int target1, int target2){
    if(!root)return root;
    if(root->val < target1 && root->val < target2){
        return findLCA(root->right, target1, target2);
    }
    if(root->val > target1 && root->val > target2){
        return findLCA(root->left, target1, target2);
    }
    return root;
}
int main(){
    vector<int> arr = {23,1,34,45,2,4,6,89,78, 63};
    binary_search_tree bst;
    bst.insert_node(arr);
    int target1 = 89, target2=78;
    int ans = findLCA(bst.root, target1, target2)->val;
    cout << ans;
}