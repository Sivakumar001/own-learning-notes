#include<bits/stdc++.h>
using namespace std;

pair<int, int> missing_and_repeating(vector<int> &A){
    long long int len = A.size();

    long long int S = (len * (len+1) ) /2;
    long long int P = (len * (len +1) *(2*len +1) )/6;
    // long long int missingNumber=0, repeating=0;
     
    for(auto it: A){
       S -= (long long int)it;
       P -= (long long int)it*(long long int)it;
    }
    
    long long int missingNumber = (S + P/S)/2;

    long long int repeating = missingNumber - S;

    return {missingNumber,repeating};
}


int main(){
    vector<int> question = {3,1,2,5,3};
    pair<int, int> ans = missing_and_repeating(question);
    cout << ans.first << "\t" << ans.second;
    return 0;
}