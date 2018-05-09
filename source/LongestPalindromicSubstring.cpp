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

int extend(string s, int left, int right);

string Solutions::longestPalindrome(string s) {
	if (s.empty()) return "";
	if (s.size()==1) return s;
	string res;
	for (int i=0;i<s.size();i++) {
		//odd length 
		int length = extend(s,i,i);
		if (length > res.size()) {
			int tmp = (length-1)>>1;
			res = s.substr(i-tmp,length);
		}
		//even length
		if (i<s.size()-1 && s[i]==s[i+1]) {
			length = extend(s,i,i+1);
			if (length > res.size()) {
				int tmp = length>>1;
				res = s.substr(i-tmp+1,length);
			}
		}
	}
	return res;
}

int extend(string s, int left, int right) { 
	while (s[left]==s[right]) {
		left--;
		right++;
		if (left<0 || right>=s.size()) break;
	}
	return ((right-1)-(left+1)+1);
}

#if 0
string Solutions::longestPalindrome(string s) {
    if (s.empty()) return "";
    
	//dp[i][j] is 1 if substring s.substr(i,j-i+1) is palindromic
	//otherwise is 0
    vector<int> row(s.size(),0);
    vector<vector<int>> dp(s.size(),row);
    string res(1,s[0]);
    
	//check if s.substr(i,diff+1) is palindromic
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
#endif