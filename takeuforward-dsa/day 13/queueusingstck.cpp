#include<bits/stdc++.h>

using namespace std;

class queue_using_stack{
    public:
    stack<int> stk1;
    stack<int> stk2;
    int capacity;
    int size;
    queue_using_stack(int capacity):capacity(capacity){
        size=0;
    }

    void insert(int value){
        if(isFull())return;
        while(!stk2.empty()){
            stk1.push(stk2.top());
            stk2.pop();
        }
        stk1.push(value);
        while(!stk1.empty()){
            stk2.push(stk1.top());
            stk1.pop();
        }
        size++;
    }

    void pop(){
        if(isEmpty())return;
        stk2.pop();
        size--;
    }

    int top(){
        return stk2.top();
    }
    bool isFull(){
        return size==capacity;
    }

    bool isEmpty(){
        return size==0;
    }
};

int main(){
    queue_using_stack qst(5);
    qst.insert(10);
    qst.insert(20);
    qst.insert(30);
    cout << qst.top();
    qst.pop();
    cout << qst.top();
    return 0;
}