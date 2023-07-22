// Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place. The left and right pointers in nodes are to be used as previous and next pointers respectively in converted DLL. The order of nodes in DLL must be same as Inorder of the given Binary Tree. The first node of Inorder traversal (leftmost node in BT) must be the head node of the DLL.

// Note: H is the height of the tree and this space is used implicitly for the recursion stack.
 
// TreeToList

// Example 1:
// Input:
//       1
//     /  \
//    3    2
// Output:
// 3 1 2 
// 2 1 3 
// Explanation: DLL would be 3<=>1<=>2
// Example 2:
// Input:
//        10
//       /   \
//      20   30
//    /   \
//   40   60
// Output:
// 40 20 60 10 30 
// 30 10 60 20 40
// Explanation:  DLL would be 
// 40<=>20<=>60<=>10<=>30.

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

class Solution {
private:
    TreeNode* prev = NULL;
    TreeNode* head = NULL;
    
    void convertBinaryTreeToDLL(TreeNode* root) {
        if(!root) return;
        
        convertBinaryTreeToDLL(root->left);
        
        if(prev) {
            root->left = prev;
            prev->right = root;
        }
        else head = root;
        
        prev = root;
        
        convertBinaryTreeToDLL(root->right);
    }
public: 
    TreeNode * bToDLL(TreeNode *root) {
        convertBinaryTreeToDLL(root);
        return head;
    }
};

// Time Complexity  : O(n) 
// Space Complexity : O(h)
// where h is the height of the tree