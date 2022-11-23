#include<bits/stdc++.h>
#include"binary_tree.cpp"

using namespace std;

int check_tree(Node* root){
    if(root==nullptr){
        return 0;
    }
    int left = check_tree(root->left);
    if(left==-1)return -1;
    int right =check_tree(root->right);
    if(right==-1)return -1;
    if(abs(left-right)>1)return -1;
    return 1+max(left, right);
}

int main()
{
    vector<int> arr = {1,2,3,4,5,6,7,7,9,8,0,11,12,13,14, 15};

    Node* n = buildTree(arr, arr.size());
    if(check_tree(n)!=-1)
    {
        cout << "yes it is balanced";
    }
    else
    {
        cout << "No it isnt";
    }
}