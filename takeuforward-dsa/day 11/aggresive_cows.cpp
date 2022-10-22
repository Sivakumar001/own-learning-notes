#include<bits/stdc++.h>

using namespace std;

bool  canPlace(vector<int> &stall, int cows, int mid){
    int distance = stall[0];
    int count=1;
    for(int i=1;i<stall.size();i++){
        if(stall[i]-distance >= mid){
            count++;
            distance = stall[i];
        }
    }
    if(count>=cows)return true;
    return false;
}
int aggresive_cow(vector<int> &stall, int cows){
    int n=stall.size();
    int low = 1, high = stall[n-1]-stall[0];

    while(low<=high){
        int mid = (low+high)>>1;
        if(canPlace(stall, cows, mid)){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return high;
}

int main(){
    vector<int> stall = {1,2,8,4,9};
    sort(stall.begin(), stall.end());
    int cows = 3;
    cout << aggresive_cow(stall, cows);
    return 0;
}