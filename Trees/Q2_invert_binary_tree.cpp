// Given the root of a binary tree, invert the tree, and return its root.

// Example 1:
// Input: root = [4,2,7,1,3,6,9]
// Output: [4,7,2,9,6,3,1]

// Example 2:
// Input: root = [2,1,3]
// Output: [2,3,1]

// Example 3:
// Input: root = []
// Output: []

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    TreeNode* invert(TreeNode* root) {
        if(!root) return NULL;

        TreeNode* left = invert(root->left);
        TreeNode* right = invert(root->right);

        root->left = right;
        root->right = left;

        return root;
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        return invert(root);
    }
};

// Time Complexity  : O(number of nodes)
// Space Complexity : O(height of tree)