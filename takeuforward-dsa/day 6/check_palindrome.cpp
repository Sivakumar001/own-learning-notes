#include<bits/stdc++.h>
#include"linked_list.cpp"

using namespace std;

bool check_palindrome(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;
    // middle of LL
    while(fast->next && fast ){
        slow = slow->next;
        fast = fast->next->next;
    }
    // reverse a LL
    ListNode* prev = nullptr;
    ListNode* curr = slow->next;
    ListNode* nxt = nullptr;
    while(curr){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    slow->next = prev;

    // traversal of slow/fast ptr
    fast = head;
    slow = slow->next;

    while(slow!=nullptr){
        if(fast->value!=slow->value)return false;
        slow = slow->next;
        fast = fast->next;
    }
    return true;
}

int main(){
    linked_list l;

    l.addAtTail(1);
    l.addAtTail(2);
    l.addAtTail(3);
    l.addAtTail(3);
    l.addAtTail(2);
    l.addAtTail(1);

    cout << check_palindrome(l.head);
    return 0;
}