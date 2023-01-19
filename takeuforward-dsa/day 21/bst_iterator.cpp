#include<bits/stdc++.h>
#include"../day 20/bst.cpp"

using namespace std;

class bst_iterator{
    public:
        stack<TreeNode*> stk;
        bst_iterator(TreeNode* root){
            pushAll(root);
        }

        int _next(){
            TreeNode* cur = stk.top();
            stk.pop();
            pushAll(cur->right);
            return cur->val;
        }

        bool has_next(){
            return !stk.empty();
        }
    private:
        void pushAll(TreeNode* root){
            while(root){
                stk.push(root);
                root=root->left;
            }
        }
};

int main(){
    binary_search_tree bst;
    vector<int> arr = {8,5,2,7,10,12};
    bst.insert_node(arr);
    bst_iterator cur_itr(bst.root);

    cout << cur_itr._next() << endl;
    cout << cur_itr._next() << endl;
    cout << cur_itr._next() << endl;
    cout << cur_itr._next() << endl;
    cout << cur_itr._next() << endl;
    cout << cur_itr._next() << endl;

    cout << cur_itr.has_next() << " hasnext" << endl;


}