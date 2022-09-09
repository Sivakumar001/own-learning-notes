#include<bits/stdc++.h>
#include"linked_list.cpp"

using namespace std;

Node* find_start_of_cycle(Node* head){
    if(head==nullptr)return head;
    Node* slow = head;
    Node* fast = head;

    while(fast!=nullptr){
        fast = fast->next;
        if(fast!=nullptr)fast = fast->next;
        slow = slow->next;
        if(slow==fast)break;
    }

    fast = head;
    while(slow && fast && slow!=fast){
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
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
    l.addAtTail(8);

    // l.getNodeAtIndex(7)->next = l.getNodeAtIndex(3);
    cout << find_start_of_cycle(l.head)->value;
    return 0;
}