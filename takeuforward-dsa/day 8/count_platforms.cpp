#include<bits/stdc++.h>

using namespace std;

int number_of_platforms(vector<int> arr, vector<int> dept){
    int max_platforms=1, platform=1;
    sort(arr.begin(), arr.end());
    sort(dept.begin(), dept.end());

    int i=1,j=0, n=arr.size();
    while(i<n && j<n){
        if(arr[i]<=dept[j]){
            platform++;
            i++;
        }
        else if(arr[i]>dept[j]){
            platform--;
            j++;
        }
        max_platforms = max(max_platforms, platform);
    }
    
    return max_platforms;
}

int main(){
    vector<int> arrival = {900, 945, 955, 1100, 1500, 1800};
    vector<int> departure = {920, 1200, 1130, 1150, 1900, 2000};

    cout << number_of_platforms(arrival, departure);
    return 0;
}