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

int main(){
    set_concept();
    return 0;
}