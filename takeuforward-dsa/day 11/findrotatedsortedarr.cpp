#include<bits/stdc++.h>

using namespace std;

int findstart(vector<int> &arr, int target){
    int low = 0 , high=arr.size()-1;
    while(low<=high){
        int mid = (low+high) >> 1;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[low]<=arr[mid]){
            if(target>=arr[low] && target<=arr[mid]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        else{
            if(target>=arr[mid] && target<=arr[high]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
    }
    return -1;
}

int main(){
    int target=5;
    vector<int> arr = {4,5,6,7,0,1,2,3};
    cout << findstart(arr, target);
    return 0;
}