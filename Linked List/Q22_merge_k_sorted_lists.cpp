// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

// Merge all the linked-lists into one sorted linked-list and return it.

// Example 1:
// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted list:
// 1->1->2->3->4->4->5->6

// Example 2:
// Input: lists = []
// Output: []

// Example 3:
// Input: lists = [[]]
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
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0) return NULL;

        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;

        for(int i = 0; i < n; i++) {
            if(lists[i]) pq.push({ lists[i]->val, lists[i] });
        }

        ListNode* dummy = new ListNode();
        ListNode* end = dummy;

        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            end->next = curr.second;
            end = end->next;

            if(curr.second->next)
                pq.push({ curr.second->next->val, curr.second->next });
        }
        return dummy->next;
    }
};

// Time Complexity  : O(nlogk) [where k is the number of lists and n is the total number of elements across all the lists]
// Space Complexity : O(k)