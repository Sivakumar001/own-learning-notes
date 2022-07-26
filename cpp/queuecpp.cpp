#include<bits/stdc++.h>
#define LOG(x) :: std::cout << x << std::endl;
/*
Queue
    First In First Out
    spotify playlist,
    ticket queue,
*/
void queue_concept(){
    std::queue<int> sample_queue;
    sample_queue.push(4);
    sample_queue.push(1);
    sample_queue.push(3);

    for(int i=0; i<3; i++){
        LOG(sample_queue.front());
        sample_queue.pop();
    }
    if(sample_queue.empty()) LOG("empty");
}
int main(){
    queue_concept();
    return 0;
}