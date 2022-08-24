#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    for(int i=1;i<=n;i++){
        for(int j=n;j>i;j--){
            cout << " ";
        }
        for(int j=0;j<i;j++){
            cout << char('A'+j);
        }
        for(int j=i-1;j>0;j--){
            cout << char('A'+j-1);
        }
        cout << "\n";
    }
    return 0;
}