#include<bits/stdc++.h>
using namespace std;
// two for loops and binary search the target to find foursum

vector<vector<int>> four_sum(vector<int> &arr, int target){
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    
    int n=arr.size();
    int i,j,left,right;
    
    for(i=0;i<=n-4;i++){
        for(j=i+1;j<=n-3;j++){
            int rem_sum = target - (arr[i] + arr[j]);
            left=j+1; right=n-1;

            while(left<right){
                int bs_sum=arr[left]+arr[right];
                if(bs_sum == rem_sum){
                    ans.push_back({arr[i], arr[j], arr[left], arr[right]}); 
                    int left_comp=arr[left], right_comp=arr[right];
                    while(arr[right]==right_comp)right--;
                    while(arr[left]==left_comp)left++;
                }
                if(bs_sum>rem_sum){
                    right--;
                }
                else if(bs_sum<rem_sum){
                    left++;
                }
            }
        }
    }
    return ans;
}

int main(){
    vector<int> question={1,0,-1,0,-2,2};
    int target = 0;
    vector<vector<int>> ans = four_sum(question, target);
    for(auto it: ans){
        for(auto itr: it){
            cout << itr << "\t";
        }
        cout << "\n";
    }
    return 0;
}