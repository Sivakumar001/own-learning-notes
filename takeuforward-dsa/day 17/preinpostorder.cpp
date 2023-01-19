#include<bits/stdc++.h>
#include"binary_tree.cpp"

using namespace std;

vector<vector<int>> allorderTraversal(TreeNode* root){
    vector<int> preorder, inorder, postorder;
    stack<pair<TreeNode*, int>> st;
    st.push({root, 0});
    while(!st.empty()){
        auto it = st.top();
        st.pop();

        if(it.second==0){
            preorder.push_back(it.first->val);
            it.second++;
            st.push(it);
            if(it.first->left){
                st.push({it.first->left, 0});
            }
        }
        else if(it.second==1){
            inorder.push_back(it.first->val);
            it.second++;
            st.push(it);
            if(it.first->right){
                st.push({it.first->right, 0});
            }
        }
        else{
            postorder.push_back(it.first->val);
        }
    }

    vector<vector<int>> ans;
    ans.push_back(preorder);
    ans.push_back(inorder);
    ans.push_back(postorder);
    return ans;
}
int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    TreeNode* root = buildTree(arr, arr.size());
    vector<vector<int>> ans = allorderTraversal(root);
    for(auto itr: ans){
        for(auto it: itr){
            cout << it << " ";
        }
        cout << endl;
    }
}