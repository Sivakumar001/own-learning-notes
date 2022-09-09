#include<bits/stdc++.h>
#include"linked_list.cpp"

using namespace std;

Node* merge_two_list(Node* a, Node* b){
    Node* res = new Node(-1);
    Node* tmp = res;
    while(a!=nullptr || b!=nullptr){
        if(a->value < b->value){
            tmp->next = a;
            a = a->next;
        }else{
            tmp->next = b;
            b = b->next;
        }
    }
    if(a!=nullptr){
        tmp->next = a;
        a = a->next;
    }else{
        tmp->next = b;
        b = b->next;
    }
    return res->next;
}

Node* flatten(Node* root){
    if(root==nullptr && root->next ==nullptr)return root;
    root->next = flatten(root->next);
    root = merge_two_list(root, root->next);//bottom
    return root;
}
int main(){
    return 0;
}