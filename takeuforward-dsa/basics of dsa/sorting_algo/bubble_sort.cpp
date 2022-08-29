#include<bits/stdc++.h>
using namespace std;

void bubble_sort(int *arr, int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                swap(arr[i],arr[j]);
            }
        }
    }
}
int main(){
    int arr[] = {2,12,34,53,21,4};
    bubble_sort(arr, sizeof(arr)/sizeof(int));
    for(auto it: arr){
        cout << it << " ";
    }
    return 0;
}