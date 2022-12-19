#include<bits/stdc++.h>
#include"../day 17/binary_tree.cpp"

using namespace std;

void find_parents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& get_parents){
    if(!root)return;
    queue<TreeNode*> treequeue;
    treequeue.push(root);
    while(!treequeue.empty()){
        TreeNode* cur = treequeue.front();treequeue.pop();
        if(cur->left){
            get_parents[cur->left] = cur;
            treequeue.push(cur->left);
        }
        if(cur->right){
            get_parents[cur->right] = cur;
            treequeue.push(cur->right);
        }
    }
    return;
}


int find_min_time(TreeNode* root){
    if(!root)return 0;
    unordered_map<TreeNode*, TreeNode*> get_parents;
    find_parents(root, get_parents);

    int distance = 0;
    unordered_map<TreeNode*, bool> visited;
    queue<TreeNode*> bfs;
    visited[root]=1;
    bfs.push(root);

    while(!bfs.empty()){
        int size = bfs.size();
        distance++;
        for(int i=0;i<size;i++){
            TreeNode* cur = bfs.front();bfs.pop();
            if(cur->left && !visited[cur->left]){
                visited[cur->left]=1;
                bfs.push(cur->left);
            }
            if(cur->right && !visited[cur->right]){
                visited[cur->right]=1;
                bfs.push(cur->right);
            }
            if(get_parents[cur] && !visited[get_parents[cur]]){
                visited[get_parents[cur]]=1;
                bfs.push(get_parents[cur]);
            }
        }
    }

    return distance;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8};
    TreeNode* node = buildTree(arr, arr.size());

    int min_time = 0;
    cout << find_min_time(node);
}