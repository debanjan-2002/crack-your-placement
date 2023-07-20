// Given an array arr[] of N nodes representing preorder traversal of some BST. You have to build the exact PostOrder from it's given preorder traversal. 
// In Pre-Order traversal, the root node is visited before the left child and right child nodes.

// Example 1:
// Input:
// N = 5
// arr[]  = {40,30,35,80,100}
// Output: 35 30 100 80 40
// Explanation: PreOrder: 40 30 35 80 100
// Therefore, the BST will be:
//               40
//            /      \
//          30       80
//            \        \   
//            35      100
// Hence, the postOrder traversal will
// be: 35 30 100 80 40

// Example 2:
// Input:
// N = 8
// arr[]  = {40,30,32,35,80,90,100,120}
// Output: 35 32 30 120 100 90 80 40

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

class Solution{
private:
    TreeNode* buildTree(vector<int>& pre, int &preIndex, unordered_map<int, int>& inIndexMap, int start, int end) {
        if(start > end) return NULL;
        
        TreeNode* root = new TreeNode(pre[preIndex++]);
        
        int inIndex = inIndexMap[root->val];
        
        root->left = buildTree(pre, preIndex, inIndexMap, start, inIndex - 1);
        root->right = buildTree(pre, preIndex, inIndexMap, inIndex + 1, end);
        
        return root;
    }
public:
    //Function that constructs BST from its preorder traversal.
    TreeNode* post_order(vector<int>& pre) {
        int n = pre.size();

        vector<int> inorder;
        unordered_map<int, int> inIndexMap;
        int preIndex = 0;
        
        for(int i = 0; i < n; i++) {
            inorder.push_back(pre[i]);
        }
        sort(inorder.begin(), inorder.end());
        
        for(int i = 0; i < n; i++) {
            inIndexMap[inorder[i]] = i;
        }
        return buildTree(pre, preIndex, inIndexMap, 0, n - 1);
    }
};

// Time Complexity  : O(n) 
// Space Complexity : O(n)