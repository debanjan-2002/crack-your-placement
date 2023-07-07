// You are given the heads of two sorted linked lists list1 and list2.

// Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

// Return the head of the merged linked list.

// Example 1:
// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]

// Example 2:
// Input: list1 = [], list2 = []
// Output: []

// Example 3:
// Input: list1 = [], list2 = [0]
// Output: [0]

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Important Question

class Solution {
private:
    // Approach 1 - Dummy Node concept
    ListNode* mergeTwoListsIterative(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* end = dummy;

        ListNode* runner1 = list1;
        ListNode* runner2 = list2;

        while(runner1 && runner2) {
            if(runner1->val <= runner2->val) {
                end->next = runner1;
                end = end->next;
                runner1 = runner1->next;
            }
            else {
                end->next = runner2;
                end = end->next;
                runner2 = runner2->next;
            }
        }
        if(runner1) end->next = runner1;
        if(runner2) end->next = runner2;
        
        return dummy->next;
    }
    // Approach 2 - Recursive implementation
    ListNode* mergeTwoListsRecursive(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;

        if(list1->val <= list2->val) {
            list1->next = mergeTwoListsRecursive(list1->next, list2);
            return list1;
        }
        else {
            list2->next = mergeTwoListsRecursive(list1, list2->next);
            return list2;
        }
    }
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // return mergeTwoListsIterative(list1, list2);
        return mergeTwoListsRecursive(list1, list2);
    }
};

// Time Complexity  : O(min(n, m))
// Space Complexity : O(1) [For recursive implementation - O(min(n, m))]