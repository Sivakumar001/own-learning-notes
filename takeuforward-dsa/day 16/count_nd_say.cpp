#include<bits/stdc++.h>

using namespace std;

string count_nd_say(int n){
    if(n==1)return "1";
    if(n==2)return "11";
    string ans = "11";

    for(int i=3;i<=n;i++){
        int count=1;
        ans+="&";
        string tmp = "";
        for(int k=1;k<ans.size();k++){
            if(ans[k-1]!=ans[k]){
                tmp += count+'0';
                tmp += ans[k-1];
                count = 1;
            }
            count++;
        }
        ans = tmp;
    }
    return ans;
}

int main(){
    cout << count_nd_say(4);
    return 0;
}