// Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a binary tree of distinct values and postorder is the postorder traversal of the same tree, reconstruct and return the binary tree.

// If there exist multiple answers, you can return any of them.

// Example 1:
// Input: preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
// Output: [1,2,3,4,5,6,7]

// Example 2:
// Input: preorder = [1], postorder = [1]
// Output: [1]

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
    unordered_map<int,int> m;
public:
    TreeNode* dfs(vector<int>& pre, vector<int>& post, int preStart, int preEnd, int postStart, int postEnd){
        if(preStart > preEnd)
            return NULL;
        TreeNode* root = new TreeNode(pre[preStart]);
        if(preStart == preEnd)
            return root;
        
        int idx = m[pre[preStart + 1]];
        int offset = idx - postStart;
        root->left = dfs(pre, post, preStart + 1, preStart + 1 + offset, postStart, idx);
        root->right = dfs(pre, post, preStart + 1 + offset + 1, preEnd, idx+1, postEnd);
        return root;
    }
    
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n = pre.size();
        for(int i = 0;i < n;i++)
            m[post[i]] = i;
        return dfs(pre, post, 0, n - 1, 0, n - 1);
    }
};

// Time Complexity  : O(n) 
// Space Complexity : O(n)