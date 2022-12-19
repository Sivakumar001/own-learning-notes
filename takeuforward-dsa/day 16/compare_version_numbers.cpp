#include<bits/stdc++.h>

using namespace std;

bool compare_versions(string v1, string v2){
    int m=v1.size(), n=v2.size();
    int i=0,j=0;
    int n1=0, n2=0;
    while(i<m || j<n){
        while(i<m && v1[i]!='.'){
            n1 = n1*10+(v1[i]-'0');
            i++;
        }
        while(j<n && v2[j]!='.'){
            n2 = n2*10+(v2[j]-'0');
            j++;
        }
        if(n1>n2){
            return 1;
        }
        if(n1<n2){
            return 0;
        }
        i++;j++;
        n1=0;n2=0;
    }
}
int main(){
    string v1 = "1.22.44.00.3";
    string v2 = "1.22.44.00.2";

    if(compare_versions(v1, v2)==1){
        cout << "v1 is latest version";
    }
    else{
        cout << "v2 is the latest version";
    }
}