#include<bits/stdc++.h>
#include"../day 20/bst.cpp"

using namespace std;

class NodeSize{
    public:
    int mini;
    int maxi;
    int size;
    NodeSize(int m, int x, int s){
        mini = m;
        maxi = x;
        size = s;
    }
};

NodeSize max_size_helper(TreeNode* root){
    if(!root){
        return NodeSize(INT_MAX, INT_MIN, 0);
    }
    auto left = max_size_helper(root->left);
    auto right = max_size_helper(root->right);

    if(left.maxi<root->val && right.mini>root->val){
        // this is valid bst
        return NodeSize(min(root->val, left.mini), max(root->val, right.maxi), left.size+right.size+1);
    }
    return NodeSize(INT_MIN, INT_MAX, max(left.size,right.size));
}

int get_max_size(TreeNode* root){
    return max_size_helper(root).size;
}

int main(){
    vector<int> arr = {8,4,3,2,5,7,6,10,19,23,12,13,45,23};
    binary_search_tree bst;
    bst.insert_node(arr);
    cout << get_max_size(bst.root);
}