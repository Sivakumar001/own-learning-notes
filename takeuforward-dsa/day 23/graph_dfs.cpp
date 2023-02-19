#include<bits/stdc++.h>

using namespace std;

void dfs_on_graph(vector<vector<int>>& graphs, int point, vector<int>& ans, vector<int>& visited){
    visited[point] = 1;
    ans.push_back(point);
    for(auto it: graphs[point]){
        if(!visited[it]){
            dfs_on_graph(graphs, it, ans, visited);
        }
    }
}

int main(){
    int nodes=0, mapping=0;
    cin >> nodes >> mapping;
    vector<vector<int>> graphs(nodes+1);
    for(int i=1;i<=mapping;i++){
        int u=0, v=0;
        cin >> u >> v;
        graphs[u].push_back(v);
        graphs[v].push_back(u);
    }

    int point = 3;
    vector<int> ans, visit(nodes+1);
    dfs_on_graph(graphs, point, ans, visit);
    for(auto itr: ans){
        cout << itr << " ";
    }
}