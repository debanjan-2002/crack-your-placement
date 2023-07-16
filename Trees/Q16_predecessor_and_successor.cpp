// There is BST given with the root node with the key part as an integer only. You need to find the in-order successor and predecessor of a given key. If either predecessor or successor is not found, then set it to NULL.

// Note:- In an inorder traversal the number just smaller than the target is the predecessor and the number just greater than the target is the successor. 

// Example 1:
// Input:
//         10
//       /   \
//      2    11
//    /  \ 
//   1    5
//       /  \
//      3    6
//       \
//        4
// key = 8
// Output: 
// 6 10
// Explanation: 
// In the given BST the inorder predecessor of 8 is 6 and inorder successor of 8 is 10.

// Example 2:
// Input:
//       8
//     /   \
//    1     9
//     \     \
//      4    10
//     /
//    3
// key = 11
// Output: 
// 10 -1
// Explanation: 
// In given BST, the inorder predecessor of 11 is 10 whereas it does not have any inorder successor.

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
    void findPreSuc(TreeNode* root, TreeNode*& pre, TreeNode*& suc, int key) {
        TreeNode* temp1 = root;
        TreeNode* temp2 = root;
        
        while(temp1) {
            if(temp1->val <= key) temp1 = temp1->right;
            else {
                suc = temp1;
                temp1 = temp1->left;
            }
        }
        while(temp2) {
            if(temp2->val >= key) temp2 = temp2->left;
            else {
                pre = temp2;
                temp2 = temp2->right;
            }
        }
    }
};

// Time Complexity  : O(h) 
// Space Complexity : O(1)
// where h is the height of the tree