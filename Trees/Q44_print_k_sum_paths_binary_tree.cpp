// Given a binary tree and an integer K. Find the number of paths in the tree which have their sum equal to K.
// A path may start from any node and end at any node in the downward direction.

// Example 1:
// Input:      
// Tree = 
//           1                               
//         /   \                          
//        2     3
// K = 3
// Output: 2
// Explanation:
// Path 1 : 1 + 2 = 3
// Path 2 : only leaf node 3

// Example 2:
// Input: 
// Tree = 
//            1
//         /     \
//       3        -1
//     /   \     /   \
//    2     1   4     5                        
//         /   / \     \                    
//        1   1   2     6    
// K = 5                    
// Output: 8
// Explanation:
// The following paths sum to K.  
// 3 2 
// 3 1 1 
// 1 3 1 
// 4 1 
// 1 -1 4 1 
// -1 4 2 
// 5 
// 1 -1 5 

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
    int ans = 0;
    void findKPathSum(TreeNode* root, int k, int currSum, unordered_map<int,int>& mp) {
        if(!root) return;
        currSum += root->val;
        
        if(mp.count(currSum - k)) ans += mp[currSum - k];
        
        mp[currSum]++;
        
        findKPathSum(root->left, k, currSum, mp);
        findKPathSum(root->right, k, currSum, mp);
        
        mp[currSum]--;
    }
  public:
    int sumK(TreeNode *root,int k)
    {
        unordered_map<int,int> mp;
        mp[0] = 1;
        
        findKPathSum(root, k, 0, mp);
        return ans;
    }
};

// Time Complexity  : O(n) 
// Space Complexity : O(h + n) = O(n)
// where h is the height of the tree