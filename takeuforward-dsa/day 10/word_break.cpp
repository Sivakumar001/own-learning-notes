#include<bits/stdc++.h>

using namespace std;

bool isPresent(string &s, set<string> &dict, int cur_idx, int i){
    string cmp = s.substr(cur_idx, i-cur_idx+1);
    return find(dict.begin(), dict.end(), cmp)!=dict.end();
}

bool word_breaks(string &s, set<string> &dict, int cur_idx=0){
    if(cur_idx==s.size()){
        return true;
    }
    for(int i=cur_idx; i<s.size();i++){
        if(isPresent(s, dict, cur_idx, i)){
            if(word_breaks(s, dict, i+1))return true;
        }
    }
    return false;
}
int main(){
    string s = "godisnowherenowhere";
    set<string> dict = {"god" ,"is" ,"now" ,"no" ,"where" ,"here"};

    if(word_breaks(s, dict)){
        cout << "yes";
    }else{
        cout << "no";
    }
    return 0;
}