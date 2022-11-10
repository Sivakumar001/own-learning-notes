#include<bits/stdc++.h>

using namespace std;

string reverse_string(string s){
    int i=0,n=s.size(),j=0;
    string sub;
    string answer;
    while(i<n){
        while(i<n && s[i]==' ')i++;
        if(i>=n)break;
        j=i+1;
        while(j<n && s[j]!=' ')j++;
        sub = s.substr(i, j-i);
        if(answer.size()==0){
            answer = sub;
        }
        else{
            answer = sub + " " + answer;
        }
        i=j+1;
    }
    cout << answer.size() << endl;
    return answer;
}

int main(){
    string s = " this program will or wont run perfectly!  ";
    cout << s.size();
    cout << "|" << reverse_string(s) << "|"<< endl;
}