#include<bits/stdc++.h>
#include"linked_list.cpp"

using namespace std;

Node* reverse_in_groups(Node* head, int k){

}
int main(){
    linked_list l;
    
    l.addAtTail(1);
    l.addAtTail(2);
    l.addAtTail(3);
    l.addAtTail(4);
    l.addAtTail(5);
    l.addAtTail(6);

    Node* ans = reverse_in_groups(l.head, 3);
    while(ans){
        cout << ans->value << "-> ";
        ans = ans->next;
    }
    return 0;
}