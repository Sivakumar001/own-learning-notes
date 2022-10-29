#include<queue>
#include<iostream>

using namespace std;

void heapify(vector<int> &arr, int size, int index){
    while(index<size){
        int left = 2*index+1,right=2*index+2;
        int large = index;
        if(left<size && arr[left]>arr[large]){
            large = left;
        }
        if(right<size && arr[right]>arr[large]){
            large = right;
        }
        if(large!=index){
            swap(arr[large], arr[index]);
            index = large;
        }
        else{
            return;
        }
    }
}

int main(){
    vector<int> question = {2,4,1,6,3,7,4};
    int k = 3;
    int size = question.size();
    int ans = 0;
    while(k--){
        for(int i=size/2; i>-1; i--){
            heapify(question, size, i);
        }
        ans = question[0];
        size--;
        swap(question[0], question[size]);
    }
    cout << ans;
    return 0;
}