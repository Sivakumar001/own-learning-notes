#include<bits/stdc++.h>

using namespace std;

int max_area(vector<int> heights){
    int n = heights.size();
    int max_area = 0;

    vector<int> left(n), right(n);
    stack<int> stk;

    for(int i=0;i<n;i++){
        while(!stk.empty() && heights[i]<=heights[stk.top()]){
            stk.pop();
        }
        if(stk.empty()){
            left[i]=0;
        }else{
            left[i] = stk.top()+1;
        }
        stk.push(i);
    }

    while(!stk.empty())stk.pop();

    for(int i=n-1;i>=0;i--){
        while(!stk.empty() && heights[i]<=heights[stk.top()]){
            stk.pop();
        }
        if(stk.empty()){
            right[i] = n-1;
        }
        else{
            right[i] = stk.top()-1;
        }
        stk.push(i);
    }
    for(auto it: right){
        cout << it << " ";
    }
    for(int i=0;i<n;i++){
        max_area = max(max_area, (right[i]-left[i]+1)*heights[i]);
    }
    return max_area;
}

int main(){
    vector<int> arr = {2,1,5,6,2,3};
    cout << max_area(arr);
    return 0;
}