#include<iostream>
using namespace std;

class ListNode{
    public:
        int value;
        ListNode *next;
        ListNode(int x):value(x),next(nullptr){};
};

class linked_list{
    public:
        ListNode* head;
        int size;
        linked_list():head(nullptr),size(0){};

        void addAtHead(int value){addAtIndex(0, value);}
        void addAtTail(int value){addAtIndex(size, value);}

        int getAtHead(){return getAtIndex(0);}
        int getAtTail(){return getAtIndex(size-1);}

        void addAtIndex(int index, int value){
            if(index<0 || index>size){
                return;
            }
            ListNode* current = head;
            ListNode* new_node = new ListNode(value);
            if(index==0){
                new_node->next = current;
                head = new_node;
            }else{
                for(int i=0;i<index-1;i++){
                    current = current->next;
                }
                new_node->next = current->next;
                current->next = new_node;
            }
            size++;
        }

        int getAtIndex(int index){
            if(index<0 || index>=size)return -1;
            ListNode* current = head;
            if(index==0){
                return current->value;
            }else{
                for(int i=1;i<=index;i++){
                    current = current->next;
                }
                return current->value;
            }
        }

        ListNode* getNodeAtIndex(int index){
            if(index<0 || index>=size)return new ListNode(-1);
            ListNode* current = head;
            if(index==0){
                return current;
            }else{
                for(int i=1;i<=index;i++){
                    current = current->next;
                }
                return current;
            }
        }
        void printAll(){
            ListNode *current = head;
            while(current!=nullptr){
                cout << current->value << "-> ";
                current = current->next;
            }
        }
        void deleteAtIndex(int index){
            if(index<0 || index>=size)return;
            ListNode *current=head;
            if(index==0){
                head = head->next;
                delete current;
            }else{
                for(int i=0;i<index-1;i++){
                    current = current->next;
                }
                ListNode* tmp = current->next;
                current->next = tmp->next;
                delete tmp;
            }
            size--;
        }
        ~linked_list(){
            ListNode *ptr = head;
            while(head){
                head=head->next;
                delete ptr;
                ptr = head;
            }
        }

};

// int main(){
//     linked_list l;
//     l.addAtHead(1);
//     l.addAtTail(2);
//     l.addAtTail(3);
//     l.addAtTail(4);
//     l.addAtTail(5);
//     l.addAtTail(6);
//     l.deleteAtIndex(5);
//     l.printAll();
//     cout << l.getAtTail();
//     return 0;
// }