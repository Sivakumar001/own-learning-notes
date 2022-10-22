#include<bits/stdc++.h>

using namespace std;

int find_kth_position(vector<int> &arr1, vector<int> &arr2, int k){
    if(k>(arr1.size()+arr2.size())){return 0;}
    unsigned int idx1=0,idx2=0;
    int cur_val=0;
    while(idx1<arr1.size() && idx2<arr2.size() && k){
        if(arr1[idx1]<=arr2[idx2]){
            cur_val = arr1[idx1];
            idx1++;
        }else{
            cur_val = arr2[idx2];
            idx2++;
        }
        k--;
    }
    if(k){
        if(idx1<arr1.size()){
            cur_val = arr1[idx1+k-1];
        }
        else{
            cur_val = arr2[idx2+k-1];
        }
    // }
    // while(k && idx1<arr1.size()){
    //     cur_val = arr1[idx1];
    //     idx1++;
    //     k--;
    // }
    // while(k && idx2<arr2.size()){
    //     cur_val = arr2[idx2];
    //     idx2++;
    //     k--;
    }
    return cur_val;
}
int main(){
    vector<int> arr1={};
    vector<int> arr2={1,4,8,10};
    int k=2;
    cout << find_kth_position(arr1, arr2, k);
    return 0;
}