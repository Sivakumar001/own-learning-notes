#include<bits/stdc++.h>
#include"linked_list.cpp"

using namespace std;

int find_middle(linked_list &l){
    Node *head = l.head;
    Node *node1 = head;
    Node *node2 = head;

    while(node2!=nullptr && node2->next!=nullptr){
        node1 = node1->next;
        node2 = node2->next->next;
    }
    return node1->value;
}
int main(){
    linked_list l;
    l.addAtTail(1);
    l.addAtTail(2);
    l.addAtTail(3);
    l.addAtTail(4);
    l.addAtTail(5);
    l.addAtTail(6);
    cout << find_middle(l);
    return 0;
}