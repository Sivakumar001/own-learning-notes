#include<bits/stdc++.h>

using namespace std;

class queues{
    public:
    int capacity;
    int front,rear;
    int *arr;

    queues(int capacity):capacity(capacity){
        arr = new int[capacity];
        front=rear=0;
    }

    void insert(int value){
        if(isFull())return;
        arr[rear%capacity]=value;
        rear++;
    }

    void pop_out(){
        if(isEmpty())return;
        arr[front%capacity]=0;
        front++;
    }

    int see_top(){
        if(isEmpty())return 0;
        return arr[front];
    }

    bool isEmpty(){
        return rear==front;
    }

    bool isFull(){
        return (rear-front)==capacity;
    }

    int size(){
        return rear-front;
    }

    void print_arr(){
        for(int i=0;i<capacity;i++){
            cout << arr[i] << " ";
        }cout << endl;
    }
    ~queues(){
        delete[] arr;
    }
};

int main(){
    queues q(5);
    q.insert(3);
    q.insert(7);
    q.insert(4);
    q.insert(8);
    q.insert(12);
    q.pop_out();
    q.insert(13);
    q.print_arr();
    cout << q.see_top();
    return 0;
}