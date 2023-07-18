// Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

// The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).

// Example 1:
// Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
// Output: 3
// Explanation: The paths that sum to 8 are shown.

// Example 2:
// Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
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

// Very important question
// Hashing
// Similar to subarray sum question

class Solution {
private:
    int countPaths(TreeNode* root, unordered_map<long, long>& mp, long sum, int targetSum) {
        if(!root) return 0;

        sum += root->val;

        int ans = 0;
        if(mp.count(sum - targetSum)) ans += mp[sum - targetSum];

        mp[sum]++;

        ans += countPaths(root->left, mp, sum, targetSum);
        ans += countPaths(root->right, mp, sum, targetSum);
        
        mp[sum]--;

        return ans;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long, long> mp;
        // For path starting from the root
        mp[0] = 1;
        return countPaths(root, mp, 0, targetSum);
    }
};

// Time Complexity  : O(n) 
// Space Complexity : O(h + n) = O(n)
// where h is the width of the tree