#include<bits/stdc++.h>
#include"..\day 17\binary_tree.cpp"

using namespace std;

TreeNode* flatten_to_linked_list(TreeNode* root){
    stack<TreeNode*> stk;
    stk.push(root);
    TreeNode* linkedList= new TreeNode(-1);
    TreeNode* ll = linkedList;
    while (!stk.empty())
    {
        TreeNode* cur = stk.top();
        ll->left = cur;
        stk.pop();
        if(cur->right){
            stk.push(cur->right);
        }
        if(cur->left){
            stk.push(cur->left);
        }
        ll = ll->left;
    }
    return linkedList->left;
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    TreeNode* root = buildTree(arr, arr.size());
    TreeNode* ans = flatten_to_linked_list(root);
    while(ans){
        cout << ans->val << " ";
        ans = ans->left;
    }
}