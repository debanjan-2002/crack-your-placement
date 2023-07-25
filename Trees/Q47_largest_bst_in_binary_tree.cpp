// Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.
// Note: Here Size is equal to the number of nodes in the subtree.

// Example 1:
// Input:
//         1
//       /   \
//      4     4
//    /   \
//   6     8
// Output: 1
// Explanation: There's no sub-tree with size
// greater than 1 which forms a BST. All the
// leaf Nodes are the BSTs with size equal
// to 1.

// Example 2:

// Input: 6 6 3 N 2 9 3 N 8 8 2
//             6
//         /       \
//        6         3
//         \      /   \
//          2    9     3
//           \  /  \
//           8 8    2 
// Output: 2
// Explanation: The following sub-tree is a
// BST of size 2: 
//        2
//     /    \ 
//    N      8

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

class NodeValue{
public:
    int maxSize;
    int maxValue;
    int minValue;
    NodeValue(int maxSize, int minValue, int maxValue) {
        this->maxSize = maxSize;
        this->minValue = minValue;
        this->maxValue = maxValue;
    }
};

class Solution{
private:
    NodeValue findLargestBST(TreeNode* root) {
        if(!root) return NodeValue(0, INT_MAX, INT_MIN);
        
        auto left = findLargestBST(root->left);
        auto right = findLargestBST(root->right);
        
        if(left.maxValue < root->val && right.minValue > root->val) {
            int size = left.maxSize + right.maxSize + 1;
            return NodeValue(size, min(root->val, left.minValue), max(root->val, right.maxValue));
        }
        return NodeValue(max(left.maxSize, right.maxSize), INT_MIN, INT_MAX);
    }
public:
    int largestBst(TreeNode *root) {
    	return findLargestBST(root).maxSize;
    }
};

// Time Complexity  : O(n) 
// Space Complexity : O(h)
// where h is the height of the tree