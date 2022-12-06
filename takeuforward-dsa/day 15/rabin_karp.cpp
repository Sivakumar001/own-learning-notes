#include<bits/stdc++.h>

using namespace std;

bool rabin_karp(string text, string pattern){
    int pattern_hash = 0;
    for(auto chr: pattern){
        pattern_hash = ((pattern_hash*10)+(chr))%INT_MAX;
    }

    int m = text.size(), n=pattern.size();
    int i=0;
    int text_hash=0;

    while(i<m){

        if(i>=n)text_hash =(int)(text_hash - ((text[i-n])*pow(10,n-1)))%INT_MAX;
        text_hash = (text_hash*10 + (text[i]))%INT_MAX;

        if(text_hash==pattern_hash){
            int j=0,k=i-n+1;
            while(j<n){
                if(text[k++]!=pattern[j++])break;
            }
            if(j==n)return true;
        }

        i++;
    }
    return false;
}

int main(){
    string text = "AAABBCCCDDEE";
    string pattern="DEFFFFGGG";

    if(rabin_karp(text, pattern)){
        cout << "found";
    }
    else{
        cout << "not found";
    }
}