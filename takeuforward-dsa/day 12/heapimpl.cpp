#include<bits/stdc++.h>

using namespace std;
// https://stackoverflow.com/a/22900767/12077335

class heapqzero{
    public:
    int arr[100];
    int size;

    heapqzero(){
        size = 0;
    }
    void insert(int value){
        arr[size] = value;
        int index = size;
        while(index>0){
            int parent = (index-1)/2;
            if(arr[index]>arr[parent]){
                swap(arr[index], arr[parent]);
                index = parent;
            }else{
                break;
            }
        }
        size++;
    }

    void delete_root(){
        if(size==0)return;
        arr[0] = arr[size-1];
        size--;
        int index = 0;
        while(index<size){
            int left = (2*index)+1, right = (2*index)+2;
            int largest = index;
            if(left<size && arr[left]>arr[largest]){
                largest = left;
            }
            if(right<size && arr[right]>arr[largest]){
                largest = right;
            }
            if(largest!=index){
                swap(arr[largest], arr[index]);
                index = largest;
            }
            else{
                return;
            }
        }
    }

    void print(){
        for(int i=0;i<size;i++){
            cout << arr[i] << " ";
        }cout << endl;
    }
};

class heapq{
    public:
        int arr[100];
        int size;

    heapq(){
        size = 0;
        arr[0]=-1;
    }

    void insert(int value){
        size++;
        int index = size;
        arr[index] = value;

        while(index>1){
            int parent = index/2;
            if(arr[index]>arr[parent]){
                swap(arr[index], arr[parent]);
                index = parent;
            }
            else{
                return;
            }
        }
    }

    void root_delete(){
        int i = 1;
        swap(arr[i], arr[size]);
        size--;
        while(i<size){
            int left = 2*i, right = 2*i+1;

            if(left<size && arr[left]>arr[i]){
                swap(arr[left], arr[i]);
                i=left;
            }
            else if(right<size && arr[right]>arr[i]){
                swap(arr[right], arr[i]);
                i = right;
            }
            else{
                return;
            }
        }
    }

    int top(){
        return arr[1];
    }

    void print(){
        for(int i=1;i<=size;i++){
            cout << arr[i] << " ";
        }cout << endl;
    }

    bool isEmpty(){
        return size==0;
    }
};

void heapify(int arr[], int n, int i){
    int parent = i;
    int left = 2*i;
    int right = 2*i+1;
    int largest = parent;
    if(left<n && arr[left]>arr[parent]){
        largest = left;
    }
    if(right<n && arr[right]>arr[largest]){
        largest = right;
    }
    if(largest!=parent){
        swap(arr[largest], arr[parent]);
        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n){
    int size = n;
    while(size>1){
        swap(arr[1], arr[size]);
        size--;
        heapify(arr, size, 1);
    }
}
int main(){
    vector<int> hp = {50,55,54,53,57};
    heapq cur_hp;
    for(auto it: hp){
        cur_hp.insert(it);
    }
    // cur_hp.print();
    // cur_hp.root_delete();
    // cur_hp.print();

    int arr[6] = {-1, 54, 57, 53, 55, 52};
    int n = 5;
    for(int i=n/2;i>0;i--){
        heapify(arr, n, i);
    }

    for(int i=1;i<6;i++){
        cout << arr[i] << " ";
    }cout << endl;

    heap_sort(arr, n);
    for(int i=1;i<6;i++){
        cout << arr[i] << " ";
    }cout << endl;
    return 0;
}