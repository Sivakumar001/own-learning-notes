#include<bits/stdc++.h>

using namespace std;

int* lps(string needle){
    int i=1,j=0;
    int* res = new int[needle.size()];
    res[0] = 0;
    while(j<needle.size()){
        if(needle[i]==needle[j]){
            res[i] = j+1;
            i++;j++;
        }
        else if(j>0){
            j = res[j-1];
        }
        else{
            res[i] = 0;
            i++;
        }
    }
    return res;
}

int kmp_implement(string haystack, string needle){
    int* leastps = lps(needle);
    int i=0,j=0;
    while(i<haystack.size() && j<needle.size()){
        if(haystack[i]==needle[j]){
            i++;j++;
        }
        else if(j>0){
            j = leastps[j-1];
        }
        else{
            i++;
        }
    }
    return j == needle.length()? i-j:-1;
}

int main(){
    string haystack="aabaabaabaababaaab";
    string needle="aba";

    cout << kmp_implement(haystack, needle);
}