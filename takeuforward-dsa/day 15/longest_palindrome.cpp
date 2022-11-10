#include<bits/stdc++.h>

using namespace std;
pair<int, int> find_palindrome(string s, int l, int r){
    while(l>-1 && r<s.size() && s[l]==s[r]){
        l--;
        r++;
    }
    return {l+1,r-1};
}

string longest_palindrome(string s){
    int n = s.size(), len=0;
    int max_l=0, max_r=0;

    for(int i=0;i<n;i++){
        pair<int, int> even_pal, odd_pal;
        even_pal = find_palindrome(s, i, i);
        odd_pal = find_palindrome(s, i-1, i);
        if(even_pal.second-even_pal.first>odd_pal.second-odd_pal.first){
            max_l = even_pal.first;
            max_r = even_pal.second;
        }
        else{
            max_l = odd_pal.first;
            max_r = odd_pal.second;
        }
    }
    return s.substr(max_l, max_r-max_l);
}
int main(){
    string s = "babad";
    cout << longest_palindrome(s);
}