#include<bits/stdc++.h>

using namespace std;

vector<int> get_maximum(vector<int> &arr, int k){
    deque<int> max_q;
    vector<int> max_in_arr;

    for(int i=0;i<arr.size();i++){

        while(!max_q.empty() && arr[i]<=arr[max_q.back()]){
            max_q.pop_back();
        }

        if(!max_q.empty() && max_q.front()<=i-k){
            max_q.pop_front();
        }

        max_q.push_back(i);

        if(i>=k-1){
            max_in_arr.push_back(arr[max_q.front()]);
        }
    }

    return max_in_arr;
}

vector<int> max_min(vector<int> &arr){
    int n = arr.size();
    vector<int> ans;
    deque<int> min_queue;

    for(int k=1;k<=n;k++){
        vector<int> tmp = get_maximum(arr, k);
        ans.push_back(*max_element(tmp.begin(), tmp.end()));
    }

    return ans;
}
int main(){
    vector<int> arr={1,2,3,4};
    vector<int> ans = max_min(arr);
    for(auto it: ans){
        cout << it << " ";
    }
    return 0;
}