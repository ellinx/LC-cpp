#include "../Solutions.hpp"
#include "../main.h"

using namespace std;

/***************** Longest Uncommon Subsequence I *****************/
/*
 Given a group of two strings, you need to find the longest uncommon subsequence of this group of two strings. The longest uncommon subsequence is defined as the longest subsequence of one of these strings and this subsequence should not be any subsequence of the other strings.
 
 A subsequence is a sequence that can be derived from one sequence by deleting some characters without changing the order of the remaining elements. Trivially, any string is a subsequence of itself and an empty string is a subsequence of any string.
 
 The input will be two strings, and the output needs to be the length of the longest uncommon subsequence. If the longest uncommon subsequence doesn't exist, return -1.
 
 Example 1:
 Input: "aba", "cdc"
 Output: 3
 Explanation: The longest uncommon subsequence is "aba" (or "cdc"),
 because "aba" is a subsequence of "aba",
 but not a subsequence of any other strings in the group of two strings.
 Note:
 
 Both strings' lengths will not exceed 100.
 Only letters from a ~ z will appear in input strings.
 */

//dp practice
int Solutions::findLUSlength(string a, string b) {
    int m = a.size();
    int n = b.size();
    //if (a==b) return -1;
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    
    //if a[i]==b[j] then dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
    //if a[i]!=b[j] then dp[i][j] = dp[i-1][j-1]+1;
    
    iota(dp[0].begin(), dp[0].end(), 0);
    
    for (int i=1;i<m+1;i++) {
        dp[i][0] = i;
    }
    dp[0][0] = -1;
    for (int i=1;i<m+1;i++) {
        for (int j=1;j<n+1;j++) {
            if (a[i-1]==b[j-1]) {
                if (dp[i-1][j-1] == -1) {
                    dp[i][j] = -1;
                } else {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            } else {
                if (dp[i-1][j-1] == -1) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i-1][j-1]+1;
                }
            }
        }
    }
    for (auto vec : dp) {
        printVector(vec);
    }
    return dp[m][n];
}

//
int findLUSlength(string a, string b) {
    return (a==b)?-1:max(a.size(), b.size());
}
