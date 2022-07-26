#include<bits/stdc++.h>
#define LOG(x) :: std::cout << x << std::endl;
/* 
Set 
    elements are unique in nature
    cant modify
    ordered set/ unordered set
    ordered set use bst
*/
void set_concept(){
    std::set<int> sample_set;
    sample_set.insert(2);
    sample_set.insert(3);
    sample_set.insert(3);
    sample_set.insert(3);
    sample_set.insert(3);
    sample_set.insert(4);
    sample_set.erase(sample_set.begin(), (std::next(sample_set.begin(),2)));
    for(auto it: sample_set){
        LOG(it);
    }
}

void unordered_set_concept(){
    std::unordered_set<int> sample_unordered_set;
    sample_unordered_set.insert(10);
    sample_unordered_set.insert(1);
    sample_unordered_set.insert(3);
    sample_unordered_set.insert(3);

    for(auto it: sample_unordered_set){
        LOG(it);
    }

    std::string x = (sample_unordered_set.count(10)>0)? "Hi": "Bye";
    LOG(x);
}

int main(){
    set_concept();
    unordered_set_concept();
    return 0;
}