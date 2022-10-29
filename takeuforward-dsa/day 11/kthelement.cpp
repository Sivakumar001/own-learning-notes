#include<bits/stdc++.h>

using namespace std;

int find_kth_position(vector<int> &arr1, vector<int> &arr2, int k){
    if(arr1.size()>arr2.size()){return find_kth_position(arr2, arr1, k);}
    int n = arr1.size(), m = arr2.size();
    // special case where array 1 size is less than k (its waste of time to enter the array itself)
    int low = max(0, k-n), high = min(k, m);

    while(low<=high){
        int cut1 = (low+high)>>1;
        int cut2 = k-cut1;

        int l1 = cut1==0? INT_MIN: arr1[cut1-1];
        int l2 = cut2==0? INT_MIN: arr2[cut2-1];

        int r1 = cut1==n? INT_MAX: arr1[cut1];
        int r2 = cut2==m? INT_MAX: arr2[cut2];

        if(l1<=r2 && l2<=r1){
            return max(l1, l2);
        }
        else if(l1>r2){
            high = cut1 - 1;
        }
        else{
            low = cut1 + 1;
        }
    }
    return -1;
}

int main(){
    vector<int> arr1={2,3,6};
    vector<int> arr2={1,4,8,10};
    int k=6;
    cout << find_kth_position(arr1, arr2, k);
    return 0;
}