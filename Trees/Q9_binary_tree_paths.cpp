// Given the root of a binary tree, return all root-to-leaf paths in any order.

// A leaf is a node with no children.

// Example 1:
// Input: root = [1,2,3,null,5]
// Output: ["1->2->5","1->3"]

// Example 2:
// Input: root = [1]
// Output: ["1"]

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
    void paths(TreeNode* root, string curr, vector<string>& ans) {
        if(!root) return;
        if(!root->left && !root->right) {
            curr += to_string(root->val);
            ans.push_back(curr);
            return;
        }

        curr += to_string(root->val);
        curr += "->";

        paths(root->left, curr, ans);
        paths(root->right, curr, ans);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        paths(root, "", ans);
        return ans;
    }
};

// Time Complexity  : O(n) 
// Space Complexity : O(n)