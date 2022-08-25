#include<bits/stdc++.h>
using namespace std;

void selection_sort(int *arr, int n){
    for(int i=0;i<n-1;i++){
        int min_idx=i;
        for(int j=i+1;j<n;j++){
            if(arr[min_idx]>arr[j]){
                min_idx = j;
            }
        }
        if(min_idx!=i){
            swap(arr[min_idx], arr[i]);
        }
    }
}

int main(){
    int arr[] ={3,2,1,8,4,2,9};
    selection_sort(arr, sizeof(arr)/sizeof(int));
    for(auto it: arr){
        cout << it;
    }
    return 0;
}