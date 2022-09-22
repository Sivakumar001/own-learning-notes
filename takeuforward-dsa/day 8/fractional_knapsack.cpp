#include<bits/stdc++.h>

using namespace std;

struct knap{
    int value;
    int weight;
};

bool static comparator(knap a, knap b){
    double a_ppv = a.value/a.weight;
    double b_ppv = b.value/b.weight;
    if(a_ppv>b_ppv)return true;
    else if(a_ppv<b_ppv)return false;
    else if(a.weight<b.weight)return true;
}

int fractional_knapsack(int values[], int weight[], int n, int target){
    vector<knap> sacks(n);
    for(int i=0;i<n;i++){
        sacks[i].value=values[i];
        sacks[i].weight=weight[i];
    }
    sort(sacks.begin(), sacks.end(), comparator);

    int cur_weight=0,cur_value=0;

    for(auto sack: sacks){
        if(cur_weight+sack.weight < target){
            cur_weight += sack.weight;
            cur_value += sack.value;
        }
        else{
            int rem_weight=target-cur_weight;
            cur_weight += rem_weight;
            cur_value += rem_weight*(double)(sack.value/sack.weight);
            return cur_value;
        }
    }
    return -1;
}
int main(){
    int values[]={100,60,120};
    int weight[]={20,10,30};
    cout << fractional_knapsack(values, weight, 3, 50);
    return 0;
}