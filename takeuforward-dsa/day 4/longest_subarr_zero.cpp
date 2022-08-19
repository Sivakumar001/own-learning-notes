#include<bits/stdc++.h>
using namespace std;

int longest_subarr_sum(vector<int> &arr){
    unordered_map<int, int> un_map;
    int sum=0, max_sum=INT16_MIN;
    for(int i=0;i<arr.size();i++){
        sum += arr[i];
        if(sum==0){
            max_sum = max(max_sum, i+1);
        }
        else{
            if(un_map.find(sum)!=un_map.end()){
                max_sum = max(max_sum, i-(un_map[sum]+1)+1);
            }else{
                un_map[sum]=i;
            }
        }
    }
    return max_sum;
}

int main(){
    vector<int> que={9, -3, 3, -1, 6, -5};
    cout << longest_subarr_sum(que);
    return 0;
}