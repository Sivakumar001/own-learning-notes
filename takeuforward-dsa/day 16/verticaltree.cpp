#include<bits/stdc++.h>
#include"binary_tree.cpp"

using namespace std;

vector<vector<int>> vertical_tree(TreeNode* root){
    vector<vector<int>> ans;
    if(!root)return ans;

    map<int, map<int, multiset<int>>> mpset;
    queue<pair<TreeNode*, pair<int, int>>> q;
    q.push({root, {0, 0}});

    while(!q.empty()){
        auto tmp = q.front();
        q.pop();
        TreeNode* cur = tmp.first;
        int x = tmp.second.first;
        int y = tmp.second.second;
        mpset[x][y].insert(cur->val);

        if(cur->left){
            q.push({cur->left, {x-1, y+1}});
        }

        if(cur->right){
            q.push({cur->right, {x+1, y+1}});
        }
    }

    for(auto x: mpset){
        vector<int> col;
        for(auto y: x.second){
            col.insert(col.end(), y.second.begin(), y.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7};
    TreeNode* rt = buildTree(arr, arr.size());
    vector<vector<int>> ans = vertical_tree(rt);
    for(auto it: ans){
        for(auto itr: it){
            cout << itr << " ";
        }
        cout << endl;
    }
}