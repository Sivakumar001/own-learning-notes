#include<bits/stdc++.h>

using namespace std;

double multiplier(int times, double value){
    double result = 1.0;
    for(int i=0;i<times;i++){
        result = result*value;
    }
    return result;
}

double nthroot(int times, int number){
    double low=1.0;
    double high=number;
    double exp = 1e-6;

    while((high-low)>exp){
        double mid = (low+high)/2.0;
        if(multiplier(times, mid)<number){
            low = mid;
        }
        else{
            high = mid;
        }
    }
    return low;
}

int main(){
    int times = 4;
    int number = 15;
    cout << nthroot(times, number);
    return 0;
}