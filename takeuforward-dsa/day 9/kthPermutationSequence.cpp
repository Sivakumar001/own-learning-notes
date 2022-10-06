#include<bits/stdc++.h>

using namespace std;

vector<int> nextPermutation(vector<int> arr){
    int i=arr.size()-2;
    for(;i>=0;i--){
        if(arr[i]<arr[i+1])break;
    }
    if(i<0){
        reverse(arr.begin(), arr.end());
    }else{
        int j=arr.size()-1;
        for(;j>=i;j--){
            if(arr[j]>arr[i])break;
        }
        swap(arr[i], arr[j]);
        reverse(arr.begin()+(i+1), arr.end());
    }
    return arr;
}

void findPermutations(vector<string> &ans, string &s, int start, int end, int k, int count){
    if(start==end){
        ans.push_back(s);
        return;
    }
    for(int i=start;i<=end;i++){
        swap(s[start], s[i]);
        findPermutations(ans, s, start+1, end, k, count+1);
        swap(s[start], s[i]);
    }
    return;
}

int main(){
    string s="123";
    vector<string> ans;
    int k=1, count=0;
    findPermutations(ans, s, 0, s.size()-1, k, count);
    for(auto it: ans){
        cout << it << endl;
    }
    return 0;
}