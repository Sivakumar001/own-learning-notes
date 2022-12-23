#include<bits/stdc++.h>
#include"../day 17/binary_tree.cpp"

using namespace std;

class binary_search_tree{
    public:
        TreeNode* root;
        binary_search_tree(){
            root = nullptr;
        }

        void insert_node(int value){
            TreeNode* cur = root;
            TreeNode* node = new TreeNode(value);
            if(!root){
                root = node;
                return;
            }
            while(true){
                if(value>cur->val){
                    if(cur->right){
                        cur = cur->right;
                    }
                    else{
                        cur->right = node;
                        break;
                    }
                }
                else{
                    if(cur->left){
                        cur = cur->left;
                    }
                    else{
                        cur->left = node;
                        break;
                    }
                }
            }
        }

        void delete_node(int value){
            if(root->val==value){
                root = helper(root);
                return;
            }
            TreeNode* cur = root;
            while(cur){
                if(cur->val>value){
                    if(cur->left && cur->left->val==value){
                        cur->left = helper(cur->left);
                        break;
                    }
                    else{
                        cur =  cur->left;
                    }
                }
                if(cur->val<value){
                    if(cur->right && cur->right->val==value){
                        cur->right = helper(cur->right);
                        break;
                    }
                    else{
                        cur = cur->right;
                    }
                }
            }
        }

        TreeNode* helper(TreeNode* cur){
            if(!cur->left){
                return cur->right;
            }
            if(!cur->right){
                return cur->left;
            }
            TreeNode* leftChild = cur->left;
            TreeNode* rightChild = cur->right;
            TreeNode* lastRight = findLastRight(leftChild);
            lastRight->right = rightChild;
            return leftChild;
        }

        TreeNode* findLastRight(TreeNode* child){
            if(!child->right)return child;
            findLastRight(child->right);
        }
};

void preorder_traversal(TreeNode* root){
    if(!root)return;
    stack<TreeNode*> stk;
    stk.push(root);
    while(!stk.empty()){
        TreeNode* cur = stk.top();stk.pop();
        cout << cur->val << " ";
        if(cur->right)stk.push(cur->right);
        if(cur->left)stk.push(cur->left);

    }
}

int main(){
    binary_search_tree bst;
    bst.insert_node(2);
    bst.insert_node(3);
    bst.insert_node(1);
    bst.insert_node(7);

    bst.delete_node(3);
    preorder_traversal(bst.root);
}