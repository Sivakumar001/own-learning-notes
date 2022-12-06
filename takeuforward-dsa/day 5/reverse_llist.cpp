#include<bits/stdc++.h>
#include"linked_list.cpp"

void reverse_list(linked_list &l){
    ListNode *head = l.head;

    ListNode *current = head;
    ListNode *prev = nullptr;
    ListNode *nxt = nullptr;

    while(current){
        nxt = current->next;
        current->next = prev;
        prev = current;
        current = nxt;
    }
    l.head = prev;
    return;
}

ListNode* reverse_list(ListNode* head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    ListNode* newHead = reverse_list(head->next);
    ListNode* headNext = head->next;
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