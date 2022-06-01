#include<bits/stdc++.h>
#define LOG(x) :: std::cout<< x <<std::endl;

using namespace std;

int main(){
    /* Array 
    it is similar to normal declaration but convenient in access/copy
    can be passed in function by value
    can use for iterator based calculation below
    */
    array<int, 5> supra_int;
    
    for(int i=0;i<5;i++){
        supra_int[i] = i;
    }
    LOG(supra_int.size());
    LOG(supra_int.at(3)); // 3
    LOG(supra_int.empty()); //false
    LOG(supra_int.front()); //0
    LOG(supra_int.back()); //4

    for(int* i=supra_int.begin(); i!=supra_int.end(); i++){
        LOG(*i);
    }
    LOG("***vector****")

    /* Vector 
    dynamic array
    uses dynamic sizes to power of 2
    */
    vector<int> vct;
    
    LOG(vct.capacity());
   
    for(int i=0;i<10;i++){
       vct.push_back(i);
    }
    
    LOG(vct.size());
    LOG(vct.capacity());
    
    vct.pop_back();
    LOG(vct.back());

    vct.insert(vct.begin()+3, 88);
    for(int i=0;i<10;i++){
       LOG(vct[i]);
    }

    for(std::vector<int>::iterator i = vct.begin(); i!=vct.end(); i++){
        LOG(*i);
    }
    vct.clear();
    LOG(vct.size());
    vector<int> a(5,1);
    for(int i: a){
        LOG(i);
    }
    LOG("****deque****")
    /* deque
    can add/remove from back or front
    act both queue and stack
    */

    deque<int> dq;
    dq.push_front(232);
    dq.push_back(357);

    dq.push_back(464);
    dq.push_front(167);
    LOG(dq.size());
    
    dq.pop_back();
    dq.pop_front();
    LOG(dq.size());

    dq.erase(dq.begin(), dq.end()-1);

    for(deque<int>::iterator i= dq.begin(); i!=dq.end(); i++){
        LOG(*i);
    }

    LOG("*****LIST*******")

    list<int> number_list(8, 100);

    number_list.push_back(2);
    number_list.push_back(3);
    number_list.pop_front();
    number_list.pop_back();

    for(std::list<int>::iterator i=number_list.begin(); i!=number_list.end(); i++){
        LOG(*i);
    }
    
    std::list<int>::iterator itr = number_list.begin();
    advance(itr, 1);

    number_list.erase(itr , number_list.end());
    LOG("after removal")
    for(std::list<int>::iterator i=number_list.begin(); i!=number_list.end(); i++){
        LOG(*i);
    }
    LOG(number_list.size());

    /* Stack 
    First In Last Out
    bookstack,
    ctrl+z,
    browser back button,
    */
}