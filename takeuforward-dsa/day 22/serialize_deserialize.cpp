#include<bits/stdc++.h>
#include"../day 17/binary_tree.cpp"
using namespace std;

class Solution{
    public:
        string serialization(TreeNode* root){
            if(!root)return "";

            string s="";
            queue<TreeNode*> levelQueue;
            levelQueue.push(root);

            while(!levelQueue.empty()){
                TreeNode* curNode = levelQueue.front();
                levelQueue.pop();
                if(curNode){
                    s+=to_string(curNode->val)+",";
                    levelQueue.push(curNode->left);
                    levelQueue.push(curNode->right);
                }
                else
                {
                    s+="#,";
                }
            }
            return s;
        }

    TreeNode* deserialize(string str)
    {
        if(str=="")return nullptr;
        stringstream s(str);
        string cur;
        getline(s, cur, ',');

        TreeNode* root = new TreeNode(stoi(cur));
        queue<TreeNode*> levelQueue;
        levelQueue.push(root);
        while(!levelQueue.empty())
        {
            TreeNode* curNode = levelQueue.front();
            levelQueue.pop();

            // left side
            getline(s, cur, ',');
            if(cur=="#"){
                curNode->left = nullptr;
            }
            else{
                TreeNode* lnode = new TreeNode(stoi(cur));
                curNode->left = lnode;
                levelQueue.push(lnode);
            }
            // right side
            getline(s, cur, ',');
            if(cur=="#"){
                curNode->right = nullptr;
            }
            else{
                TreeNode* rnode = new TreeNode(stoi(cur));
                curNode->right = rnode;
                levelQueue.push(rnode);
            }
        }
        return root;
    }

};

void preorder_traversal(TreeNode* root){
    if(!root)return;
    cout << root->val << " ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

int main(){
    vector<int> arr = {1,2,3,4};
    TreeNode* root = buildTree(arr, arr.size());
    Solution s1;
    string txt = s1.serialization(root);
    TreeNode* ans = s1.deserialize(txt);
    preorder_traversal(ans);
    return 0;
}