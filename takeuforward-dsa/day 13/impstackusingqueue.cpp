#include<bits/stdc++.h>

using namespace std;

class create_stck{
    public:
    queue<int> q1;
    queue<int> q2;

    create_stck(){

    }

    void push(int value){
        q1.push(value);
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
    }

    void pop(){
        if(!q2.empty())q2.pop();
    }

    int top(){
        return q2.front();
    }

};

int main(){
    create_stck st;
    st.push(3);
    st.push(4);
    st.push(1);
    st.push(5);
    st.push(9);

    st.pop();
    cout << st.top();
    return 0;
}