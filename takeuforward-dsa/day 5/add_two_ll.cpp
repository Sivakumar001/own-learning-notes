#include<bits/stdc++.h>
#include"linked_list.cpp"

using namespace std;

linked_list add_two_ll(Node* l1, Node* l2){
    Node* result = new Node(-1);
    Node* current = result;
    int carry=0;
    while( (l1||l2) || carry){
        int sum=0;
        if(l1!=nullptr){
            sum+=l1->value;
            l1 = l1->next;
        }
        if(l2!=nullptr){
            sum+=l2->value;
            l2 = l2->next;
        }
        sum+=carry;
        carry = sum/10;
        Node* tmp = new Node(sum%10);
        current->next = tmp;
        current = current->next;
    }
    linked_list ans;
    ans.head = result->next;
    return ans;
}

int main(){
    linked_list l1;
    l1.addAtTail(9);
    l1.addAtTail(9);
    l1.addAtTail(9);
    l1.addAtTail(9);
    l1.addAtTail(9);
    l1.addAtTail(9);
    l1.addAtTail(9);


    linked_list l2;
    l2.addAtTail(9);
    l2.addAtTail(9);
    l2.addAtTail(9);
    l2.addAtTail(9);

    linked_list ans = add_two_ll(l1.head, l2.head);
    ans.printAll();
    return 0;
}