#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class TreeNode
{
public:
    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;

    TreeNode(int val)
    {
        this->val = val;
    }
};

int size(TreeNode *root)
{
    return root == nullptr ? 0 : size(root->left) + size(root->right) + 1;
}

int height(TreeNode *root)
{
    return root == nullptr ? -1 : max(height(root->left), height(root->right)) + 1;
}

int maximum(TreeNode *root)
{
    TreeNode *curr = root;
    while (curr->right != nullptr)
        curr = curr->right;

    return curr->val;
}

int minimum(TreeNode *root)
{
    TreeNode *curr = root;
    while (curr->left != nullptr)
        curr = curr->left;

    return curr->val;
}

bool findData(TreeNode *root, int data)
{
    TreeNode *curr = root;
    while (curr != nullptr)
    {
        if (curr->val == data)
            return true;
        else if (curr->val < data)
            curr = curr->right;
        else
            curr = curr->left;
    }
}
