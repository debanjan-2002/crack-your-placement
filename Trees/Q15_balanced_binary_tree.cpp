// Given a binary tree, determine if it is height-balanced.
// A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one..

// Example 1:
// Input: root = [3,9,20,null,null,15,7]
// Output: true

// Example 2:
// Input: root = [1,2,2,3,3,null,null,4,4]
// Output: false

// Example 3:
// Input: root = []
// Output: true

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
    int checkBalanced(TreeNode* root) {
        if(!root) return 0;

        int leftHeight = checkBalanced(root->left);
        if(leftHeight == -1) return -1;

        int rightHeight = checkBalanced(root->right);
        if(rightHeight == -1) return -1;

        if(abs(leftHeight - rightHeight) > 1) return -1;

        return max(leftHeight, rightHeight) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        int ans = checkBalanced(root);
        return ans == -1 ? 0 : 1;
    }
};

// Time Complexity  : O(n) 
// Space Complexity : O(h)
// where h is the height of the tree