#include<bits/stdc++.h>

using namespace std;

string kthPermutations(int n, int k){
    int factorial=1;
    vector<int> numbers;

    for(int i=1;i<=n;i++){
        factorial = factorial * i;
        numbers.push_back(i);
    }

    string ans = "";
    k = k-1;

    while(true){
        if(numbers.size()==0){break;}

        factorial = factorial/numbers.size();
        int idx = k/factorial;

        string index = to_string(numbers[k/factorial]);
        numbers.erase(numbers.begin()+(k/factorial));

        k = k%factorial;
        ans+=index;
    }
    return ans;
}

int main(){
    int n=3;
    int k=3;
    string s = kthPermutations(n, k);
    cout << s;
    return 0;
}