// Given a Binary Search Tree that contains positive integer values greater than 0. The task is to complete the function isDeadEnd which returns true if the BST contains a dead end else returns false. Here Dead End means, we are not able to insert any element after that node.

// Example 1:
// Input :   
//                8
//              /   \ 
//            5      9
//          /  \     
//         2    7 
//        /
//       1     
          
// Output : 
// Yes
// Explanation : 
// Node "1" is the dead End because after that we cant insert any element.

// Example 2:
// Input :     
//               8
//             /   \ 
//            7     10
//          /      /   \
//         2      9     13

// Output : 
// Yes
// Explanation : 
// We can't insert any element at node 9.   

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
    void addAllNodes(TreeNode* root, unordered_map<int,bool>& mp) {
        if(!root) return;
        
        mp[root->val] = 1;
        
        addAllNodes(root->left, mp);
        addAllNodes(root->right, mp);
    }

    bool dfs(TreeNode* root, unordered_map<int,bool>& mp) {
        if(!root) return false;
        if(!root->left && !root->right) {
            int next = root->val + 1;
            int prev = root->val - 1;
            
            if(mp.count(next) && mp.count(prev)) return true;
        }    
        return dfs(root->left, mp) || dfs(root->right, mp);
    }

    bool isDeadEnd(TreeNode *root) {
        unordered_map<int,bool> mp;
        addAllNodes(root, mp);
        mp[0] = 1;
        
        return dfs(root, mp);
    }
};

// Time Complexity  : O(n) 
// Space Complexity : O(n)