#include<bits/stdc++.h>
#include"binary_tree.cpp"

using namespace std;

vector<int> levelOrder_traversal(Node* n)
{
    vector<int> ans;
    if(n==nullptr)return ans;

    queue<Node*> q;
    q.push(n);
    while(!q.empty())
    {
        Node* tmp = q.front();
        if(tmp->left)q.push(tmp->left);
        if(tmp->right)q.push(tmp->right);
        q.pop();
        ans.push_back(tmp->val);
    }
    return ans;
}

vector<int> reverse_levelorder_traversal(Node* n)
{
    vector<int> ans;
    stack<int> st;
    queue<Node*> q;
    q.push(n);
    while(!q.empty())
    {
        Node* tmp = q.front();
        st.push(tmp->val);
        if(tmp->left)q.push(tmp->left);
        if(tmp->right)q.push(tmp->right);
        q.pop();
    }
    while(!st.empty())
    {
        ans.push_back(st.top());st.pop();
    }
    return ans;
}

int main()
{
    vector<int> arr = {1,2,3,4,5,6};
    Node* n = buildTree(arr, arr.size());
    vector<int> ans = reverse_levelorder_traversal(n);
    for(auto it: ans)
    {
        cout << it << " ";
    }
    return 0;
}