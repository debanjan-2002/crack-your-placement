// Given a linked list of 0s, 1s and 2s, The task is to sort and print it.

// Examples: 

// Input: 1 -> 1 -> 2 -> 0 -> 2 -> 0 -> 1 -> NULL 
// Output: 0 -> 0 -> 1 -> 1 -> 1 -> 2 -> 2 -> NULL

// Input: 1 -> 1 -> 2 -> 1 -> 0 -> NULL 
// Output: 0 -> 1 -> 1 -> 1 -> 2 -> NULL 

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
// Dummy Node concept

class Solution {
public:
    ListNode* sort0s1s2s(ListNode* head) {
        ListNode* zeroDummy = new ListNode(-1);
        ListNode* oneDummy = new ListNode(-1);
        ListNode* twoDummy = new ListNode(-1);

        ListNode* zeroEnd = zeroDummy;
        ListNode* oneEnd = oneDummy;
        ListNode* twoEnd = twoDummy;

        ListNode* runner = head;

        while(runner) {
            if(runner->val == 0) {
                zeroEnd->next = runner;
                zeroEnd = zeroEnd->next;
            }
            else if(runner->val == 1) {
                oneEnd->next = runner;
                oneEnd = oneEnd->next;
            }
            else {
                twoEnd->next = runner;
                twoEnd = twoEnd->next;
            }
            runner = runner->next;
        }
        zeroEnd->next = oneDummy->next;
        oneEnd->next = twoDummy->next;
        twoEnd->next = NULL;
        
        return zeroDummy->next;
    }
};

int main() {
    // Example
    ListNode* head = new ListNode(2);
    head->next = new ListNode(1);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next->next->next->next = new ListNode(0);

    Solution s;
    ListNode* newHead = s.sort0s1s2s(head);

    ListNode* runner = newHead;
    while(runner) {
        cout << runner->val << " ";
        runner = runner->next;
    }
}

// Time Complexity  : O(n)
// Space Complexity : O(size of 3 dummy nodes)