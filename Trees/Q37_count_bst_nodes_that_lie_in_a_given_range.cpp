// Given a Binary Search Tree (BST) and a range l-h(inclusive), count the number of nodes in the BST that lie in the given range.

// The values smaller than root go to the left side
// The values greater and equal to the root go to the right side

// Example 1:
// Input:
//       10
//      /  \
//     5    50
//    /    /  \
//   1    40  100
// l = 5, h = 45
// Output: 3
// Explanation: 5 10 40 are the node in the
// range

// Example 2:
// Input:
//      5
//     /  \
//    4    6
//   /      \
//  3        7
// l = 2, h = 8
// Output: 5
// Explanation: All the nodes are in the
// given range.

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
    int countNodesInRange(TreeNode* root, int l, int h) {
        if(!root) return 0;
        
        int ans = 0;
        
        if(root->val < l) ans += countNodesInRange(root->right, l, h);
        else if(root->val > h) ans += countNodesInRange(root->left, l, h);
        else {
            ans++;
            ans += countNodesInRange(root->right, l, h);
            ans += countNodesInRange(root->left, l, h);
        }
        return ans;
    }
public:
    int getCount(TreeNode *root, int l, int h) {
      return countNodesInRange(root, l, h);
    }
};

// Time Complexity  : O(n) 
// Space Complexity : O(h)
// where h is the height of the tree
