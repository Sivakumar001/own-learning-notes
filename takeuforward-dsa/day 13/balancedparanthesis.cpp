#include<bits/stdc++.h>

using namespace std;

bool balanced_paranthesis(string s){
    stack<char> stck;
    for(int i=0;i<s.size();i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            stck.push(s[i]);
        }
        else{
            if(stck.empty())return false;
            if( (stck.top()=='(' && s[i]==')') ||
                (stck.top()=='{' && s[i]=='}') ||
                (stck.top()=='[' && s[i]==']')
            ){
                stck.pop();
            }
            else{
                return false;
            }
        }
    }
    return stck.empty();
}

int main(){
    string s = "([]) ";
    if(balanced_paranthesis(s)){
        cout << "yes true balanced";
    }
    else{
        cout << "Nah";
    }
    return 0;
}