#include<bits/stdc++.h>
#include"..\day 16\binary_tree.cpp"

using namespace std;


vector<int> bottom_view(Node* root){
    vector<int> ans;
    if(!root)return ans;

    map<int, int> bottomMap;
    queue<pair<Node*, int>> levelTraversal;
    levelTraversal.push({root, 0});

    while(!levelTraversal.empty()){
        Node* cur_node = levelTraversal.front().first;
        int pos = levelTraversal.front().second;
        levelTraversal.pop();

        bottomMap[pos] = cur_node->val;
        if(cur_node->left){
            levelTraversal.push({cur_node->left, pos-1});
        }
        if(cur_node->right){
            levelTraversal.push({cur_node->right, pos+1});
        }
    }

    for(auto it: bottomMap){
        ans.push_back(it.second);
    }
    return ans;
}

int main(){
    vector<int> arr = {2,3,4,5,6,7,8,9};
    Node* n = buildTree(arr, arr.size());
    vector<int> ans = bottom_view(n);
    for(auto it: ans){
        cout << it << " ";
    }
    return 0;
}