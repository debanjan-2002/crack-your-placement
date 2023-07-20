// Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

// Example 1:
// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[20,9],[15,7]]

// Example 2:
// Input: root = [1]
// Output: [[1]]

// Example 3:
// Input: root = []
// Output: []

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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        stack<int> st;
        bool flag = false;
        
        q.push(root);

        while(!q.empty()) {
            int count = q.size();
            vector<int> currLevel;
            for(int i = 0; i < count; i++) {
                auto curr = q.front();
                q.pop();

                if(flag) st.push(curr->val);
                else currLevel.push_back(curr->val);

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            if(flag) {
                while(!st.empty()) {
                    currLevel.push_back(st.top());
                    st.pop();
                }
            }
            ans.push_back(currLevel);
            flag = !flag;
        }
        return ans;
    }
};

// Time Complexity  : O(n) 
// Space Complexity : O(w)
// where w is the width of the tree