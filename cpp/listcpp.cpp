#include<bits/stdc++.h>
#define LOG(x) :: std::cout << x << std::endl;
// https://stackoverflow.com/questions/1905417/array-vs-vector-vs-list
/* List
    list is similar to array but dynamic in nature
    list does not contain dynamic size but creates automatically(use linked list datastructure)
*/
void list_concept(){
    std::list<int> sample_list;

    for(int i=0;i<10;i++){
        sample_list.push_back(i);
    }

    for(int i=10;i<20;i++){
        sample_list.push_front(i);
    }

    sample_list.pop_back();
    sample_list.pop_front();
    std::list<int>::iterator it = std::prev(sample_list.end(), 3);
    sample_list.erase(it);

    for(auto it: sample_list){
        LOG(it);
    }

    LOG(sample_list.size());
}

int main(){
    list_concept();
    return 0;
}