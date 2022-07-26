#include <bits/stdc++.h>
#define LOG(x) ::std::cout << x << std::endl;

using namespace std;

int main()
{
    LOG("*****set*****");
    

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