#include<bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>>& graph, vector<bool>& visited, int point){
    visited[point] = 1;
    for(auto it: graph[point]){
        if(!visited[it]){
            dfs(graph, visited, it);
        }
    }
}

int numberProvinces(vector<vector<int>> graph){
    int count=0;
    vector<bool> visited(0, graph.size());
    for(size_t i=0;i<graph.size();i++){
        if(!visited[i]){
            count++;
            dfs(graph, visited, i);
        }
    }
    return count;
}

int main(){
    vector<vector<int>> graph_que = {{2},{},{0}};
    cout << numberProvinces(graph_que);
}