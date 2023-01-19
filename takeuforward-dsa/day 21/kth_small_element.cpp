#include<bits/stdc++.h>
#include"bst.cpp"

using namespace std;

int kth_small(TreeNode* root, int k){
    TreeNode* cur = root;
    int ans = 0;
    while(cur && k){
        if(cur->left==nullptr){
            ans = cur->val;k--;
            cur = cur->right;
        }
        else{
            TreeNode* pre = cur->left;
            while(pre->right!=nullptr && pre->right!=cur){
                pre = pre->right;
            }
            if(pre->right==nullptr){
                pre->right = cur;
                cur = cur->left;
            }
            else{
                pre->right = nullptr;
                ans = cur->val;k--;
                cur = cur->right;
            }
        }
    }
    return ans;
}
int main(){
    vector<int> arr = {5,3,6,2,4,1};
    binary_search_tree bst;
    bst.insert_node(arr);
    int target = 4;
    cout << kth_small(bst.root, target);
}