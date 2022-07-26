#include<bits/stdc++.h>
#define LOG(x) :: std::cout<< x <<std::endl;
/* Array
    it is similar to normal declaration but convenient in access/copy
    can be passed in function by value
    can use for iterator based calculation below
*/
void array_function(){
    std::array<int, 10> sampleArray;
    for(int i=0; i<10; i++){
        sampleArray[i] = i;
    }
    int sizeOfArray = sampleArray.size();
    LOG(sizeOfArray);
    int atPosTwo = sampleArray.at(2);
    LOG(atPosTwo);
    for(auto it = sampleArray.begin(); it!=sampleArray.end(); it++){
        LOG(*it);
    }
}

int main(){
    array_function();
    return 0;
}