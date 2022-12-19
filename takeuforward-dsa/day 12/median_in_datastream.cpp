#include<bits/stdc++.h>

using namespace std;

class MedianFinder{
    public:
        priority_queue<int, vector<int>> max_hp;
        priority_queue<int, vector<int>, greater<int>> min_hp;

        void add(int element){
            max_hp.push(element);
            min_hp.push(max_hp.top());
            max_hp.pop();
            if(min_hp.size()>max_hp.size()){
                max_hp.push(min_hp.top());
                min_hp.pop();
            }
        }

        double findMed(){
            int sum = max_hp.size()+min_hp.size();
            if(sum%2==0){
                return (max_hp.top()+min_hp.top())/2.0;
            }
            return max_hp.top();
        }
};
int main(){
    MedianFinder mf;
    mf.add(2);
    mf.add(5);
    mf.add(4);
    mf.add(6);
    mf.add(1);

    cout << mf.findMed();
}