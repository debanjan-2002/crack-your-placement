// Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

// Example 1:
// Input: head = [1,2,3,4,5], left = 2, right = 4
// Output: [1,4,3,2,5]

// Example 2:
// Input: head = [5], left = 1, right = 1
// Output: [5]

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
    ListNode* reverse(ListNode* head, int len) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* tempHead = head;
        ListNode* next;

        while(curr && len) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            len--;
        }
        tempHead->next = next;
        return prev;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next) return head;

        ListNode* dummy = new ListNode(-1, head);
        ListNode* runner = dummy;

        for(int i = 0; i < left - 1; i++) {
            runner = runner->next;
        }
        ListNode* tempHead = reverse(runner->next, right - left + 1);
        runner->next = tempHead;
        return dummy->next;
    }
};

// Time Complexity  : O(n)
// Space Complexity : O(1)