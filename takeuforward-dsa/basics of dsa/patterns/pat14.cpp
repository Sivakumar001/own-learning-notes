#include<bits/stdc++.h>
using namespace std;

void printer(int **arr, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << (arr[i][j]);
        }
        cout << "\n";
    }
}
int main(){
    int n;
    cin >> n;
    int size=(2*n)-1;
    
    int **arr = new int*[size];

    for(int i=0;i<size;i++){
        arr[i]=new int[size];
    }
    
    int start=0,end=size-1;

    while(n!=0){
        for(int i=start;i<=end;i++){
            for(int j=start;j<=end;j++){
                if(i==start || j==start || i==end || j==end){
                    arr[i][j]=n;
                }
            }
        }
        start++;
        end--;
        n--;
    }
    printer(arr, size);
    return 0;
}