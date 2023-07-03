// Given an m x n grid of characters board and a string word, return true if word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

// Example 1:
// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
// Output: true

// Example 2:
// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
// Output: true

// Example 3:
// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
// Output: false

#include<bits/stdc++.h>
using namespace std;

// Depth First Search (DFS) solution
class Solution {
private:
    bool isInsideBoard(int row, int col, int n, int m) {
        return (row >= 0 && row < n && col >= 0 && col < m);
    }
    bool dfs(vector<vector<char>>& board, string &word, int row, int col, int i, int n, int m) {
        if(i == word.length()) return true;
        if(!isInsideBoard(row, col, n, m)) return false;
        if(board[row][col] == '#' || board[row][col] != word[i]) return false;
        
        char curr = board[row][col];
        board[row][col] = '#';

        bool op1 = dfs(board, word, row + 1, col, i + 1, n, m);
        bool op2 = dfs(board, word, row - 1, col, i + 1, n, m);
        bool op3 = dfs(board, word, row, col + 1, i + 1, n, m);
        bool op4 = dfs(board, word, row, col - 1, i + 1, n, m);

        board[row][col] = curr;

        return (op1 || op2 || op3 || op4);
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(dfs(board, word, i, j, 0, n, m)) {
                    return true;
                }
            }
        }
        return false;
    }
};

// Time Complexity  : O(n * m * 4 ^ k) [where k = length of word] 
// Space Complexity : O(4 ^ k)