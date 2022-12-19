#include<bits/stdc++.h>

using namespace std;

vector<int> merge_sort(vector<int> ans, vector<int> vct){
    int m=ans.size(), n=vct.size();
    vector<int> result(m+n, 0);

    int i=0,j=0,k=0;
    while(i<m && j<n){
        if(ans[i]<vct[j]){
            result[k++] = ans[i++];
        }
        else{
            result[k++] = vct[j++];
        }
    }
    while(i<ans.size()){
        result[k++] = ans[i++];
    }
    while(j<vct.size()){
        result[k++] = vct[j++];
    }
    return result;
}

vector<int> merge_k_sorted_arr(vector<vector<int>> arrys){
    vector<int> ans;
    for(auto l: arrys){
        ans = merge_sort(ans, l);
    }
    return ans;
}

int main(){
    vector<int> arr1 = {11,34,55,52,34,53};
    vector<int> arr2 = {16,31,52,23,345,567};
    vector<int> arr3 = {12,32,55,254,34,51};
    sort(begin(arr1), end(arr1));
    sort(begin(arr2), end(arr2));
    sort(begin(arr3), end(arr3));
    vector<vector<int>> arrys;
    arrys.push_back(arr1);
    arrys.push_back(arr2);
    arrys.push_back(arr3);

    vector<int> ans = merge_k_sorted_arr(arrys);
    for(auto it: ans){
        cout << it << " ";
    }
}