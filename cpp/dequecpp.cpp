#include<bits/stdc++.h>
#define LOG(x) :: std::cout << x << std::endl;
/* deque
    can add/remove from back or front
    act both queue and stack
*/

void dequeue_concept(){
    std::deque<int> sample_dequeue;
    for(int i=0; i<5; i++){
        sample_dequeue.push_front(i);
    }
    for(int i=5;i<10;i++){
        sample_dequeue.push_back(i);
    }
    
    LOG(sample_dequeue.size());
    LOG(sample_dequeue.at(4));

    for(auto it: sample_dequeue){
        LOG(it);
    }
}   

int main(){
    dequeue_concept();
    return 0;
}