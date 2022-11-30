#include<bits/stdc++.h>
#include"../day 16/binary_tree.cpp"

using namespace std;

void getAllPaths(Node* root, vector<int>& dp, vector<vector<int>>& paths){
    if(!root)return;
    dp.push_back(root->val);

    if(!root->left && !root->right){
        paths.push_back(dp);
    }
    else{
        getAllPaths(root->left, dp, paths);
        getAllPaths(root->right, dp, paths);
    }
    dp.pop_back();
}


int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10,11};
    Node* root = buildTree(arr, arr.size());
    vector<vector<int>> paths;
    vector<int> dp;
    getAllPaths(root, dp, paths);

    for(auto it: paths){
        for(auto itr: it){
            cout << itr << " ";
        }
        cout << endl;
    }
}