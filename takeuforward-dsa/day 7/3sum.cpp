#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> three_sum(vector<int> arr){
    sort(arr.begin(), arr.end());
    int len = arr.size();
    vector<vector<int>> ans;

    for(int i=0;i<len-2;i++){
        if(arr[i]!=arr[i-1] || i==0){
            int left = i+1;
            int right = len-1;
            while(left<right){
                int total = arr[i]+arr[left]+arr[right];
                if(total==0){
                    ans.push_back({arr[i], arr[left], arr[right]});
                    int tmp_left =arr[left], tmp_right=arr[right];
                    while(arr[left]==tmp_left && left<right)left++;
                    while(arr[right]==tmp_right && left<right)right--;
                }
                else if(total>0){
                    right--;
                }
                else if(total<0){
                    left++;
                }     
            }
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {-1,0,1,2,-1,-4};
    vector<vector<int>> ans = three_sum(arr);
    for(auto it: ans){
        for(auto itr: it){
            cout << itr << " ";
        }cout << "\n";
    }
    return 0;
}