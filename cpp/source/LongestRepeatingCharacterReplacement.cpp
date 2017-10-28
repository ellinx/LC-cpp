
#include "../Solutions.hpp"

/***************** Longest Repeating Character Replacement *****************/
/*
 Given a string that consists of only uppercase English letters, you can replace any letter in the string with another letter at most k times. Find the length of a longest substring containing all repeating letters you can get after performing the above operations.
 
 Note:
 Both the string's length and k will not exceed 104.
 
 Example 1:
 
 Input:
 s = "ABAB", k = 2
 
 Output:
 4
 
 Explanation:
 Replace the two 'A's with two 'B's or vice versa.
 Example 2:
 
 Input:
 s = "AABABBA", k = 1
 
 Output:
 4
 
 Explanation:
 Replace the one 'A' in the middle with 'B' and form "AABBBBA".
 The substring "BBBB" has the longest repeating letters, which is 4.
 */


//sliding window solution
int Solutions::characterReplacement(string s, int k) {
    int res = 0;
    vector<int> letters(26,0);
    int maxSameCharCount = 0;
    int start=0,end=0;
    
    for (;end<s.size();end++) {
        letters[s[end]-'A']++;
        maxSameCharCount = max(maxSameCharCount, letters[s[end]-'A']);
        while (end-start+1-maxSameCharCount > k) {
            letters[s[start]-'A']--;
            start++;
            maxSameCharCount = 0;
            for (int count:letters) {
                maxSameCharCount = max(maxSameCharCount, count);
            }
        }
        res = max(res, end-start+1);
    }
    return res;
} 
