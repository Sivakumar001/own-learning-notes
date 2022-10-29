#include<bits/stdc++.h>


using namespace std;

vector<int> max_sum_combination(vector<int> arr1, vector<int> arr2, int k){
    priority_queue<int, vector<int>> sum_heap;
    for(auto A: arr1){
        for(auto B: arr2){
            sum_heap.push(A+B);
        }
    }
    vector<int> ans;
    while (k--)
    {
        ans.push_back(sum_heap.top());
        sum_heap.pop();
    }
    return ans;
}
int main(){
    vector<int> arr1 = {1,3};
    vector<int> arr2 = {4,2};
    int k = 3;
    vector<int> ans = max_sum_combination(arr1, arr2, k);
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    return 0;
}