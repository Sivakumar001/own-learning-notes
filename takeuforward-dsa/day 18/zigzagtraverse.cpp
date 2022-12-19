#include<bits/stdc++.h>
#include"../day 17/binary_tree.cpp"

using namespace std;

vector<vector<int>> zigzag(TreeNode* root){
    vector<vector<int>> ans;
    queue<TreeNode*> q;
    q.push(root);
    bool flag=true;

    while(!q.empty()){

        int size = q.size();
        vector<int> cur_level(size);
        for(int i=0;i<size;i++){
            TreeNode* tmp = q.front();
            q.pop();
            if(tmp->left)q.push(tmp->left);
            if(tmp->right)q.push(tmp->right);
            int index = (flag)? i:(size-i-1);
            cur_level[index] = tmp->val;
        }
        flag = !flag;
        ans.push_back(cur_level);

        // while(size>0){
        //     Node* tmp = q.front();
        //     q.pop();size--;
        //     cur_level.push_back(tmp->val);
        //     if(tmp->left)q.push(tmp->left);
        //     if(tmp->right)q.push(tmp->right);
        // }

        // if(flag){
        //     ans.push_back(cur_level);
        //     flag=false;
        // }
        // else{
        //     reverse(cur_level.begin(), cur_level.end());
        //     ans.push_back(cur_level);
        //     flag=true;
        // }

        // cur_level.clear();
    }

    return ans;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    TreeNode* n = buildTree(arr, arr.size());
    vector<vector<int>> ans = zigzag(n);
    for(auto it: ans){
        for(auto itr: it){
            cout << itr << " ";
        }
        cout << endl;
    }
    return 0;
}