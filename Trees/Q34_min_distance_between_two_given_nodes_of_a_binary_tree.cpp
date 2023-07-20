// Given a binary tree and two node values your task is to find the minimum distance between them.
// The given two nodes are guaranteed to be in the binary tree and nodes are numbered from 1 to N.
// Please Note that a and b are not always leaf node.

// Example 1:
// Input:
//         1
//       /  \
//      2    3
// a = 2, b = 3
// Output: 2
// Explanation: The tree formed is:
//        1
//      /   \ 
//     2     3
// We need the distance between 2 and 3.
// Being at node 2, we need to take two
// steps ahead in order to reach node 3.
// The path followed will be:
// 2 -> 1 -> 3. Hence, the result is 2. 

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

// LCA Application

class Solution {
private:
    TreeNode* lca(TreeNode* root, int a, int b) {
        if(!root) return NULL;
        if(root->val == a || root->val == b) return root;
        
        TreeNode* lca1 = lca(root->left, a, b);
        TreeNode* lca2 = lca(root->right, a, b);
        
        if(lca1 && lca2) return root;
        if(lca1) return lca1;
        return lca2;
    } 
    int dfs(TreeNode* root, int val, int level) {
        if(!root) return -1;
        if(root->val == val) return level;
        
        int left = dfs(root->left, val, level + 1);
        if(left != -1) return left;
        
        return dfs(root->right, val, level + 1);
    }
public:
    int findDist(TreeNode* root, int a, int b) {
        TreeNode* lcaRoot = lca(root, a, b);
        
        int dist1 = dfs(lcaRoot, a, 0);
        int dist2 = dfs(lcaRoot, b, 0);
        
        return dist1 + dist2;
    }
};

// Time Complexity  : O(n) 
// Space Complexity : O(h)
// where h is the height of the tree