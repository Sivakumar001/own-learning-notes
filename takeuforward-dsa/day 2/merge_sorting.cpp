#include<bits/stdc++.h>
using namespace std;


// classic merge sort algorithm

void merge(vector<int> &arr, int start, int end){
    int mid = (start+end)/2;
    int len1 = mid - start + 1;
    int len2 = end- mid;
    
    int *first = new int[len1];
    int *second = new int[len2];

    for(int i=0;i<len1;i++){
        first[i] = arr[start+i];
    }
    for(int j=0;j<len2;j++){
        second[j] = arr[mid+1+j];
    }

    int i=0,j=0,k=start;

    while(i<len1 && j<len2){
        if(first[i]<=second[j]){
            arr[k++] = first[i++];
        }
        else{
            arr[k++] = second[j++];
        }
    }
    while(i<len1){
        arr[k++]=first[i++];
    }
    while(j<len2){
        arr[k++]=second[j++];
    }
    delete[] first;
    delete[] second;
}


void mergeSort(vector<int> &arr, int start, int end){
    if(start>=end){return;}

    int mid=(start+end)/2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);
    merge(arr, start, end);
}
int main(){
    vector<int> arr = {3,1,2,10,7};
    int n=5;
    mergeSort(arr, 0, n-1);
    for(auto it: arr){
        cout << it << "\t";
    }
    return 0;
}