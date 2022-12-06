#include<bits/stdc++.h>
#include"linked_list.cpp"

using namespace std;

ListNode* reverse_list(ListNode* head){
    if(head==nullptr || head->next==nullptr)return head;
    ListNode* prev = nullptr;
    ListNode* nxt = nullptr;
    while(head){
        nxt = head->next;
        head->next = prev;
        prev = head;
        head = nxt;
    }
    return prev;
}

ListNode* rotate_list(ListNode* head, int k){
    ListNode* tmp = head;
    int len=0;
    while(tmp){
        tmp = tmp->next;
        len++;
    }

    if(head==nullptr|| head->next==nullptr || k==0)return head;
    ListNode* fast = head;
    ListNode* slow = head;

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