// Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.

// Example 1:
// Input: root = [4,2,6,1,3]
// Output: 1

// Example 2:
// Input: root = [1,0,48,null,null,12,49]
// Output: 1

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
    int ans = 1e9;
    TreeNode* prev = NULL;
    void dfs(TreeNode* root) {
        if(!root) return;

        dfs(root->left);
        if(prev) ans = min(ans, root->val - prev->val);

        prev = root;
        dfs(root->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        return ans;
    }
};

// Time Complexity  : O(n) 
// Space Complexity : O(h)
// where h is the height of the tree