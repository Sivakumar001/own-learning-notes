#include<bits/stdc++.h>
using namespace std;
/*
j
|
2 3 1

j i
| |
2 3 1

swap here
j i
3 2 1

reverse from j+1
3 1 2

*/
void next_perm(vector<int> &array){
    if(array.size()==1)return;
    int n = array.size();
    int i, j;
    //find number not in ascending order
    for(i=n-2; i>=0; i--){
        if(array[i]<array[i+1]){break;}
    }

    if(i<0){reverse(array.begin(), array.end());}
    //if number is found swap the number to its greater number
    // but less than other numbers(ie smaller to all numbers except i)
    // reverse untill j+1
    else{
        for(j=n-1; j>=0; j--){
            if(array[j]>array[i]){break;}
        }
        swap(array[i], array[j]);
        reverse(array.begin()+j+1, array.end());
    }
}

int main(){
    vector<int> vct = {2,3,1};
    next_perm(vct);
    // built in function
    // next_permutation(vct.begin(), vct.end());
    for(auto it: vct){
        cout << it;
    }
    return 0;
}