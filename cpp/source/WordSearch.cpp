#include "../Solutions.hpp"

using namespace std;

/***************** Word Search *****************/
/*
 Given a 2D board and a word, find if the word exists in the grid.
 
 The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
 
 For example,
 Given board =
 
 [
 ['A','B','C','E'],
 ['S','F','C','S'],
 ['A','D','E','E']
 ]
 word = "ABCCED", -> returns true,
 word = "SEE", -> returns true,
 word = "ABCB", -> returns false.
*/
bool DFSHelper(vector<vector<char>>& board, vector<vector<int>> trace, int row, int col, string target);

bool Solutions::exist(vector<vector<char>>& board, string word) {
    int row = board.size();
    if (row==0) return false;
    
    int col = board[0].size();
    vector<int> tmp(col, 0);
    vector<vector<int>> trace(row, tmp);
    
    bool res = false;
    for (int i=0;i<row;i++) {
        for (int j=0;j<col;j++) {
            if (board[i][j]==word.front()) {
                if (word.size()==1 || word.empty()) return true;
                else {
                    trace[i][j] = 1;
                    res |= DFSHelper(board, trace, i, j, word.substr(1,-1));
                    trace[i][j] = 0;
                }
            }
            if (res) return true;
        }
    }
    return res;
    
}

bool DFSHelper(vector<vector<char>>& board, vector<vector<int>> trace, int row, int col, string target) {
    bool res = false;
    //up
    if (row>0) {
        if (trace[row-1][col]==0 && board[row-1][col]==target.front()) {
            if (target.size()==1) return true;
            else {
                trace[row-1][col] = 1;
                res |= DFSHelper(board, trace, row-1, col, target.substr(1,-1));
                trace[row-1][col] = 0;
            }
        }
    }
    if (res) return true;
    
    //down
    if (row<board.size()-1) {
        if (trace[row+1][col]==0 && board[row+1][col]==target.front()) {
            if (target.size()==1) return true;
            else {
                trace[row+1][col] = 1;
                res |= DFSHelper(board, trace, row+1, col, target.substr(1,-1));
                trace[row+1][col] = 0;
            }
        }
    }
    if (res) return true;
    
    //left
    if (col>0) {
        if (trace[row][col-1]==0 && board[row][col-1]==target.front()) {
            if (target.size()==1) return true;
            else {
                trace[row][col-1] = 1;
                res |= DFSHelper(board, trace, row, col-1, target.substr(1,-1));
                trace[row][col-1] = 0;
            }
        }
    }
    if (res) return true;
    
    //right
    if (col<board[0].size()-1) {
        if (trace[row][col+1]==0 && board[row][col+1]==target.front()) {
            if (target.size()==1) return true;
            else {
                trace[row][col+1] = 1;
                res |= DFSHelper(board, trace, row, col+1, target.substr(1,-1));
                trace[row][col+1] = 0;
            }
        }
    }
    return res;
}
