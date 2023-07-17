// Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

// You can return the answer in any order.

// Example 1:
// Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
// Output: [7,4,1]
// Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.

// Example 2:
// Input: root = [1], target = 1, k = 3
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
private:
    void buildParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int count = q.size();
            for(int i = 0; i < count; i++) {
                auto curr = q.front();
                q.pop();

                if(curr->left) {
                    q.push(curr->left);
                    parent[curr->left] = curr;
                }
                if(curr->right) {
                    q.push(curr->right);
                    parent[curr->right] = curr;
                }
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        buildParent(root, parent);

        q.push(target);
        visited[target] = 1;
        int level = 0;

        while(!q.empty()) {
            int count = q.size();
            if(level++ == k) break;
            for(int i = 0; i < count; i++) {
                auto curr = q.front();
                q.pop();

                if(curr->left && !visited[curr->left]) {
                    q.push(curr->left);
                    visited[curr->left] = 1;
                }
                if(curr->right && !visited[curr->right]) {
                    q.push(curr->right);
                    visited[curr->right] = 1;
                }
                if(parent[curr] && !visited[parent[curr]]) {
                    q.push(parent[curr]);
                    visited[parent[curr]] = 1;
                }
            }
        }
        vector<int> ans;
        while(!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};

// Time Complexity  : O(n) 
// Space Complexity : O(h)
// where h is the height of the tree