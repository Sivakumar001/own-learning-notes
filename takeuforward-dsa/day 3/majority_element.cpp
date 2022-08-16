#include<bits/stdc++.h>
using namespace std;


bool isMajority(vector<int> arr, int target, int k){
    int count = 0;
    for(auto it: arr){
        if(it==target){
            count++;
        }
    }
    return (count>arr.size()/k)? true : false;
}


int majority_n_by_k(vector<int> arr, int k){
    int count = 0, index = 0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==arr[index]){
            count++;
        }
        else{
            count--;
        }
        if(count==0){
            index = i;
            count = 1;
        }
    }
    bool a = isMajority(arr, arr[index], k);
    if(!a){
        return -1;
    }
    return arr[index];
}

int main(){
    vector<int> question = {2,3,4,3,2};
    cout << majority_n_by_k(question, 2);
    return 0;
}