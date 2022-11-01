#include<bits/stdc++.h>

using namespace std;

class stack_single_queue{
    public:
    queue<int> stckspace;
    int size;
    int capacity;

    stack_single_queue(int cap):capacity(cap){
        size=0;
    }

    void insert(int value){
        if(isFull())return;
        stckspace.push(value);
        int i=0;
        while(i<size){
            stckspace.push(stckspace.front());
            stckspace.pop();
            i++;
        }
        size++;
    }

    void pop(){
        if(isEmpty())return;
        stckspace.pop();
    }

    int top(){
        return stckspace.front();
    }

    bool isFull(){
        return size==capacity;
    }

    bool isEmpty(){
        return size==0;
    }
};

int main(){
    stack_single_queue st(5);
    st.insert(10);
    st.insert(20);
    st.insert(30);
    cout << st.top();
    st.pop();
    cout << st.top();
    return 0;
}