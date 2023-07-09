// Given a linked list where every node represents a linked list and contains two pointers of its type: 

// Pointer to next node in the main list (we call it ‘right’ pointer in the code below) 
// Pointer to a linked list where this node is headed (we call it the ‘down’ pointer in the code below). 
// Note: All linked lists are sorted and the resultant linked list should also be sorted

// Examples: 

// Input:    5 -> 10 -> 19 -> 28
//           |    |     |     |  
//           7    20    22    35
//           |          |     |
//           8          50    40
//           |                |
//           30               45

// Output: 5->7->8->10->19->20->22->28->30->35->40->45->50

// Input:    3 -> 10 -> 7 -> 14
//           |    |     |    |
//           9    47    15   22
//           |          |             
//           17         30

// Output: 3->7->9->10->14->15->17->22->30->47 

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode* bottom;
    ListNode() : val(0), next(nullptr), bottom(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* dummy = new ListNode();
        ListNode* end = dummy;
        ListNode* runner1 = head1;
        ListNode* runner2 = head2;

        while(runner1 && runner2) {
            if(runner1->val <= runner2->val) {
                end->bottom = runner1;
                end = end->bottom;
                runner1 = runner1->bottom;
            }
            else {
                end->bottom = runner2;
                end = end->bottom;
                runner2 = runner2->bottom;
            }
        }
        if(runner1) end->bottom = runner1;
        if(runner2) end->bottom = runner2;

        return dummy->bottom;
    }
    ListNode* flatten(ListNode* root) {
        if(!root || !root->next) return root;
    
        root->next = flatten(root->next);
        root = merge(root, root->next);
        
        return root;
    }
};

// Time Complexity  : O(Total number of nodes in the linked list)
// Space Complexity : O(Total number of nodes in the upper layer)