#include<bits/stdc++.h>
#define LOG(x) :: std::cout << x << std::endl;
/* 
Priority Queue === Max Heap/ Min Heap
    stores value based on ascending order whatever the user enters
    cares who is on top just like capitalism
    uses heap concept
*/
void priority_queue_concept(){
    std::priority_queue<int, std::vector<int>, std::greater<int>> minheap;
    std::priority_queue<int> maxheap; // default heap is max heap

    for(int i=10; i>0; i--){
        minheap.push(i);
        maxheap.push(i);
    }
    for(int i=0; i<10; i++){
        LOG(maxheap.top());
        maxheap.pop();
    }
    LOG("\n");
    for(int i=0; i<10; i++){
        LOG(minheap.top());
        minheap.pop();
    }


}

int main(){
    priority_queue_concept();
    return 0;
}