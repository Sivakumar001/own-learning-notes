#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int v)
    {
        val = v;
        left = nullptr;
        right = nullptr;
    }
};

Node* buildTree(int arr[], int n, int i=0)
{
    Node *root = nullptr;
    // Base case for recursion
    if (i < n)
    {
        root = new Node(arr[i]);
        // insert left child
        root->left = buildTree(arr, n, 2 * i + 1);
        // insert right child
        root->right = buildTree(arr, n, 2 * i + 2);
    }
    return root;
}