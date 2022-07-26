#include <bits/stdc++.h>
#define LOG(x) ::std::cout << x << std::endl;

using namespace std;

int main()
{
    /* Algorithms
    binary search
    sort
    swap
    max
    min
    lower bound/ upper bound
    reverse
    rotate
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