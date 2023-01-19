#include<bits/stdc++.h>
#include"binary_tree.cpp"

using namespace std;

// This level order traversal works but queue takes extra space compared

// to recursion traversal pre/in/postorder.

vector<int> left_view(TreeNode* root){
    vector<int> ans;
    if(!root)return ans;

    map<int, int> leftMap;
    queue<pair<TreeNode*, int>> levelTraversal;
    levelTraversal.push({root, 0});

    while(!levelTraversal.empty()){
        TreeNode* cur = levelTraversal.front().first;
        int pos = levelTraversal.front().second;
        levelTraversal.pop();

        if(leftMap.find(pos)==leftMap.end()){
            leftMap[pos] = cur->val;
        }

        if(cur->left){
            levelTraversal.push({cur->left, pos+1});
        }
        if(cur->right){
            levelTraversal.push({cur->right, pos+1});
        }
    }

    for(auto it: leftMap){
        ans.push_back(it.second);
    }

    return ans;
}

void left_view(TreeNode* root, map<int, int>& ans, int pos=0){
    if(!root){
        return;
    }
    if(ans.find(pos)==ans.end()){
        ans[pos] = root->val;
    }
    if(root->left){
        left_view(root->left, ans, pos+1);
    }
    if(root->right){
        left_view(root->right, ans, pos+1);
    }
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    TreeNode* question = buildTree(arr, arr.size());
    vector<int> ans = left_view(question);
    map<int, int> cur_map;

    left_view(question, cur_map);

    for(auto it: cur_map){
        cout << it.second << " ";
    }

    for(auto itr: ans){
        cout << itr << " ";
    }
}