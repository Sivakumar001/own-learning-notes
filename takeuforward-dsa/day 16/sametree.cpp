#include<bits/stdc++.h>
#include"binary_tree.cpp"

using namespace std;

bool isSame(Node* n, Node* m){
    if(n==nullptr || m==nullptr){
        return n==m;
    }
    return (n->val==m->val && isSame(n->left, m->left) && isSame(n->right, m->right));
}
int main(){
    vector<int> arr = {1,2,3};
    Node* n = buildTree(arr, arr.size());
    Node* m = buildTree(arr, arr.size());
    if(isSame(n, m)){
        cout << "Yes its true";
    }
    else{
        cout << "Nah not same";
    }
}