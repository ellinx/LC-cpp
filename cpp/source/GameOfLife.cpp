#include "../Solutions.hpp"

using namespace std;

/***************** Game of Life  *****************/
/*
 According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."
 
 Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):
 
 1. Any live cell with fewer than two live neighbors dies, as if caused by under-population.
 2. Any live cell with two or three live neighbors lives on to the next generation.
 3. Any live cell with more than three live neighbors dies, as if by over-population..
 4. Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
 Write a function to compute the next state (after one update) of the board given its current state.
 
 Follow up:
 Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
 In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?
 */

void Solutions::gameOfLife(vector<vector<int>>& board) {
    int row = board.size();
    int col = board[0].size();
    vector<vector<int>> newBoard(row, vector<int>(col, -1));
    
    for (int i=0;i<row;i++) {
        for (int j=0;j<col;j++) {
            int lives = 0;
            int dies = 0;
            
            if (i>0) {
                //up
                if (board[i-1][j]==0) {
                    dies++;
                } else {
                    lives++;
                }
                //up-left
                if (j>0) {
                    if (board[i-1][j-1]==0) {
                        dies++;
                    } else {
                        lives++;
                    }
                }
                //up-right
                if (j<col-1) {
                    if (board[i-1][j+1]==0) {
                        dies++;
                    } else {
                        lives++;
                    }
                }
            }
            //left
            if (j>0) {
                if (board[i][j-1]==0) {
                    dies++;
                } else {
                    lives++;
                }
            }
            //right
            if (j<col-1) {
                if (board[i][j+1]==0) {
                    dies++;
                } else {
                    lives++;
                }
            }
            if (i<row-1) {
                //bottom
                if (board[i+1][j]==0) {
                    dies++;
                } else {
                    lives++;
                }
                //left-bottom
                if (j>0) {
                    if (board[i+1][j-1]==0) {
                        dies++;
                    } else {
                        lives++;
                    }
                }
                //right-bottom
                if (j<col-1) {
                    if (board[i+1][j+1]==0) {
                        dies++;
                    } else {
                        lives++;
                    }
                }
            }
            
            int nextState = board[i][j];
            if (board[i][j]==0) {
                //dead cell
                if (lives==3) {
                    nextState = 1;
                }
            } else {
                //live cell
                if (lives<2 || lives>3) {
                    nextState = 0;
                }
            }
            newBoard[i][j] = nextState;
        }
    }
    
    board = newBoard;
}
