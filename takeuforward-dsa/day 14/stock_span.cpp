#include<bits/stdc++.h>

using namespace std;

class StockSpanner{
    public:
        stack<pair<int, int>> stocks;
        StockSpanner(){

        }

        int next(int val){
            int count = 1;
            while(!stocks.empty() && stocks.top().first<=val){
                count += stocks.top().second;
                stocks.pop();
            }
            stocks.push({val, count});
            return stocks.top().second;
        }
};

int main(){
    StockSpanner sp;
    cout << sp.next(100) << endl;
    cout << sp.next(80) << endl;
    cout << sp.next(60) << endl;
    cout << sp.next(70) << endl;
    cout << sp.next(60) << endl;
    cout << sp.next(75) << endl;
    cout << sp.next(85) << endl;

    return 0;
}