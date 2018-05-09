#include "../Solutions.hpp"

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
bool DFSHelper(vector<vector<char>>& board, int row, int col, string target);

bool Solutions::exist(vector<vector<char>>& board, string word) {
    int row = board.size();
    if (row==0) return false;
    
    int col = board[0].size();
    
    bool res = false;
    for (int i=0;i<row;i++) {
        for (int j=0;j<col;j++) {
            if (board[i][j]==word.front()) {
                if (word.size()==1 || word.empty()) return true;
                else {
                    char tmp = board[i][j];
                    board[i][j] = '0';
                    res |= DFSHelper(board, i, j, word.substr(1,-1));
                    board[i][j] = tmp;
                }
            }
            if (res) return true;
        }
    }
    return res;
    
}

bool DFSHelper(vector<vector<char>>& board, int row, int col, string target) {
    bool res = false;
    //up
    if (row>0) {
        if (board[row-1][col]==target.front()) {
            if (target.size()==1) return true;
            else {
                char tmp = board[row-1][col];
                board[row-1][col] = '0';
                res |= DFSHelper(board, row-1, col, target.substr(1,-1));
                board[row-1][col] = tmp;
            }
        }
    }
    if (res) return true;
    
    //down
    if (row<board.size()-1) {
        if (board[row+1][col]==target.front()) {
            if (target.size()==1) return true;
            else {
                char tmp = board[row+1][col];
                board[row+1][col] = '0';
                res |= DFSHelper(board, row+1, col, target.substr(1,-1));
                board[row+1][col] = tmp;
            }
        }
    }
    if (res) return true;
    
    //left
    if (col>0) {
        if (board[row][col-1]==target.front()) {
            if (target.size()==1) return true;
            else {
                char tmp = board[row][col-1];
                board[row][col-1] = '0';
                res |= DFSHelper(board, row, col-1, target.substr(1,-1));
                board[row][col-1] = tmp;
            }
        }
    }
    if (res) return true;
    
    //right
    if (col<board[0].size()-1) {
        if (board[row][col+1]==target.front()) {
            if (target.size()==1) return true;
            else {
                char tmp = board[row][col+1];
                board[row][col+1] = '0';
                res |= DFSHelper(board, row, col+1, target.substr(1,-1));
                board[row][col+1] = tmp;
            }
        }
    }
    return res;
}



/***************** Word Search II *****************/
/*
 Given a 2D board and a list of words from the dictionary, find all words in the board.
 
 Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.
 
 For example,
 Given words = ["oath","pea","eat","rain"] and board =
 
 [
 ['o','a','a','n'],
 ['e','t','a','e'],
 ['i','h','k','r'],
 ['i','f','l','v']
 ]
 Return ["eat","oath"].
 */


bool helper(vector<vector<char>>& board, string target, int x, int y);
//extern void printMatrix(vector<vector<char>>& matrix);

vector<string> Solutions::findWords(vector<vector<char>>& board, vector<string>& words) {
    vector<string> res;
    unordered_map<char, vector<pair<int, int>>> map;
    unordered_set<string> wordSet;
    
    if (board.empty()) return res;
    
    //store all character starting point in a map
    
    for (int i=0;i<board.size();i++) {
        for (int j=0;j<board[0].size();j++) {
            auto iter = map.find(board[i][j]);
            if (iter==map.end()) {
                //not in map, create "start" list
                vector<pair<int, int>> tmp;
                pair<int, int> start(i, j);
                tmp.push_back(start);
                map[board[i][j]] = tmp;
            } else {
                //already in map, add to "start" list
                pair<int, int> start(i, j);
                map[board[i][j]].push_back(start);
            }
        }
    }
    
    for (string word : words) {
        wordSet.insert(word);
    }
    
    for (string word : wordSet) {
        //cout<<word<<endl;
        auto iter = map.find(word.front());
        if (iter==map.end()) continue;
        //cout<<"start point "<<iter->second.size()<<endl;
        for (pair<int,int> start : iter->second) {
            if (word.size()==1) {
                res.push_back(word);
                break;
            } else {
                char tmp = board[start.first][start.second];
                board[start.first][start.second] = '0';
                if (helper(board, word.substr(1,-1), start.first, start.second)) {
                    res.push_back(word);
                    board[start.first][start.second] = tmp;
                    break;
                }
                board[start.first][start.second] = tmp;
            }
        }
    }
    return res;
}

bool helper(vector<vector<char>>& board, string target, int x, int y) {
    bool res = false;
    //cout<<"start point x="<<x<<", y="<<y<<endl;
    //printMatrix(board);
    //up
    if (x>0) {
        if (board[x-1][y]==target.front()) {
            if (target.size()==1) {
                return true;
            } else {
                char tmp = board[x-1][y];
                board[x-1][y] = '0';
                res |= helper(board,target.substr(1,-1), x-1, y);
                board[x-1][y] = tmp;
            }
        }
    }
    if (res) return true;
    
    //down
    if (x<board.size()-1) {
        if (board[x+1][y]==target.front()) {
            if (target.size()==1) {
                return true;
            } else {
                char tmp = board[x+1][y];
                board[x+1][y] = '0';
                res |= helper(board,target.substr(1,-1), x+1, y);
                board[x+1][y] = tmp;
            }
        }
    }
    if (res) return true;
    
    //left
    if (y>0) {
        if (board[x][y-1]==target.front()) {
            if (target.size()==1) {
                return true;
            } else {
                char tmp = board[x][y-1];
                board[x][y-1] = '0';
                res |= helper(board,target.substr(1,-1), x, y-1);
                board[x][y-1] = tmp;
            }
        }
    }
    if (res) return true;
    
    //right
    if (y<board[0].size()-1) {
        if (board[x][y+1]==target.front()) {
            if (target.size()==1) {
                return true;
            } else {
                char tmp = board[x][y+1];
                board[x][y+1] = '0';
                res |= helper(board,target.substr(1,-1), x, y+1);
                board[x][y+1] = tmp;
            }
        }
    }
    return res;
}
