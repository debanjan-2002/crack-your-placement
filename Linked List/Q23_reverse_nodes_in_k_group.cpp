// Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

// You may not alter the values in the list's nodes, only nodes themselves may be changed.

// Example 1:
// Input: head = [1,2,3,4,5], k = 2
// Output: [2,1,4,3,5]

// Example 2:
// Input: head = [1,2,3,4,5], k = 3
// Output: [3,2,1,4,5]

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Recursive Implementation
// Important question

class Solution {
private:
    ListNode* reverse(ListNode* head, int k) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        while(curr && k) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            k--;
        }
        return prev;
    }
    ListNode* reverseInGroup(ListNode* head, int k) {
        if(!head || !head->next) return head;

        int count = k;
        ListNode* runner = head;

        while(runner && count) {
            runner = runner->next;
            count--;
        }
        if(count == 0) {
            ListNode* restHead = reverseInGroup(runner, k);
            ListNode* newHead = reverse(head, k);
            head->next = restHead;
            return newHead;
        }
        else return head;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        return reverseInGroup(head, k);
    }
};

// Time Complexity  : O(n)
// Space Complexity : O(n/k)