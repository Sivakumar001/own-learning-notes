#include<bits/stdc++.h>
using namespace std;

void merge_(vector<int>& arr, int low, int mid, int high, int &count){
    vector<int> temp;
    int i=low, j=mid+1;

    for(int i=low;i<=mid;i++){
        while(j<=high && arr[i]>2LL*arr[j]){
            j++;
        }
        count += j-(mid+1);
    }
    j=mid+1;

    while(i<=mid && j<=high){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i++]);
        }else{
            temp.push_back(arr[j++]);
        }
    }
    while(i<=mid){
        temp.push_back(arr[i++]);
    }
    while(j<=high){
        temp.push_back(arr[j++]);
    }
    for(int i=0;i<temp.size();i++){
        arr[i+low] = temp[i];
    }
}
void mergeSort(vector<int> &arr, int low, int high, int &count){
    if(low>=high) return;
    int mid=(low+high)/2;
    mergeSort(arr, low, mid, count);
    mergeSort(arr, mid+1, high, count);
    merge_(arr, low, mid, high, count);
}

int main(){
    vector<int> que = {10,3,7,4,6};
    int count = 0;
    mergeSort(que, 0, que.size()-1, count);
    for(auto it: que){
        cout << it;
    }
    cout << "\t" << count;
    return 0;
}