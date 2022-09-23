#include<bits/stdc++.h>

using namespace std;

int min_coins(int rupees){
    if(rupees==0)return 0;
    vector<int> coin_values={1000,500,100,50,20,10,5,2,1};
    int number_of_coins=0,rem_amount=rupees;
    int i=0,n=coin_values.size();

    while(i<n){
        if(coin_values[i]<=rem_amount){
            number_of_coins++;
            rem_amount = rem_amount - coin_values[i];
        }else{
            i++;
        }
    }
    return number_of_coins;
}

int main(){
    cout << min_coins(3);
    return 0;
}