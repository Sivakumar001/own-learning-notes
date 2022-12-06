#include<bits/stdc++.h>
#include"linked_list.cpp"

using namespace std;

void delete_node(ListNode* node){
    ListNode* current = node;
    ListNode* nxt = current->next;
    current->value = nxt->value;
    current->next = nxt->next;
    delete nxt;
}
int main(){
    linked_list l;
    l.addAtTail(1);
    l.addAtTail(2);
    l.addAtTail(3);
    l.addAtTail(4);
    l.addAtTail(5);
    //setting que
    ListNode* que_node = l.head;
    for(int i=0;i<2;i++){
        que_node = que_node->next;
    }
    delete_node(que_node);
    l.printAll();
    return 0;
}