#include<bits/stdc++.h>

using namespace std;

bool detect_cycle(vector<vector<int>> &adj_list, pair<int, int> node, int visited[]){
    queue<pair<int, int>> bfs;
    bfs.push(node);
    visited[node.first]=1;
    while(!bfs.empty()){

        int cur_node = bfs.front().first;
        int parent = bfs.front().second;
        bfs.pop();

        for(auto itr: adj_list[cur_node]){
            if(!visited[itr]){
                visited[itr]=1;
                bfs.push({itr, cur_node});
            }
            else if(itr!=parent){
                return true;
            }
        }
    }
    return false;
}

int main(){
    vector<vector<int>> adj_list = {
        {}, {2}, {1, 3}, {2}
    };


    int visited[adj_list.size()] = {0};
    bool flag=true;
    for(int i=0;i<adj_list.size();i++){
        if(!visited[i]){
            if(detect_cycle(adj_list, {i, -1}, visited)){
                flag = false;
                cout << "cycle exist";
            }
        }
    }
    if(flag)cout << "cycle doesnt exist";
}