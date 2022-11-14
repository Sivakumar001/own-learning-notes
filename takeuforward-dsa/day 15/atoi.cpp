#include<bits/stdc++.h>

using namespace std;

int convert_atoi(string s){
    int i=0,n=s.size();

    while(i<n && s[i]==' '){
        i++;
    }

    if(i>=n)return -1;

    bool sign=0;

    if(s[i]=='-'){
        sign=1;
        i++;
    }
    else if(s[i]=='+'){i++;}
    long long int answer=0;

    while(i<n && s[i]>='0' && s[i]<='9'){
        if(answer>INT_MAX/10 || answer==INT_MAX/10 && (s[i]-'0')>INT_MAX%10){
            return sign?INT_MIN:INT_MAX;
        }
        else{
            answer = answer*10+(s[i]-'0');
        }
    }


    return (sign)?answer*-1:answer;
}

int main(){
    //           2147483647
    string s = "-232342345";
    cout << convert_atoi(s);
}