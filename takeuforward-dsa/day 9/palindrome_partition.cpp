#include<bits/stdc++.h>

using namespace std;

bool isPalindrome(string &s, int start, int end){
    while(start<=end){
        if(s[start++]!=s[end--])return false;
    }
    return true;
};
void palindrome_validation(vector<vector<string>> &ans, vector<string> &ds, string &s, int index=0){
    if(index==s.length()){
        ans.push_back(ds);
        return;
    }
    for(int i=index;i<s.size();i++){
        if(isPalindrome(s, index, i)){
            ds.push_back(s.substr(index,i-index+1));
            palindrome_validation(ans, ds, s, i+1);
            ds.pop_back();
        }
    }
    return;
}
int main(){
    string s = "aabb";
    vector<vector<string>> answer;
    vector<string> ds;
    palindrome_validation(answer, ds, s);
    for(auto it: answer){
        for(auto itr: it){
            cout << itr << endl;
        }cout << endl;
    }
    return 0;
}