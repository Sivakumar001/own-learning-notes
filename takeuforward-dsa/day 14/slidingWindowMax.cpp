#include<bits/stdc++.h>

using namespace std;

vector<int> sliding_window(vector<int> &arr, int k){
    deque<int> dq;
    vector<int> answer;
    for(int i=0;i<arr.size();i++){

        if(!dq.empty() && dq.front()==i-k){
            dq.pop_front();
        }

        while(!dq.empty() && arr[i]>=arr[dq.back()]){
            dq.pop_back();
        }

        dq.push_back(i);
        if(i>=k-1){
            answer.push_back(arr[dq.front()]);
        }
    }
    return answer;
}

int main(){
    vector<int> array = {4,0,-1,3,5,3,6,8};
    int k = 3;
    vector<int> ans = sliding_window(array, k);
    for(auto it: ans){
        cout << it << " ";
    }cout << endl;
    return 0;
}