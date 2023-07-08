// Given a linked list, rearrange it such that the converted list should be of the form a < b > c < d > e < f … where a, b, c… are consecutive data nodes of the linked list.

// Examples: 

// Input:  1->2->3->4
// Output: 1->3->2->4 
// Explanation : 1 and 3 should come first before 2 and 4 in zig-zag fashion, So resultant linked-list will be 1->3->2->4. 

// Input:  11->15->20->5->10
// Output: 11->20->5->15->10 

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
public:
    ListNode* zigzag(ListNode* head) {
        // If the flag is 1, then it means the current element should be smaller than the next element and vice-versa
        bool flag = 1;
        ListNode* runner = head;

        while(runner->next) {
            if(flag && runner->val > runner->next->val) swap(runner->val, runner->next->val);
            else if(runner->val < runner->next->val) swap(runner->val, runner->next->val);
            runner = runner->next;
            flag = !flag;
        }
        return head;
    }
};

// Time Complexity  : O(n)
// Space Complexity : O(1)