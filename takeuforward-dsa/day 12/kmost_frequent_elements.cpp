#include<bits/stdc++.h>

using namespace std;

struct comparator{
    bool operator()(pair<int, int>& p1, pair<int, int>& p2){
        if(p1.second<=p2.second || (p1.second==p2.second && p1.first<=p2.second)){
            return true;
        }
        return false;
    }
};

int k_most_frequency(vector<int> arr, int k){
    unordered_map<int, int> count_freq;
    for(auto it: arr){
        count_freq[it]++;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> freq_heap;
    for(auto itr: count_freq){
        cout << itr.first << "\t" << itr.second << "\n";
        freq_heap.push(itr);
    }
    cout << "\n";
    while(k--){
        freq_heap.pop();
    }
    return freq_heap.top().first;
}

int main(){
    vector<int> arr = {1,1,1,1,1,1,2,2,2,2,2,3,3,3,3,3,3,3,4,4,4,4,4,5,5,5,5,5,3,6,6,6,6,4,4,4,4,2,2,2,2,2,2,2,1};
    int k = 2;
    cout << k_most_frequency(arr, k);
}