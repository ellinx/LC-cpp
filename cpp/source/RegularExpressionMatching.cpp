#include "../Solutions.hpp"
#include "../main.h"

using namespace std;

/***************** Regular Expression Matching *****************/
/*
 Implement regular expression matching with support for '.' and '*'.
 
 '.' Matches any single character.
 '*' Matches zero or more of the preceding element.
 
 The matching should cover the entire input string (not partial).
 
 The function prototype should be:
 bool isMatch(const char *s, const char *p)
 
 Some examples:
 isMatch("aa","a") → false
 isMatch("aa","aa") → true
 isMatch("aaa","aa") → false
 isMatch("aa", "a*") → true
 isMatch("aa", ".*") → true
 isMatch("ab", ".*") → true
 isMatch("aab", "c*a*b") → true
 */

bool Solutions::isMatchRegE(string s, string p) {
    int m = s.size();
    int n = p.size();
    
    //dp[i][j] : if s[1~i] matches p[1~j]
    vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
    
    dp[0][0] = true;
    
    for (int i=1;i<=n;i++) {
        if (p[i-1]=='*') {
            dp[0][i] = dp[0][i-2];
        }
    }
    
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            if (s[i-1]==p[j-1] || p[j-1]=='.') {
                dp[i][j] = dp[i-1][j-1];
                continue;
            }
            if (p[j-1]=='*') {
                if (s[i-1]==p[j-2] || p[j-2]=='.') {
                    dp[i][j] =  dp[i][j-2] || dp[i-1][j-2] || dp[i-1][j];//a* stand for no a, one a and multiple a
                } else {
                    dp[i][j] = dp[i][j-2];
                }
            }
        }
    }
    for (auto vec : dp) {
        printVector(vec);
    }
    return dp[m][n];
}
