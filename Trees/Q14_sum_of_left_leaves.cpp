// Given the root of a binary tree, return the sum of all left leaves.

// A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.

// Example 1:
// Input: root = [3,9,20,null,null,15,7]
// Output: 24
// Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.

// Example 2:
// Input: root = [1]
// Output: 0

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
    int dfs(TreeNode* root) {
        if(!root) return 0;

        int ans = 0;
        // returns the sum of left leaves rooted at "root->left"
        ans += dfs(root->left); 
        // returns the sum of left leaves rooted at "root->right"
        ans += dfs(root->right);

        // If the left node w.r.t the current node is leaf then add that to the answer
        if(root->left && !root->left->right && !root->left->left) 
            ans += root->left->val;
        
        return ans;
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root);
    }
};

// Time Complexity  : O(n) 
// Space Complexity : O(h)
// where h is the height of the tree