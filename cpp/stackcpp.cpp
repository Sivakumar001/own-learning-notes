#include<bits/stdc++.h>
#define LOG(x) :: std::cout << x << std::endl;
/* 
Stack
    Last In First Out
    bookstack,
    ctrl+z,
    browser back button,
*/

void stack_concept(){

    std::stack<int> sample_stack;
    sample_stack.push(1);
    sample_stack.push(2);

    LOG(sample_stack.top());

    sample_stack.pop();
    LOG(sample_stack.empty());
}

int main(){
    stack_concept();
    return 0;
}