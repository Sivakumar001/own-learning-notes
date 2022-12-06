#include<bits/stdc++.h>
#include"linked_list.cpp"

using namespace std;

ListNode* find_intersection(ListNode* list1, ListNode* list2){
    ListNode* l1 = new ListNode(-1);
    ListNode* l2 = new ListNode(-1);

    l1->next = list1;
    l2->next = list2;

    while(l1!=l2){
        l1 = (l1==nullptr)? list2: l1->next;
        l2 = (l2==nullptr)? list1: l2->next;
    }
    return l1;
}

int main(){
    linked_list l1;
    l1.addAtTail(1);
    l1.addAtTail(3);
    l1.addAtTail(1);

    linked_list l2;
    l2.addAtTail(3);
    l2.addAtTail(2);
    l2.addAtTail(4);

    l1.getNodeAtIndex(2)->next = l2.getNodeAtIndex(1);

    ListNode* ans = find_intersection(l1.head, l2.head);
    cout << ans->value;
    return 0;
}