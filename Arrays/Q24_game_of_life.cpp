// According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

// The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

// Any live cell with fewer than two live neighbors dies as if caused by under-population.
// Any live cell with two or three live neighbors lives on to the next generation.
// Any live cell with more than three live neighbors dies, as if by over-population.
// Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
// The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously. Given the current state of the m x n grid board, return the next state.

// Example 1:
// Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
// Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]

// Example 2:
// Input: board = [[1,1],[1,0]]
// Output: [[1,1],[1,1]]

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int countLiveNeighbors(vector<vector<int>>& board, int row, int col, int n, int m) {
        int count = 0;
        
        count += (row - 1 >= 0 && board[row - 1][col]) ? 1 : 0;
        count += (col - 1 >= 0 && board[row][col - 1]) ? 1 : 0;
        count += (row + 1 < n && board[row + 1][col]) ? 1 : 0;
        count += (col + 1 < m && board[row][col + 1]) ? 1 : 0;
        count += (row - 1 >= 0 && col - 1 >= 0 && board[row - 1][col - 1]) ? 1 : 0;
        count += (row - 1 >= 0 && col + 1 < m && board[row - 1][col + 1]) ? 1 : 0;
        count += (row + 1 < n && col - 1 >= 0 && board[row + 1][col - 1]) ? 1 : 0;
        count += (row + 1 < n && col + 1 < m && board[row + 1][col + 1]) ? 1 : 0;

        return count;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> tempBoard = board; 

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int liveNeighbors = countLiveNeighbors(tempBoard, i, j, n, m);
                // Current cell is live
                if(board[i][j] == 1) {
                    if(liveNeighbors < 2 || liveNeighbors > 3) board[i][j] = 0;
                }
                // Current cell is dead and live neighbors = 3
                else if(liveNeighbors == 3) board[i][j] = 1;
            }
        }
    }
};

// Time Complexity  : O(n * m)
// Space Complexity : O(n * m)