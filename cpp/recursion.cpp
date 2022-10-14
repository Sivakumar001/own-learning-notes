#include<bits/stdc++.h>

using namespace std;

void fun(int n, string name, int i=1){
    if(i>n){ 
        return;
    }
    cout << name << endl;
    fun(n, name, i+1);
}

void print_n(int i, int n){
    if(i>n)return;
    cout << i << endl;
    print_n(i+1, n);
}

void print_nto1(int n){
    if(n==0){
        return;
    }
    cout << n << endl;
    print_nto1(n-1);
}

void print_oneback(int n){
    if(n<=0)return;
    print_oneback(n-1);
    cout << n << endl;
}

void print_nback(int n, int i=1){
    if(i>n){
        return;
    }
    print_nback(n, i+1);
    cout << i << endl;
}

int summation(int n){
    if(n==0)return 0;
    return n + summation(n-1);
}

int factorial(int n){
    if(n<=1)return 1;
    return n* factorial(n-1);
}

void reverse_arr(int* arr, int n, int i=0){
    if(i>=n/2)return;
    swap(arr[i], arr[n-i-1]);
    reverse_arr(arr, n, i+1);
}

bool check_palindrome(string s, int n, int i=0){
    if(i>=n/2)return true;
    if(s[i]!=s[n-i-1])return false;
    return check_palindrome(s, n, i+1);
}

int fibonacci(int n){
    if(n<=1)return n;
    int first = fibonacci(n-1);
    int second = fibonacci(n-2);
    return first+second;
}

void print_subseq(vector<int> &ds, int arr[], int n, int i=0){
    if(i>=n){
        for(auto it: ds){
            cout << it << " ";
        }
        cout << endl;
        return;
    }
    ds.push_back(arr[i]);
    print_subseq(ds, arr, n, i+1);
    ds.pop_back();
    print_subseq(ds, arr, n, i+1);
}

int printSumSubArray(int arr[], int n, int que_sum, int summation=0, int i=0){
    if(i==n){
        if(que_sum == summation){
            return 1;
        }
        return 0;
    }
    summation=summation+arr[i];
    int l = printSumSubArray(arr, n,que_sum, summation, i+1);
    summation= summation-arr[i];
    int r = printSumSubArray(arr, n, que_sum, summation, i+1);
    return l+r;
}

int main(){
    int arr[] = {1,2,3,4,5};
    cout << printSumSubArray(arr, 5, 5);
    return 0;
}