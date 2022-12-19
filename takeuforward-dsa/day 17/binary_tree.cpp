#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int v)
    {
        val = v;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode *buildTree(vector<int> &arr, int n, int i = 0)
{
    TreeNode *root = nullptr;
    // Base case for recursion
    if (i < n)
    {
        root = new TreeNode(arr[i]);
        // insert left child
        root->left = buildTree(arr, n, 2 * i + 1);
        // insert right child
        root->right = buildTree(arr, n, 2 * i + 2);
    }
    return root;
}