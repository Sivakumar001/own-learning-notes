#include<bits/stdc++.h>

using namespace std;

string int_to_roman(int integer){
    vector<int> roman_int = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    vector<string> roman_literal = {"M", "CM", "D", "CD","C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    string answer;
    for(int ptr=0; ptr<roman_int.size();ptr++){
        while(integer>=roman_int[ptr]){
            answer += roman_literal[ptr];
            integer -= roman_int[ptr];
        }
    }
    return answer;
}

int main(){
    int integer = 1994;
    cout << int_to_roman(integer);
}