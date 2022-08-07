#include<bits/stdc++.h>
using namespace std;

void merge_two_sorted_arrays(vector<int> &A, vector<int>&B){
    int m=A.size(), n=A.size()+B.size();
    double gap = n;
    while(gap!=1){
        gap = ceil(gap/2);
        int i=0,j=gap;
        while(j<n){
            if(i<m && j>=m && A[i]>B[j%m]){
                swap(A[i%m], B[j%m]);

            }else if(j<m && A[i]>A[j]){
                swap(A[i%m],A[j%m]);

            }else if(i>m && j>m && B[i%m]>B[j%m]){
                swap(B[i%m], B[j%m]);
            }
            i++;
            j++;
        }
    }
}

int main(){
    vector<int> A = {1 ,4 ,8 ,10}, B={2 ,3 ,9};
    merge_two_sorted_arrays(A, B);
    for(auto it: A){
        cout << it << "\t";
    }
    cout << "\n";
    for(auto it: B){
        cout << it << "\t";
    }
    return 0;
}