#include<bits/stdc++.h>
#include"linked_list.cpp"

using namespace std;

linked_list merge_sort(linked_list &l1, linked_list &l2){
    linked_list res;
    Node* node1 = l1.head;
    Node* node2 = l2.head;

    while(node1 && node2){
        if(node1->value < node2->value){
            res.addAtTail(node1->value);
            node1 = node1->next;
        }else{
            res.addAtTail(node2->value);
            node2 = node2->next;
        }
    }
    while(node1){
        res.addAtTail(node1->value);
        node1 = node1->next;
    }

    while(node2){
        res.addAtTail(node2->value);
        node2 = node2->next;
    }
    return res;
}
int main(){
    linked_list l1;
    l1.addAtTail(2);
    l1.addAtTail(4);
    l1.addAtTail(5);
    l1.addAtTail(7);
    l1.addAtTail(8);

    linked_list l2;
    l2.addAtTail(1);
    l2.addAtTail(3);
    l2.addAtTail(5);
    l2.addAtTail(6);

    linked_list result = merge_sort(l1, l2);
    result.printAll();
    return 0;
}