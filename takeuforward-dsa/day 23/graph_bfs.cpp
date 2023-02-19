#include<bits/stdc++.h>

using namespace std;

vector<int> bfs_on_graph(vector<vector<int>> adj, int point){
    vector<bool> visited(adj.size());
    vector<int> answer_bfs;
    queue<int> bfs_queue;

    visited[point] = 1;
    bfs_queue.push(point);

    while(!bfs_queue.empty()){
        int size = bfs_queue.size();
        for(int i=0;i<size;i++){
            int cur_node = bfs_queue.front();
            answer_bfs.push_back(cur_node);
            bfs_queue.pop();
            for(auto it: adj[cur_node]){
                if(!visited[it]){
                    visited[it]=1;
                    bfs_queue.push(it);
                }
            }
        }
    }
    return answer_bfs;
}

int main(){
    int n=0, m=0;
    cin >> n >> m;
    vector<vector<int>> adj(n+1); // one based index so +1
    for(int i=0;i<m;i++){
        int u=0, v=0;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int point = 1;
    vector<int> ans = bfs_on_graph(adj, point);
    for(auto it: ans){
        cout << it << " ";
    }
}



// 4 4
// 1 2
// 2 3
// 3 4
// 4 1
