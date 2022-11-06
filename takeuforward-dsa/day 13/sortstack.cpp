#include<bits/stdc++.h>

using namespace std;

void sortInsert(stack<int> &s, int x){
    if(s.empty() || s.top()>x){
        s.push(x);
        return;
    }
    int n = s.top();
    s.pop();
    sortInsert(s, x);
    s.push(n);
}

void sort_stack(stack<int> &s){
    if(s.empty()){
        return;
    }
    int num = s.top();
    s.pop();
    sort_stack(s);
    sortInsert(s, num);
}

int main(){
    stack<int> s;
    s.push(6);
    s.push(7);
    s.push(2);
    s.push(5);
    s.push(8);
    s.push(3);

    sort_stack(s);
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}