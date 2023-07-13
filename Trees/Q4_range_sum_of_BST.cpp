// Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].

// Example 1:
// Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
// Output: 32
// Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.

// Example 2:
// Input: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
// Output: 23
// Explanation: Nodes 6, 7, and 10 are in the range [6, 10]. 6 + 7 + 10 = 23.

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
    int rangeSum(TreeNode* root,int low,int high){
        if(root == NULL)
            return 0;
        int ans = 0;
        if(root->val <= high && root->val >= low)
            ans += root->val;
        if(root->val >= high)
            ans += rangeSum(root->left,low,high);
        else if(root->val <= low)
            ans += rangeSum(root->right,low,high);
        else
            ans += (rangeSum(root->left,low,high) + rangeSum(root->right,low,high));
        return ans;
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        return rangeSum(root,low,high);
    }
};

// Time Complexity  : O(n) 
// Space Complexity : O(n)