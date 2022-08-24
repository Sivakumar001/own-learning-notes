#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int width=2*n;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j<=i){
                cout << j;
            }
            else{
                cout << " ";
            }
        }
        for(int j=n;j>0;j--){
            if(j>i){
                cout << " ";
            }else{
                cout << j;
            }
        }
        cout << "\n";
    }
    return 0;
}