#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int row = 2*n, col= 2*n;
    for(int i=1;i<=row;i++){
        for(int j=1;j<=col;j++){
            if(i==1 || j==1 || i==row || j==col){
                cout << "*";
            }
            else{
                cout << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}