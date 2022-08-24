#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int space = 2*n-2;

    vector<vector<int>> pascal_tri(n);
    for(int i=0;i<n;i++){
        pascal_tri[i].resize(i+1);
        pascal_tri[i][0]=pascal_tri[i][i]=1;

        for(int j=1;j<i;j++){
            pascal_tri[i][j]=pascal_tri[i-1][j-1]+pascal_tri[i-1][j];
        }
    }

    
    for(int i=1;i<=n;i++){
        for(int j=n;j>0;j--){
            if(j>i){
                cout << " ";
            }else{
                cout << "* ";
            }
        }
        cout << "\n";
    }
    return 0;
}