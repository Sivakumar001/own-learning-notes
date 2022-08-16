#include<bits/stdc++.h>
using namespace std;

bool isMajority(vector<int> arr, int val1, int val2){
    int count1 = 0, count2=0;
    for(auto it: arr){
        if(it==val1){
            count1++;
        }
        if(it==val2){
            count2++;
        }
    }
    int by_value = arr.size()/2;
    if(count1>by_value && count2>by_value){
        return true;
    }
    return false;
}
vector<int> majority_elements(vector<int> arr){
    int element1=-1, element2=-1, count1=0, count2=0;
    for(auto it: arr){
        if(it == element1){
            count1++;
        }
        else if(it == element2){
            count2++;
        }
        else if(count1==0){
            element1 = it;
            count1 = 1;
        }
        else if(count2==0){
            element2 = it;
            count2 = 1;
        }
        else{
            count1--;
            count2--;
        }
    }
    if(isMajority(arr, element1, element2)){
        return {element1, element2};
    }
    return {-1};
}

int main(){
    vector<int> question = {1,1,1,2,2,3,3,3,3};
    vector<int> ans = majority_elements(question);
    for(auto it: ans){
        cout << it << "\t";
    }
    return 0;
}