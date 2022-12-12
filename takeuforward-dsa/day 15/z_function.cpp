#include<vector>
#include<iostream>
#include<string>

using namespace std;

bool check_present(string text,  string pattern){
    string z_concat = text+"$"+pattern;
    vector<int> z_arr(z_concat.size(),0);
    int p_ind=0;
    int l=0,r=0;
    for(int i=1;i<z_concat.size();i++){
        if(z_concat[p_ind]==z_concat[i]){
            r++;
            p_ind++;
        }
        else{
            l=i;
            z_arr[i]=p_ind;
            p_ind=0;
        }
    }

    for(auto it: z_arr){
        if(it==pattern.size())return true;
    }
    return false;
}

int main(){
    string pattern = "aax";
    string text = "aababbaabbabaaxbabaaxabx";

    if(check_present(text, pattern))cout<< "present";
    cout<< endl;

    return 0;
}