#include "../Solutions.hpp"

using namespace std;

/***************** Longest palindromic Substring *****************/
/*
 Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 
 Example:
 
 Input: "babad"
 
 Output: "bab"
 
 Note: "aba" is also a valid answer.
 Example:
 
 Input: "cbbd"
 
 Output: "bb"
*/

string Solutions::longestPalindrome(string s) {
    if (s.empty()) return "";
    
    vector<int> row(s.size(),0);
    vector<vector<int>> dp(s.size(),row);
    string res(1,s[0]);
    
    for (int diff=0;diff<s.size();diff++) {
        for (int i=0;i<s.size()-diff;i++) {
            if (diff==0) {
                dp[i][i+diff] = 1;
            } else if (diff==1) {
                if (s[i]==s[i+diff]) {
                    dp[i][i+diff] = 1;
                    res = s.substr(i,diff+1);
                }
            } else {
                if (dp[i+1][i+diff-1]==1) {
                    if (s[i]==s[i+diff]) {
                        dp[i][i+diff]=1;
                        if (res.size()<diff+1) {
                            res = s.substr(i,diff+1);
                        }
                    }
                }
            }
        }
    }
    return res;
}
