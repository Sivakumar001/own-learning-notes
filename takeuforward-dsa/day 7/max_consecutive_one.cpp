#include<bits/stdc++.h>

using namespace std;

int max_ones(vector<int> arr){
    int len=arr.size();
    int count = 0;
    int max_count = 0;
    for(int i=0;i<len;i++){
        if(arr[i]==1){
            count++;
        }else{
            max_count = max(max_count, count);
            count = 0;
        }
    }
    return max_count;
}
int main(){
    vector<int> arr={1,1,0,0,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1};
    cout << max_ones(arr);
    return 0;
}