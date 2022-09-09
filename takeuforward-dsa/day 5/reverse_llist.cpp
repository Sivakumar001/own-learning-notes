#include<bits/stdc++.h>
#include"linked_list.cpp"

void reverse_list(linked_list &l){
    Node *head = l.head;

    Node *current = head;
    Node *prev = nullptr;
    Node *nxt = nullptr;

    while(current){
        nxt = current->next;
        current->next = prev;
        prev = current;
        current = nxt;
    }
    l.head = prev;
    return;
}

Node* reverse_list(Node* head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    Node* newHead = reverse_list(head->next);
    Node* headNext = head->next;
    headNext->next = head;
    head->next = nullptr;
    return newHead;
}

int main(){
    linked_list l;
    l.addAtTail(1);
    l.addAtTail(2);
    l.addAtTail(3);
    // reverse_list(l);
    l.head = reverse_list(l.head);
    l.printAll();
    return 0;
}