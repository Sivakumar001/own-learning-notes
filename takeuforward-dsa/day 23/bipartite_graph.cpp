#include<bits/stdc++.h>

using namespace std;

bool bfs(vector<vector<int>> &adj_list, vector<int> &visited, int start){
    visited[start]=0;
    queue<int> node; 
    node.push(start);
    while(!node.empty()){
        int cur_node = node.front();
        node.pop();
        
        for(auto val: adj_list[cur_node]){
            if(visited[val]==-1){
                visited[val] = !visited[cur_node];
                node.push(val);
            }
            else if(visited[val]==visited[cur_node]){
                return false;
            }
        }
    }
    return true;
}

bool is_bipartite(vector<vector<int>> &adj_list){
    int n = adj_list.size();
    vector<int> visited(n, -1);
    for(int i=0;i<n;i++){
        if(visited[i]==-1){
            if(!bfs(adj_list, visited, i))return false;
        }
    }
    return true;
}
int main(){
    vector<vector<int>> adj_list = {
        {},
        {2},
        {1,3,5},
        {2,4},
        {3,5,6},
        {2,4},
        {4}
    };

    if(is_bipartite(adj_list)){
        cout << "it is bipartite graph";
    }
    else{
        cout << "no it isnt";
    }
}