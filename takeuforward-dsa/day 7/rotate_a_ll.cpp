#include<bits/stdc++.h>
#include"linked_list.cpp"

using namespace std;

Node* reverse_list(Node* head){
    if(head==nullptr || head->next==nullptr)return head;
    Node* prev = nullptr;
    Node* nxt = nullptr;
    while(head){
        nxt = head->next;
        head->next = prev;
        prev = head;
        head = nxt;
    }
    return prev;
}

Node* rotate_list(Node* head, int k){
    Node* tmp = head;
    int len=0;
    while(tmp){
        tmp = tmp->next;
        len++;
    }

    if(head==nullptr|| head->next==nullptr || k==0)return head;
    Node* fast = head;
    Node* slow = head;

    for(int i=0;i<k%len;i++){
        fast = fast->next;
    }

    while(fast->next!=nullptr){
        fast = fast->next;
        slow = slow->next;
    }

    fast->next = head;
    head = slow->next;
    slow->next = nullptr;

    return head;
}

int main(){
    linked_list l;
    l.addAtTail(10);
    l.addAtTail(20);
    // l.addAtTail(30);

    l.head = rotate_list(l.head, 1);

    l.printAll();
    return 0;
}