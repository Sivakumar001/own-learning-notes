#include<bits/stdc++.h>
using namespace std;

int longest_substring_without_repeat(string s){
    unordered_map<char, int> bag;
    int l=0, r=0;
    int max_len=0;
    while(r<s.size()){
        if(bag.find(s[r])!=bag.end()){
            l=max(l, r+1);
        }
        bag[s[r]]=r;
        max_len= max(max_len, (r-l)+1);
        r++;
    }
    return max_len;
}
int main(){
    string s="abcabcbb";
    cout << longest_substring_without_repeat(s);
    return 0;
}

