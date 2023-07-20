// Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

// Example 1:
// Input: root = [3,1,4,null,2], k = 1
// Output: 1

// Example 2:
// Input: root = [5,3,6,2,4,null,null,1], k = 3
// Output: 3

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
    int count = 0;
    int res = -1;
    void dfs(TreeNode* root,int k){
        if(!root) return;
        
        dfs(root->left, k);
        count++;
        if(count == k) {
            res = root->val;
            return;
        }
        dfs(root->right, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        dfs(root,k);
        
        return res;
    }
};

// Time Complexity  : O(n) 
// Space Complexity : O(h)
// where h is the height of the tree