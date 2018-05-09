#include "../Solutions.hpp"
#include "../Tester.hpp"

/***************** Longest Palindromic Subsequence *****************/
/*
 Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.
 
 Example 1:
 Input:
 
 "bbbab"
 Output:
 4
 One possible longest palindromic subsequence is "bbbb".
 Example 2:
 Input:
 
 "cbbd"
 Output:
 2
 One possible longest palindromic subsequence is "bb".
 */

int Solutions::longestPalindromeSubseq(string s) {
    int n = s.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1,0));
    
    //if s[i]==s[j] then dp[i][j] = dp[i+1][j-1]+2;
    //if s[i]!=s[j] then dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
    
    for (int i=1;i<n+1;i++) {
        dp[i][i] = 1;
    }
    
    for (int i=n-1;i>0;i--) {
        for (int j=i+1;j<n+1;j++) {
            if (s[i-1]==s[j-1]) {
                dp[i][j] = dp[i+1][j-1] + 2;
            } else {
                dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
            }
        }
    }
//    for (auto vec : dp) {
//        Tester::print(vec);
//    }
    return dp[1][n];
}
