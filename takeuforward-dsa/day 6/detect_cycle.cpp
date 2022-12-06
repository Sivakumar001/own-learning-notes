#include<bits/stdc++.h>
#include"linked_list.cpp"

bool detect_cycle(ListNode* head){
    ListNode* fast = head;
    ListNode* slow = head;
    while(fast && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast)return true;
    }
    return false;
}
int main(){
    linked_list l;

    l.addAtTail(1);
    l.addAtTail(2);
    l.addAtTail(3);
    l.addAtTail(4);
    l.addAtTail(5);
    l.addAtTail(6);
    l.addAtTail(7);

    // l.getNodeAtIndex(6)->next = l.getNodeAtIndex(3);

    cout << detect_cycle(l.head);
    return 0;
}