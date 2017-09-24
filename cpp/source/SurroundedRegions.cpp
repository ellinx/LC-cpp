
/***************** Surrounded Regions  *****************/
/*
 Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
 
 A region is captured by flipping all 'O's into 'X's in that surrounded region.
 
 For example,
 X X X X
 X O O X
 X X O X
 X O X X
 
 After running your function, the board should be:
 
 X X X X
 X X X X
 X X X X
 X O X X
 */
#include "../Solutions.hpp"

void DFSMark(vector<vector<char>>& board, int row, int col);//for large input will cause runtime error(stack overflow)
void BFSMark(vector<vector<char>>& board, int row, int col);

void Solutions::solve(vector<vector<char>>& board) {
    int m = board.size();
    if (m==0) return;
    
    int n = board[0].size();
    
    //top and bottom edges
    for (int i=0;i<n;i++) {
        if (board[0][i]=='O') {
//            DFSMark(board, 0, i);
            BFSMark(board, 0, i);
        }
        if (m>1) {
            if (board[m-1][i]=='O') {
//                DFSMark(board, m-1, i);
                BFSMark(board, m-1, i);
            }
        }
    }
    
    //left and right edges
    for (int i=1;i<m-1;i++) {
        if (board[i][0]=='O') {
//            DFSMark(board, i, 0);
            BFSMark(board, i, 0);
        }
        if (n>1) {
            if (board[i][n-1]=='O') {
//                DFSMark(board, i, n-1);
                BFSMark(board, i, n-1);
            }
        }
    }
    
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            if (board[i][j]=='O') {
                board[i][j] = 'X';
            }
            if (board[i][j]=='1') {
                board[i][j] = 'O';
            }
        }
    }

}

void BFSMark(vector<vector<char>>& board, int row, int col) {
    int m = board.size();
    int n = board[0].size();
    queue<pair<int,int>> toVisit;
    
    if (board[row][col]=='O') {
        toVisit.push(pair<int,int>(row,col));
    }
    
    while (!toVisit.empty()) {
        pair<int, int> tmp = toVisit.front();
        toVisit.pop();
        if (board[tmp.first][tmp.second]!='O') continue;
        board[tmp.first][tmp.second] = '1';
        //add all its neighbors
        if (tmp.first>0 && board[tmp.first-1][tmp.second]=='O') {
            toVisit.push(pair<int, int>(tmp.first-1,tmp.second));
        }
        if (tmp.first<m-1 && board[tmp.first+1][tmp.second]=='O') {
            toVisit.push(pair<int, int>(tmp.first+1,tmp.second));
        }
        if (tmp.second>0 && board[tmp.first][tmp.second-1]=='O') {
            toVisit.push(pair<int, int>(tmp.first,tmp.second-1));
        }
        if (tmp.second<n-1 && board[tmp.first][tmp.second+1]=='O') {
            toVisit.push(pair<int,int>(tmp.first,tmp.second+1));
        }
    }
}


void DFSMark(vector<vector<char>>& board, int row, int col) {
    int m = board.size();
    int n = board[0].size();
    
    if (board[row][col]=='O') {
        board[row][col] = '1';
    }
    
    //up
    if (row>0 && board[row-1][col]=='O') {
        DFSMark(board, row-1, col);
    }
    
    //down
    if (row<m-1 && board[row+1][col]=='O') {
        DFSMark(board, row+1, col);
    }
    
    //left
    if (col>0 && board[row][col-1]=='O') {
        DFSMark(board, row, col-1);
    }
    
    //right
    if (col<n-1 && board[row][col+1]=='O') {
        DFSMark(board, row, col+1);
    }
}
