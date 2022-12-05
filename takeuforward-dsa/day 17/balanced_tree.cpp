#include<bits/stdc++.h>
#include"../day 16/binary_tree.cpp"

using namespace std;

int is_balanced(Node* root){
    if(!root)return 0;

    int left = is_balanced(root->left);
    int right = is_balanced(root->right);

    if(abs(left-right)>1)return -1;
    if(left==-1 || right==-1)return -1;

    return max(left, right)+1;
}


int main(){
    vector<int> arr = {1,2,3,4,5};
    Node* root = buildTree(arr, arr.size());
    if(is_balanced(root)!=-1){
        cout << "it is balanced";
    }
    else{
        cout << "No unbalanced";
    }
}