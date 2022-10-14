#include<bits/stdc++.h>

using namespace std;

void PhoneCombo(unordered_map<char, string> &phoneBook, 
                vector<string> &answer,
                string &number,
                string &ds,
                int index=0){
    string cur_phoneBook=phoneBook[number[index]];
    for(int i=0;i<cur_phoneBook.size();i++){
        ds.push_back(cur_phoneBook[i]);
        PhoneCombo(phoneBook, answer, number, ds, index+1);
        ds.pop_back();
    }
    if(index == number.size()){
        answer.push_back(ds);
    }
    return;
}

int main(){
    unordered_map<char, string> phoneBook;
    phoneBook['2']="abc";
    phoneBook['3']="def";
    phoneBook['4']="ghi";
    phoneBook['5']="jkl";
    phoneBook['6']="mno";
    phoneBook['7']="pqrs";
    phoneBook['8']="tuv";
    phoneBook['9']="wxyz";
    
    string number="1";
    vector<string> answer;
    string ds;

    PhoneCombo(phoneBook, answer, number, ds);
    for(auto it: answer){
        cout << it << endl;
    }
    return 0;
}