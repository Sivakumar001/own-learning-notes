#include<bits/stdc++.h>
#define LOG(x) :: std::cout << x << std::endl;
/* 
Vector
    dynamic array
    uses dynamic sizes to power of 2
*/
void vector_concept(){
    std::vector<int> sample_vector;

    for(int i=0;i<10;i++){
        sample_vector.push_back(i);
    }
    sample_vector.pop_back();
    sample_vector.insert(sample_vector.begin()+2, 1);
    sample_vector[2] = 23;
    LOG(sample_vector.at(4));
    for(auto it : sample_vector){
        LOG(it);
    }
    LOG(sample_vector.size());
    LOG(sample_vector.back());
    std::vector<int> vector_with_values(5, 6);
    for(auto it : vector_with_values){
        LOG(it);
    }
}

int main(){
    vector_concept();
    return 0;
}