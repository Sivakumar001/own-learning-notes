#include<bits/stdc++.h>
#include"../day 17/binary_tree.cpp"

using namespace std;

bool isSame(TreeNode* n, TreeNode* m){
    if(n==nullptr || m==nullptr){
        return n==m;
    }
    return (n->val==m->val && isSame(n->left, m->left) && isSame(n->right, m->right));
}
int main(){
    vector<int> arr = {1,2,3};
    TreeNode* n = buildTree(arr, arr.size());
    TreeNode* m = buildTree(arr, arr.size());
    if(isSame(n, m)){
        cout << "Yes its true";
    }
    else{
        cout << "Nah not same";
    }
}