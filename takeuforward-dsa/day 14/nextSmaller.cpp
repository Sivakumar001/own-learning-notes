#include<bits/stdc++.h>

using namespace std;

vector<int> nxt_small(vector<int> arr){
    int n = arr.size();
    vector<int> ans;
    stack<int> s;

    for(int i=0;i<n;i++){
        while(!s.empty() && s.top()>=arr[i%n]){
            s.pop();
        }
        ans.push_back(s.empty()?-1:s.top());
        s.push(arr[i%n]);
    }
    return ans;
}

int main(){
    vector<int> array = {4, 5, 2, 10, 8};
    vector<int> ans = nxt_small(array);
    for(auto it: ans){
        cout << it << " ";
    }
    return 0;
}