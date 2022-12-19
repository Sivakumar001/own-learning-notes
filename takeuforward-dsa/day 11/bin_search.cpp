#include<bits/stdc++.h>

using namespace std;

vector<int> bin_first_last(vector<int> arr, int target){
    int l=0,n=arr.size();
    int r=n-1;

    while(l<=r){
        int mid=(l+r)>>1;
        if(arr[mid]<=target){
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    int last = r;
    l=0;r=n-1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(arr[mid]>=target){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    int first = l;

    if(first<0 || first==n || arr[first]!=target)first=-1;
    if(last<0 || last==n || arr[last]!=target)last=-1;
    return {first, last};
}

int main(){
    vector<int> arr = {5,7,7,8,8,10};
    vector<int> ans = bin_first_last(arr, 8);
    for(auto it: ans){
        cout << it;
    }
}