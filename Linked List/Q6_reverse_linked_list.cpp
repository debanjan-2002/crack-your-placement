// Given the head of a singly linked list, reverse the list, and return the reversed list.

// Example 1:
// Input: head = [1,2,3,4,5]
// Output: [5,4,3,2,1]

// Example 2:
// Input: head = [1,2]
// Output: [2,1]

// Example 3:
// Input: head = []
// Output: []

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    // Approach 1 - Iterative implementation 
    ListNode* reverseIterative(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    // Approach 2 - Recursive implementation
    ListNode* reverseRecursive(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* restHead = reverseRecursive(head->next);
        head->next->next = head;
        head->next = NULL;
        
        return restHead;
    }
public:
    ListNode* reverseList(ListNode* head) {
        // return reverseIterative(head);
        return reverseRecursive(head);
    }
};

// Time Complexity  : O(n)
// Space Complexity : O(1) [O(n) stack space for recursive implementation]