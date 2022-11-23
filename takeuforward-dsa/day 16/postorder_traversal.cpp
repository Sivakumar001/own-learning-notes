#include<bits/stdc++.h>
#include"binary_tree.cpp"

using namespace std;
//using recursion
void postorder_traversal(Node* root, vector<int>& vct){
    if(root==nullptr){
        return;
    }
    postorder_traversal(root->left, vct);
    postorder_traversal(root->right, vct);
    vct.push_back(root->val);
}

//using stack
vector<int> postorder_traversal(Node* root){
    vector<int> ans;
    stack<Node*> st;
    while(root!=nullptr || !st.empty()){
        if(root!=nullptr){
            st.push(root);
            root = root->left;
        }
        else
        {
            Node* tmp = st.top()->right;
            if(tmp==nullptr)
            {
                tmp = st.top();
                st.pop();
                ans.push_back(tmp->val);
                while(!st.empty() && tmp==st.top()->right){
                    tmp = st.top();
                    st.pop();
                    ans.push_back(tmp->val);
                }
            }
            else
            {
                root = tmp;
            }
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {1,2,3};
    Node* n = buildTree(arr, arr.size());
    vector<int> ans = postorder_traversal(n);
    // postorder_traversal(n, ans);
    for(auto it: ans){
        cout << it << " ";
    }
}