#include<bits/stdc++.h>
#include"..\day 5\linked_list.cpp"
#include"..\day 16\binary_tree.cpp"

using namespace std;

void preorder_traversal(TreeNode* root){
    stack<TreeNode*> stk;
    linked_list l;
    stk.push(root);
    while (!stk.empty())
    {
        TreeNode* cur = stk.top();
        stk.pop();
        cout << cur->val << " ";
        l.addAtTail(cur->val);
        if(cur->right){
            stk.push(cur->right);
        }
        if(cur->left){
            stk.push(cur->left);
        }
    }
    l.printAll();
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    TreeNode* root = buildTree(arr, arr.size());
    preorder_traversal(root);
}