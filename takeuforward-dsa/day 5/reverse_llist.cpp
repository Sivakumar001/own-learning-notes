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
int main(){
    linked_list l;
    l.addAtTail(1);
    l.addAtTail(2);
    l.addAtTail(3);
    reverse_list(l);
    l.printAll();
    return 0;
}