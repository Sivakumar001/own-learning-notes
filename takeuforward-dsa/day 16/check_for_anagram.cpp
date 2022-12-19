#include<bits/stdc++.h>

using namespace std;

bool check_anagram(string s1, string s2){
    int arr[26] = {0};
    for(auto itr: s1){
        arr[itr-'a']++;
    }
    for(auto itr: s2){
        if(arr[itr-'a']){
            arr[itr-'a']--;
        }
    }
    for(auto it: arr){
        if(it!=0)return false;
    }
    return true;
}

int main(){
    string s1 = "gentleman", s2 = "elegantman";
    if(check_anagram(s1, s2)){
        cout << "yes it is anagram";
    }
    else{
        cout << "no it is not a anagram";
    }
}