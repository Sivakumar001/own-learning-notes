#include<bits/stdc++.h>
#include"bst.cpp"

using namespace std;

int postOrder(TreeNode* root){
    stack<TreeNode*> st;
    int ans=0;
    TreeNode* cur = root;
    while(!st.empty() || cur){
        if(cur){
            st.push(cur);
            cur = cur->left;
        }
        else{
            TreeNode* tp = st.top()->right;
            if(tp==nullptr){
                tp = st.top();
                st.pop();
                cout << tp->val << " ";ans++;
                while(!st.empty() && tp==st.top()->right){
                    tp = st.top();
                    st.pop();
                    cout << tp->val << " ";ans++;
                }
            }
            else{
                cur = tp;
            }
        }
    }
    cout << "ans = " << ans << endl;
    return ans;
}
// inorder morris traversal
int kth_largest(TreeNode* root, int k){
    k = postOrder(root)-k;
    TreeNode* cur = root;
    int ans=0;
    while(cur && k){
        if(cur->left==nullptr){
            ans = cur->val;k--;
            cur = cur->right;
        }
        else{
            TreeNode* pre = cur->left;
            while(pre->right!=nullptr && pre->right!=cur){
                pre = pre->right;
            }
            if(pre->right==nullptr){
                pre->right = cur;
                cur = cur->left;
            }
            if(pre->right == cur){
                pre->right = nullptr;
                ans = cur->val;k--;
                cur = cur->right;
            }
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {2,3,1, 5, 8, 12, 21, 34};
    binary_search_tree bst;
    bst.insert_node(arr);
    TreeNode* root = bst.root;
    cout << kth_largest(root, 2);
}