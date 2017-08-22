#include "../Solutions.hpp"
#include "../main.h"

using namespace std;

/***************** Longest Increasing Path in a Matrix *****************/
/*
 Given an integer matrix, find the length of the longest increasing path.
 
 From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).
 
 Example 1:
 
 nums = [
 [9,9,4],
 [6,6,8],
 [2,1,1]
 ]
 Return 4
 The longest increasing path is [1, 2, 6, 9].
 
 Example 2:
 
 nums = [
 [3,4,5],
 [3,2,6],
 [2,2,1]
 ]
 Return 4
 The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
 */

int DFS(int col, int row, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
    int res = 1;
    
    if (dp[row][col]!=0) return dp[row][col];
    //up
    if (row>0 && matrix[row-1][col]>matrix[row][col]) {
        res = max(res, DFS(col,row-1,matrix,dp)+1);
    }
    //down
    if (row<matrix.size()-1 && matrix[row+1][col]>matrix[row][col]) {
        res = max(res, DFS(col,row+1,matrix,dp)+1);
    }
    //left
    if (col>0 && matrix[row][col-1]>matrix[row][col]) {
        res = max(res, DFS(col-1,row,matrix,dp)+1);
    }
    //right
    if (col<matrix[0].size()-1 && matrix[row][col+1]>matrix[row][col]) {
        res = max(res, DFS(col+1,row,matrix,dp)+1);
    }
    dp[row][col] = res;
    return res;
}

int Solutions::longestIncreasingPath(vector<vector<int>>& matrix) {
    int m = matrix.size();
    if (m==0) return 0;
    int n = matrix[0].size();
    vector<vector<int>> dp(m,vector<int>(n,0));
    int res = 0;
    
    for (int i=0;i<matrix.size();i++) {
        for (int j=0;j<matrix[0].size();j++) {
            res = max(res,DFS(j,i,matrix,dp));
        }
    }
    cout<<"finish"<<endl;
    printMatrix(dp);
    return res;
}
