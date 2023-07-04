// Given an array of size n, generate and print all possible combinations of r elements in array. 
// For example, if input array is {1, 2, 3, 4} and r is 2, then output should be {1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4} and {3, 4}.

#include<bits/stdc++.h>
using namespace std;

void findCombinations(vector<int>& nums, vector<int>& curr, int count, int i, int r, vector<vector<int>>& ans) {
    if(count == r) {
        ans.push_back(curr);
        return;
    }
    if(i == nums.size()) return;

    // Pick the current element
    curr.push_back(nums[i]);
    findCombinations(nums, curr, count + 1, i + 1, r, ans);

    // This step is done to exclude the duplicate elements in the input array (the array is been sorted)
    while (nums[i] == nums[i + 1]) i++;
    
    // Don't pick the current element
    // Backtrack
    curr.pop_back();
    findCombinations(nums, curr, count, i + 1, r, ans);
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    vector<int> curr = {};
    int r = 3;
    vector<vector<int>> ans;

    // Sorting is done to deal with duplicate elements
    sort(nums.begin(), nums.end());

    findCombinations(nums, curr, 0, 0, r, ans);

    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}

// Time Complexity  : O(n ^ r) + O(nlogn)
// Space Complexity : O(r) [Temporary array to hold the answer] + O(n) [Call stack space]