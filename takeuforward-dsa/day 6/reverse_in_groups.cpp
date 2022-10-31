#include<bits/stdc++.h>
#include"linked_list.cpp"

using namespace std;
// https://github.com/azl397985856/leetcode/blob/master/problems/25.reverse-nodes-in-k-groups-en.md

// using recursion
Node* reverse_in_groups(Node* head, int k, int length){
    //created length to stop when len<k to avoid reversing nodes less than k
    if(head==nullptr || head->next==nullptr || length<k){
        return head;
    }

    Node* currNode = head;
    Node* prevNode = nullptr;
    Node* nxtNode = nullptr;
    int count = 0;

    while(currNode!=nullptr && count<k){
        nxtNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nxtNode;
        count++;
    }

    if(nxtNode!=nullptr){
        head->next = reverse_in_groups(nxtNode, k, length-k);
    }
    return prevNode;
}
int main(){
    linked_list l;

    l.addAtTail(1);
    l.addAtTail(2);
    l.addAtTail(3);
    l.addAtTail(4);
    l.addAtTail(5);
    l.addAtTail(6);

    Node* ans = reverse_in_groups(l.head, 4, l.size);
    while(ans){
        cout << ans->value << "-> ";
        ans = ans->next;
    }
    return 0;
}