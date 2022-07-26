#include<bits/stdc++.h>
#define LOG(x) :: std::cout << x << std::endl;
/*
Map
    stores in key value pair
    O(1) complexity
    throw hashmap in interview as it is powerfull
*/
void map_concept(){
    std::map<int, std::string> sample_map;
    sample_map.insert({1, "sk"});
    sample_map[2] = "siva";
    sample_map[3] = "kumar";
    sample_map.erase(3);
    for(auto it: sample_map){
        LOG(it.first);
        LOG(it.second);
    }
    LOG((*sample_map.find(2)).second);LOG("hi")

    std::unordered_map<int, std::string> sample_unordered_map;
    sample_unordered_map[2]="kumar";
    sample_unordered_map[3]="siva";
    sample_unordered_map[1]="sk";
    for(auto it: sample_unordered_map){
        LOG(it.first);
        LOG(it.second)
    }
}

int main(){
    map_concept();
    return 0;
}