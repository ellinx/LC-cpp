#include "../Solutions.hpp"
#include "../Tester.hpp"

using namespace std;

/***************** Wildcard Matching *****************/
/*
 Implement wildcard pattern matching with support for '?' and '*'.
 
 '?' Matches any single character.
 '*' Matches any sequence of characters (including the empty sequence).
 
 The matching should cover the entire input string (not partial).
 
 The function prototype should be:
 bool isMatch(const char *s, const char *p)
 
 Some examples:
 isMatch("aa","a") → false
 isMatch("aa","aa") → true
 isMatch("aaa","aa") → false
 isMatch("aa", "*") → true
 isMatch("aa", "a*") → true
 isMatch("ab", "?*") → true
 isMatch("aab", "c*a*b") → false
*/

bool Solutions::isMatchWildcard(string s, string p) {
    int m = s.size();
    int n = p.size();
    
    vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
    dp[0][0] = true;
    
    for (int i=1;i<=n;i++) {
        if (p[i-1]=='*') {
            dp[0][i] = dp[0][i-1];
        }
    }
    
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            if (s[i-1]==p[j-1] || p[j-1]=='?') {
                dp[i][j] = dp[i-1][j-1];
                continue;
            }
            if (p[j-1]=='*') {
                dp[i][j] = dp[i][j-1]; //* is empty
                dp[i][j] = dp[i-1][j-1] || dp[i][j]; //* is one char
                for (int k=2;k<=i;k++) {
                    dp[i][j] = dp[i-k][j-1] || dp[i][j]; //* is multiple chars
                }
            }
        }
    }
    for (auto vec : dp) {
        Tester::print(vec);
    }
    return dp[m][n];
}

#if 0
bool Solutions::isMatchWildcard(string s, string p) {
    int index1=0;
    int index2=0;
    int star = -1;
    int sstar = -1;
    while (index1<s.size()) {
        if (s[index1] == p[index2] || p[index2]=='?') {
            index1++;
            index2++;
            continue;
        }
        
        if (p[index2]=='*') {
            star = index2++;
            sstar = index1;
            continue;
        }
        
        if (star>=0) {
            index2 = star+1;
            index1 = ++sstar;
            continue;
        }
        //cout<<"index1="<<index1<<",index2="<<index2<<endl;
        return false;
    }
    while (index2<p.size()) index2++;
    //cout<<"index2="<<index2<<endl;
    return (index2==p.size());
}
#endif
