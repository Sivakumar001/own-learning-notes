#include<bits/stdc++.h>

using namespace std;

int trapping_rain(vector<int> arr){
    int left = 0;
    int right = arr.size()-1;
    int max_left = 0;
    int max_right = 0;
    int result = 0;

    while(left<=right){
        if(arr[left]<=arr[right]){
            if(arr[left]>=max_left)max_left=arr[left];
            else{
                result+=max_left-arr[left];
            }
            left++;
        }else{
            if(arr[right]>=max_right)max_right=arr[right];
            else{
                result+=max_right-arr[right];
            }
            right--;
        }
    }
    return result;
}

int main(){
    vector<int> arr = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trapping_rain(arr);
    return 0;
}