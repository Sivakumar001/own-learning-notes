#include<bits/stdc++.h>
using namespace std;

// using mergesort to find the count value
// count equals left end - curr pos in left

int merge_arr(vector<int> arr, vector<int> temp, int low, int mid, int high){
    int count = 0;
    int i=low, j=mid, k=low;

    while(i<=mid-1 && j<=high){
        if(arr[i]<=arr[j]){
            temp[k++] = arr[i++];
        }else{
            temp[k++] = arr[j++];
            count += mid - i;
        }
    }
    
    while(i<=mid-1){
        temp[k++] = arr[i++];
    }
    while(j<=high){
        temp[k++] = arr[j++];
    }
    
    for(int i=0;i<=high;i++){
        arr[i] = temp[i];
    }
    
    return count;
}

int count_inversion(vector<int> arr, vector<int> temp, int low, int high){
    int mid, count = 0;
    if(high>low){
        mid = (high + low)/2;
        count += count_inversion(arr, temp, low, mid);
        count += count_inversion(arr, temp, mid+1, high);
        count += merge_arr(arr, temp, low, mid+1, high);
    }
    return count;
}
int main(){
    vector<int> question = {5,4,3,2,1};
    int n = question.size();
    vector<int> temp(n, 0);
    cout << count_inversion(question,temp, 0, n-1);
    return 0;
}