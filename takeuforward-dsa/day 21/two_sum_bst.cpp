#include<bits/stdc++.h>
#include"../day 20/bst.cpp"

using namespace std;

class bst_iterator{
    public:
        stack<TreeNode*> asc_stk;
        bool isReverse = true;
        bst_iterator(TreeNode* root, bool reverse){
            isReverse = reverse;
            pushAll(root, isReverse);
        }

        int _next(){
            TreeNode* cur = asc_stk.top();
            asc_stk.pop();
            pushAll(cur->right, isReverse);
            return cur->val;
        }

        bool has_nxt(){
            return !asc_stk.empty();
        }

    private:
        void pushAll(TreeNode* root, bool reverse){
            while(root){
                if(reverse){
                    asc_stk.push(root);
                    root = root->right;
                }
                else{
                    asc_stk.push(root);
                    root = root->left;
                }
            }
        }
};

pair<int, int> two_sum(TreeNode* root,int target){
    bst_iterator lft(root, false);
    bst_iterator rght(root, true);

    int left = lft._next();
    int right = rght._next();

    while(left<right){
        if(left+right == target){
            return make_pair(left, right);
        }
        else if(left+right > target){
            right = rght._next();
        }
        else if(left+right < target){
            left = lft._next();
        }
    }
    return make_pair(-1, -1);
}

int main(){
    vector<int> arr = {8,5,2,1,7,6,9,10,15,13,20};
    binary_search_tree bst;
    bst.insert_node(arr);
    int target = 16;
    pair<int, int> ans = two_sum(bst.root, target);
    cout << ans.first << " " << ans.second;
}