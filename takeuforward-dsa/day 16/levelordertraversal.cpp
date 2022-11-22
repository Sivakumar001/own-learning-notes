#include<bits/stdc++.h>
#include"binary_tree.cpp"

using namespace std;

vector<int> levelOrder_traversal(Node* n){
    vector<int> ans;
    queue<Node*> q;
    q.push(n);
    while(!q.empty()){
        Node* tmp = q.front();
        ans.push_back(tmp->val);
        q.pop();
        if(tmp->left)q.push(tmp->left);
        if(tmp->right)q.push(tmp->right);
    }
    return ans;
}

int main(){
    int arr[] = {1,2,3,4,5,6};
    Node* n = buildTree(arr, 6);
    vector<int> ans = levelOrder_traversal(n);
    for(auto it: ans){
        cout << it << " ";
    }
    return 0;
}