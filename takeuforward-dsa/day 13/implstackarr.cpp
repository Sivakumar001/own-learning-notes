#include<bits/stdc++.h>

using namespace std;

class stck{
    public:
        int* input;
        int size;
        int capacity;

    stck(int cap):capacity(cap){
        input = new int[capacity];
        size=0;
    }

    void insert_value(int value){
        if(isFull())return;
        input[size]=value;
        size++;
    }

    void pop_value(){
        if(isEmpty())return;
        input[size]=0;
        size--;
    }

    int view_top(){
        if(isEmpty())return 0;
        return input[size-1];
    }

    bool isEmpty(){
        return size==0;
    }

    bool isFull(){
        return size==capacity;
    }

    ~stck(){
        delete[] input;
    }
};

int main(){
    stck s(10);
    s.pop_value();
    cout << s.view_top();
    return 0;
}