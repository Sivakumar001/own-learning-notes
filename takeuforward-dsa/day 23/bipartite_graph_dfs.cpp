#include<bits/stdc++.h>

using namespace std;

bool dfs(vector<vector<int>> adj_list, vector<int> visited, int i, int parent){
    visited[i] = parent;
    for(auto val: adj_list[i]){
        if(visited[val]==-1){
            if(!dfs(adj_list, visited, val, !parent))return false;
        }
        else if(visited[val]==parent){
            return false;
        }
    }
    return true;
}

bool is_bipartite(vector<vector<int>> &adj_list){
    int n = adj_list.size();
    vector<int> visited(n, -1);
    for(int i=0;i<n;i++){
        if(visited[i]==-1){
            if(!dfs(adj_list, visited, i, 0))return false;
        }
    }
    return true;
}

int main(){
    vector<vector<int>> adj_list = {
        {1},
        {0,2,4},
        {1,3},
        {2,6,5},
        {1,5},
        {3,4},
        {3,7},
        {6}
    };

    if(is_bipartite(adj_list)){
        cout << "it is a bipartite graph";
    }
    else{
        cout << "no it isnt";
    }
}