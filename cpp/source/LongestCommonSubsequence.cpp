#include "../Solutions.hpp"

using namespace std;

/***************** Longest Common Subsequence *****************/
/*
 A subsequence is a sequence that can be derived from another sequence by deleting some elements without changing the order of the remaining elements. Longest common subsequence (LCS) of 2 sequences is a subsequence, with maximal length, which is common to both the sequences.
 
 Given two sequence of integers,  and , find any one longest common subsequence.
 
 In case multiple solutions exist, return any of them. It is guaranteed that at least one non-empty common subsequence will exist.
 
 Example:
 A = [1 2 3 4 1]
 B = [3 4 1 2 1 3]
 
 There is no common subsequence with length larger than 3. And "1 2 3", "1 2 1", "3 4 1" are all correct answers.
 */

vector<int> Solutions::LCS(vector<int> a, vector<int> b) {
    int m = a.size();
    int n = b.size();
    vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1,vector<int>()));
    //if a[i]==b[j] then dp[i][j] = dp[i-1][j-1]+a[i];
    //if a[i]!=b[j] then dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    
    for (int i=1;i<m+1;i++) {
        for (int j=1;j<n+1;j++) {
            if (a[i-1]==b[j-1]) {
                dp[i][j] = dp[i-1][j-1];
                dp[i][j].push_back(a[i-1]);
            } else {
                if (dp[i-1][j].size()>dp[i][j-1].size()) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
    }
    return dp[m][n];
}
