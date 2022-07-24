#include <bits/stdc++.h>
#define LOG(x) ::std::cout << x << std::endl;

using namespace std;

int main()
{
    /* Array
    it is similar to normal declaration but convenient in access/copy
    can be passed in function by value
    can use for iterator based calculation below
    */
    array<int, 5> supra_int;

    for (int i = 0; i < 5; i++)
    {
        supra_int[i] = i;
    }
    LOG(supra_int.size());
    LOG(supra_int.at(3));   // 3
    LOG(supra_int.empty()); // false
    LOG(supra_int.front()); // 0
    LOG(supra_int.back());  // 4

    for (int *i = supra_int.begin(); i != supra_int.end(); i++)
    {
        LOG(*i);
    }
    LOG("***vector****")

    /* Vector
    dynamic array
    uses dynamic sizes to power of 2
    */
    vector<int> vct;

    LOG(vct.capacity());

    for (int i = 0; i < 10; i++)
    {
        vct.push_back(i);
    }

    LOG(vct.size());
    LOG(vct.capacity());

    vct.pop_back();
    LOG(vct.back());

    vct.insert(vct.begin() + 3, 88);
    for (int i = 0; i < 10; i++)
    {
        LOG(vct[i]);
    }

    for (std::vector<int>::iterator i = vct.begin(); i != vct.end(); i++)
    {
        LOG(*i);
    }
    vct.clear();
    LOG(vct.size());
    vector<int> a(5, 1);
    for (int i : a)
    {
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

    dq.erase(dq.begin(), dq.end() - 1);

    for (deque<int>::iterator i = dq.begin(); i != dq.end(); i++)
    {
        LOG(*i);
    }

    LOG("*****LIST*******")

    list<int> number_list(8, 100);

    number_list.push_back(2);
    number_list.push_back(3);
    number_list.pop_front();
    number_list.pop_back();

    for (std::list<int>::iterator i = number_list.begin(); i != number_list.end(); i++)
    {
        LOG(*i);
    }

    std::list<int>::iterator itr = number_list.begin();
    advance(itr, 1);

    number_list.erase(itr, number_list.end());
    LOG("after removal")
    for (std::list<int>::iterator i = number_list.begin(); i != number_list.end(); i++)
    {
        LOG(*i);
    }
    LOG(number_list.size());

    /* Stack
    Last In First Out
    bookstack,
    ctrl+z,
    browser back button,
    */

    stack<string> stck;
    stck.push("Siva");
    stck.push("kumar");

    LOG(stck.size());

    LOG(stck.top());
    stck.pop();
    LOG(stck.top());

    LOG(stck.empty());

    LOG("****Queue*****");
    /* Queue
    First In First Out
    spotify playlist,
    ticket queue,
    */

    queue<string> q;
    q.push("al;kwhjrgnawrg");
    q.push("siva");
    q.push("kumar");

    LOG(q.size());

    q.pop();
    LOG(q.back());

    LOG(q.empty());
    LOG("*****Priority Queue*****")
    /* Priority Queue === Max Heap/ Min Heap
    stores value based on ascending order whatever the user enters
    cares who is on top just like capitalism
    */

    priority_queue<int> maxh; //default is max heap
    priority_queue<int, vector<int>, greater<int>> minh;

    maxh.push(1);
    maxh.push(488);
    maxh.push(4);
    maxh.push(50);

    int size = maxh.size();
    for(int i=0;i<size; i++){
        LOG(maxh.top());
        maxh.pop();
    }

    minh.push(0);
    minh.push(100);
    minh.push(1000);
    minh.push(43);

    for(int i=0;i<size;i++){
        LOG(minh.top());
        minh.pop();
    }

    LOG(maxh.empty());
    LOG(minh.empty());

    LOG("*****set*****");
    /* Set 
    elements are unique in nature
    cant modify
    ordered set/ unordered set
    */

    set<int> st;
    st.insert(2);
    st.insert(1);
    st.insert(3);
    st.insert(5);
    st.insert(7);

    for(set<int>::iterator i=st.cbegin(); i!=st.cend(); i++){
        LOG(*i);
    }
    LOG(st.size());
    
    unordered_set<int> unset;
    unset.insert(3);
    unset.insert(1);
    unset.insert(5);
    unset.insert(4);
    unset.insert(2);
    for(auto itr=unset.begin(); itr!=unset.end();itr++){
        LOG(*itr);
    }

    LOG("*****Map*******");
    /*
    Map or Dictionary
    uses key value pair for storing values
    Powerful for interviews
    */
    map<int, string> user;
    user[10] = "siva";
    user[21] = "kumar";
    user[3] = "sundar";
    user[4] = "keerthi";

    user.insert({56,"bheem"});
    user.erase(10);
    for(std::pair<int, string> i: user){
        LOG(i.second);
    }
    for(auto itr=user.find(3); itr!=user.end();itr++){
        LOG((*itr).first);
    }

    unordered_map<int, string> umap;
    umap[12] = "senthil";
    umap[34] = "rajini";
    umap[85] = "chandramuki";

    for(auto i=umap.begin(); i!=umap.end(); i++){
        LOG((*i).first);
    }

    LOG("****ALGORITHMS*****");
    /* Algorithms
    */

    vector<int> alvct = {1,4,2,3,7,89,54,11,34};

    sort(alvct.begin(), alvct.end()); //sorts the array
    
    LOG(binary_search(alvct.begin(), alvct.end(), 11)); //binary search

    LOG(*(lower_bound(alvct.begin(), alvct.end(), 3)));
    LOG(*(upper_bound(alvct.begin(), alvct.end(), 4)));
    
    int x = 10;
    int y = 20;
    swap(x, y);
    
    LOG(max(x, y));
    LOG(min(x, y));

    string s = "siva";
    reverse(s.begin(), s.end());
    LOG(s);

    vector<int> b = {1,2,3,4,5,6,7};
    rotate(b.begin(), b.begin()+2, b.end());
    for(auto i: b){
        LOG(i);
    }
}