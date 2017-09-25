
/***************** Palindrome Partitioning  *****************/
/*
 Given a string s, partition s such that every substring of the partition is a palindrome.
 
 Return all possible palindrome partitioning of s.
 
 For example, given s = "aab",
 Return
 
 [
 ["aa","b"],
 ["a","a","b"]
 ]
 */

#include "../Solutions.hpp"

bool isPalindrome(string s);

vector<vector<string>> Solutions::partition(string s) {
    vector<vector<string>> res;
    for (int i=1;i<s.size();i++) {
        string left = s.substr(0,i);
        string right = s.substr(i);
        if (isPalindrome(left)) {
            vector<vector<string>> tmp = partition(right);
            if (!tmp.empty()) {
                for (int k=0;k<tmp.size();k++) {
                    tmp[k].insert(tmp[k].begin(), left);
                }
                res.insert(res.end(),tmp.begin(),tmp.end());
            }
        }
    }
    if (isPalindrome(s)) {
        res.push_back(vector<string>(1,s));
    }
    return res;
}

bool isPalindrome(string s) {
    int left = 0;
    int right = s.size()-1;
    
    while (left<right) {
        if (s[left++]!=s[right--]) return false;
    }
    return true;
}
