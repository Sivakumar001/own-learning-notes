#include<bits/stdc++.h>
#include"binary_tree.cpp"

using namespace std;

int max_depth(Node* n){
    if(n==nullptr){
        return 0;
    }
    int left = max_depth(n->left);
    int right = max_depth(n->right);

    return 1 + max(left, right);
}

int max_depth(Node* n){
    queue<Node*> q;
    q.push(n);
    int max_height = 0;

    while(!q.empty()){
        max_height++;
        int size = q.size();
        while(size>0){
            Node* tmp = q.front();
            q.pop();size--;
            if(tmp->left)q.push(tmp->left);
            if(tmp->right)q.push(tmp->right);
        }
    }
    return max_height;
}

int main(){
    vector<int> arr= {1,2,3,4,5,6, 7, 8, 9};
    Node* n = buildTree(arr, arr.size());
    cout << max_depth(n);
}