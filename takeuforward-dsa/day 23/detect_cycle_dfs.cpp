#include<bits/stdc++.h>

using namespace std;

bool detect_cycle(vector<vector<int>> &adj_list, int cur_node, vector<int> &vis, int parent = -1){
    vis[cur_node] = 1;
    for(auto itr: adj_list[cur_node]){
        if(!vis[itr]){
            if(detect_cycle(adj_list, itr, vis, cur_node)){
                return true;
            }
        }
        else if(itr!=parent){
            return true;
        }
    }
    return false;
}


int main(){
    vector<vector<int>> adj_list = {
        {}, {2,3}, {1,3}, {1,2}
    };
    int n = adj_list.size();
    vector<int> vis(n, 0);
    bool flag = false;
    for(int i=1;i<n;i++){
        if(!vis[i]){
            flag = detect_cycle(adj_list, i, vis);
            if(flag)break;
        }
    }
    if(flag){
        cout << "cycle exists";
    }
    else{
        cout << "cycle doesnt exists";
    }
}