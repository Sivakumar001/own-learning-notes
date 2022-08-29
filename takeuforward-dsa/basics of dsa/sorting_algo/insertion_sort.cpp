#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int *arr, int n){
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && key<arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

int main(){
    int arr[] = {30,4,12,45,678,22};
    insertion_sort(arr, sizeof(arr)/sizeof(int));
    for(auto it: arr){
        cout << it << " ";
    }
    return 0;
}