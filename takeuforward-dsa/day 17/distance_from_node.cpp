#include<bits/stdc++.h>
#include"../day 16/binary_tree.cpp"

using namespace std;

void store_parentNode(TreeNode* root, unordered_map<TreeNode*, TreeNode*>&NodeMap){
    queue<TreeNode*> Queue;
    if(!root)return;
    Queue.push(root);
    while(!Queue.empty()){
        TreeNode* curNode = Queue.front();
        Queue.pop();
        if(curNode->left){
            NodeMap[curNode->left] = curNode;
            Queue.push(curNode->left);
        }
        if(curNode->right){
            NodeMap[curNode->right] = curNode;
            Queue.push(curNode->right);
        }
    }
    return;
}

TreeNode* findTarget(TreeNode* root, int target){
    queue<TreeNode*> Q;
    if(!root)return root;
    Q.push(root);
    while(!Q.empty()){
        TreeNode* curNode = Q.front();
        Q.pop();
        if(curNode->val==target){
            return curNode;
        }
        if(curNode->left){
            Q.push(curNode->left);
        }
        if(curNode->right){
            Q.push(curNode->right);
        }
    }
    return nullptr;
}

int find_distance_k(TreeNode* root, int target, int distance){
    // store the parents of the tree
    unordered_map<TreeNode*, TreeNode*> parent_storage;
    store_parentNode(root, parent_storage);

    // find the target if the value is only given
    TreeNode* targetNode = findTarget(root, target);

    // real program begins here
    if(!targetNode)return 0;
    queue<TreeNode*> distanceCheck;
    distanceCheck.push(targetNode);

    unordered_map<TreeNode* , bool> visitedNodes;
    visitedNodes[targetNode]=true;

    while(!distanceCheck.empty()){
        int size = distanceCheck.size();
        if(distance==0)break;
        distance--;
        for(int i=0;i<size;i++){
            TreeNode* curNode = distanceCheck.front();
            distanceCheck.pop();

            if(curNode->left && !visitedNodes[curNode->left]){
                distanceCheck.push(curNode->left);
                visitedNodes[curNode->left] = true;
            }

            if(curNode->right && !visitedNodes[curNode->right]){
                distanceCheck.push(curNode->right);
                visitedNodes[curNode->right] = true;
            }

            if(parent_storage[curNode] && !visitedNodes[parent_storage[curNode]]){
                distanceCheck.push(parent_storage[curNode]);
                visitedNodes[parent_storage[curNode]] = true;
            }
        }
    }

    while(!distanceCheck.empty()){
        cout << distanceCheck.front()->val << ",";
        distanceCheck.pop();
    }

    return 0;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
    TreeNode* node = buildTree(arr, arr.size());
    find_distance_k(node, 3, 2);
    return 0;
}