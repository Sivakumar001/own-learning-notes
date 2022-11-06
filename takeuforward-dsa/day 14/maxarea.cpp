#include<bits/stdc++.h>

using namespace std;

int max_area(vector<int> arr){
    int max_area=0, area=0;
    vector<int> max_right;
    stack<int> max_stack;

    for(int i=arr.size()-1;i>=0;i--){
        while(!max_stack.empty() && arr[i]<=arr[max_stack.top()]){
            max_stack.pop();
        }
        max_right.push_back(max_stack.empty()?-1:max_stack.top()-1);
        max_stack.push(i);
    }
    reverse(max_right.begin(), max_right.end());
    while(!max_stack.empty()){
        max_stack.pop();
    }

    for(int i=0;i<arr.size();i++){

        while(!max_stack.empty() && arr[i]<=arr[max_stack.top()]){
            max_stack.pop();
        }

        int distance = (max_right[i]<0?0:max_right[i]) -(max_stack.empty()?0:arr[max_stack.top()]+1) + 1;
        area = distance*arr[i];
        if(max_area<area){
            max_area = area;
        }

        max_stack.push(i);
    }

    return max_area;
}

int main(){
    vector<int> arr = {2,4};
    cout << max_area(arr);
    return 0;
}