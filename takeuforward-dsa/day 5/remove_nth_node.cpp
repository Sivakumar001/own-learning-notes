#include<bits/stdc++.h>
#include"linked_list.cpp"

void remove_at_nth(linked_list &l, int n){
    Node* node1 = l.head;
    Node* node2 = l.head;
    for(int i=1;i<=n;i++){
        node1 = node1->next;
    }

    while(node1->next){
        node1 = node1->next;
        node2 = node2->next;
    }
    
    node1 = node2->next;
    node2->next = node1->next;
    delete node1;
    return;
}

int main(){
    linked_list l;
    l.addAtTail(1);
    l.addAtTail(2);
    l.addAtTail(3);
    l.addAtTail(4);
    l.addAtTail(5);

    remove_at_nth(l, 2);

    l.printAll();
    return 0;
}