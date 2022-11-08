#include<bits/stdc++.h>

using namespace std;

class min_stack{
    public:
    stack<long long> stk;

    void push(int value){
        if(stk.empty() || value<stk.top()){
            stk.push(value);
            return;
        }
        int frame=stk.top();
        stk.pop();
        push(value);
        stk.push(frame);
    }

    void pop(){
        stk.pop();
    }

    int top(){
        return stk.top();
    }

    bool empty(){
        return stk.empty();
    }

    bool size(){
        return stk.size();
    }
};

int main(){
    min_stack minStk;
    minStk.push(4);
    minStk.push(7);
    minStk.push(3);
    minStk.push(6);
    minStk.push(5);

    while(!minStk.empty()){
        cout << minStk.top() << " ";
        minStk.pop();
    }

    return 0;
}