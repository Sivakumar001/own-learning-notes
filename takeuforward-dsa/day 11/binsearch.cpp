#include<bits/stdc++.h>

using namespace std;

// https://stackoverflow.com/a/67031315/12077335
// why binary search impletation is tougher...

int find_last_pos(vector<int> arr, int n){
    int low = 0,high = n;
    while(low<=high){
        int mid = (low+high)>>1;
        if(arr[low]==1){
            high = mid - 1;
        }
        else{
            low = mid;
        }
    }
    return high;
}
int main(){
    vector<int> arr = {0,0,0,0,0,0,0,1,1,1,1};
    cout << find_last_pos(arr, arr.size()-1);
    return 0;
}