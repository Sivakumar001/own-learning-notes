#include<bits/stdc++.h>

using namespace std;
struct meeting{
    int start;
    int end;
    int pos;
};

bool meeting_comparator(meeting m1, meeting m2){
    if(m1.end < m2.end)return true;
    else if(m1.end > m2.end)return false;
    else if(m1.pos < m2.pos)return true;
    return false;
}

vector<int> n_meetings(vector<int> start, vector<int> end){
    vector<int> answer;
    
    vector<meeting> meetings(start.size());
    for(int i=0;i<start.size();i++){
        meetings[i].start = start[i];
        meetings[i].end = end[i];
        meetings[i].pos = i+1;
    }

    sort(meetings.begin(), meetings.end(), meeting_comparator);
    for(auto itr: meetings){
        cout << itr.start << " " << itr.end;
    }
    int limit = meetings[0].end;
    answer.push_back(meetings[0].pos);

    for(int i=1;i<meetings.size();i++){
        if(limit < meetings[i].start){
            limit = meetings[i].end;
            answer.push_back(meetings[i].pos);
        }
    }

    return answer;
}
int main(){
    vector<int> start={1,3,0,5,8,5};
    vector<int> end={2,4,5,7,9,9};
    vector<int> a = n_meetings(start, end);
    for(auto itr: a){
        cout << itr << " ";
    }
    return 0;
}