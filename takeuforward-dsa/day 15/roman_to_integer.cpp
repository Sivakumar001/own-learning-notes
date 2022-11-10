#include<bits/stdc++.h>

using namespace std;

int roman_to_integer(string s){
    unordered_map<char, int> roman_literals;
    roman_literals['I'] = 1;
    roman_literals['V'] = 5;
    roman_literals['X'] = 10;
    roman_literals['L'] = 50;
    roman_literals['C'] = 100;
    roman_literals['D'] = 500;
    roman_literals['M'] = 1000;

    int answer=0;
    for(int i=0;i<s.size()-1;i++){
        if(roman_literals[s[i]]<roman_literals[s[i+1]]){
            answer = answer - roman_literals[s[i]];
        }
        else{
            answer = answer + roman_literals[s[i]];
        }
    }
    answer += roman_literals[s.back()];
    return answer;
}

int main(){
    string roman = "MCMXCIV";
    cout << roman_to_integer(roman);
}