#include<bits/stdc++.h>

using namespace std;

int finding_unique_ele(vector<int> &arr){
    int low=0,high=arr.size()-2;
    while(low<=high){
        int mid = (low+high) >> 1;
        if(arr[mid]==arr[mid^1]){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return arr[low];
}

int main(){
    vector<int> question = {1,1,3,3,4,4,5,8,8};
    cout << finding_unique_ele(question);
    return 0;
}