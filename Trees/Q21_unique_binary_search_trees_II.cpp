// Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.

// Example 1:
// Input: n = 3
// Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]

// Example 2:
// Input: n = 1
// Output: [[1]]

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

// Very Important question
// Dynamic Programming + Catalan Number

class Solution {
private:
    vector<TreeNode*> generateBSTs(int start, int end, map<pair<int, int>, vector<TreeNode*>>& dp) {
        if(start > end) return vector<TreeNode*>{NULL};
        if(dp.count({start, end})) return dp[{start, end}];

        vector<TreeNode*> ans;

        // Considering all the numbers from 1 to n as the root of the overall tree
        for(int r = start; r <= end; r++) {
            // This returns an array consisting of the roots of the left half
            vector<TreeNode*> leftSubTree = generateBSTs(start, r - 1, dp);
            // This returns an array consisting of the roots of the right half 
            vector<TreeNode*> rightSubTree = generateBSTs(r + 1, end, dp);

            // Now we have to join all the left and right subtrees root combination
            // With the overall root node (which is 'r' in this case)

            // Going through all the combination of the left and right half
            for(int i = 0; i < leftSubTree.size(); i++) {
                for(int j = 0; j < rightSubTree.size(); j++) {
                    // Make the overall root node of the tree
                    // r is the value of the current root which we are working with
                    TreeNode * root = new TreeNode(r);

                    TreeNode* currentLeftRoot = leftSubTree[i];
                    TreeNode* currentRightRoot = rightSubTree[j];

                    root->left = currentLeftRoot;
                    root->right = currentRightRoot;

                    ans.push_back(root);
                }
            }
        }
        return dp[{start, end}] = ans;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        map<pair<int, int>, vector<TreeNode*>> dp;
        return generateBSTs(1, n, dp);
    }
};

// Time Complexity  : O(4 ^ n / sqrt(n)) [Not expected to find this in interview] 
// Space Complexity : O(sum(k = 1 to n)[(n - k + 1) * 4 ^ k / sqrt(k)])