
#include "../Solutions.hpp"

/*************** Longest Substring with At Least K Repeating Characters **************/
/*
 Find the length of the longest substring T of a given string (consists of lowercase letters only) such that every character in T appears no less than k times.
 
 Example 1:
 
 Input:
 s = "aaabb", k = 3
 
 Output:
 3
 
 The longest substring is "aaa", as 'a' is repeated 3 times.
 Example 2:
 
 Input:
 s = "ababbc", k = 2
 
 Output:
 5
 
 The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
 */

int Solutions::longestSubstring(string s, int k) {
    if (k<=1) return s.size();
    
    int maxLength = 0;
    for (int i=0;i<s.size();i++) {
        if (maxLength>=s.size()-i) break;
        vector<int> vec(26,0);
        for (int j=i;j<s.size();j++) {
            int index = s[j]-'a';
            vec[index]++;
            bool valid = true;
            for (int n=0;n<26;n++) {
                if (vec[n]>0 && vec[n]<k) {
                    valid = false;
                    break;
                }
            }
            if (valid)
                maxLength = max(maxLength, j-i+1);
        }
    }
    return maxLength;
}
