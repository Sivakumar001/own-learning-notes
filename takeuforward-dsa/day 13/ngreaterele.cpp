#include<bits/stdc++.h>

using namespace std;

vector<int> nxt_greater(vector<int> arr){
    int n = arr.size();
    vector<int> ans;
    stack<int> s;
    for(int i=2*n-1;i>=0;i--){
        while(!s.empty() && s.top()<=arr[i%n])s.pop();
        if(i<n)ans.push_back(s.empty()?-1:s.top());
        s.push(arr[i%n]);
    }
    return ans;
}

int main(){
    vector<int> arr = {3,10,4,2,1,2,6,1,7,2,9};
    vector<int> ans = nxt_greater(arr);
    for(auto it: ans){
        cout << it << " ";
    }
    return 0;
}