// You are given the head of a singly linked-list. The list can be represented as:

// L0 → L1 → … → Ln - 1 → Ln
// Reorder the list to be on the following form:

// L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
// You may not modify the values in the list's nodes. Only nodes themselves may be changed.

// Example 1:
// Input: head = [1,2,3,4]
// Output: [1,4,2,3]

// Example 2:
// Input: head = [1,2,3,4,5]
// Output: [1,5,2,4,3]

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Dummy Node + Reversal application
// Important question

class Solution {
private:
    ListNode* reverse(ListNode* head) {
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
public:
    void reorderList(ListNode* head) {
        if(!head->next || !head->next->next) return;

        ListNode* slow = head;
        ListNode* fast = head->next;

        // Find the middle of the linked list
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* runner1 = head;
        // Reverse the second half of the list
        ListNode* runner2 = reverse(slow->next);
        slow->next = NULL;

        ListNode* dummy = new ListNode();
        ListNode* runner = dummy;

        // Join the the list using alternate nodes from each list part
        while(runner1 && runner2) {
            runner->next = runner1;
            runner = runner->next;
            runner1 = runner1->next;

            runner->next = runner2;
            runner = runner->next;
            runner2 = runner2->next;
        }
        // For odd length list
        if(runner2) runner->next = runner2;
    }
};

// Time Complexity  : O(n)
// Space Complexity : O(1)