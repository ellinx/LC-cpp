#include "../Solutions.hpp"

using namespace std;

/***************** Longest Substring Without Repeating Characters *****************/
/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/

int Solutions::lengthOfLongestSubstring(string s) {
	if (s.size()==0) return 0;

	unordered_set<char> set;
	int res = 1;
	int start = 0;
	int end = 1;
	set.insert(s[0]);

	while (end<s.size()) {
		if (set.find(s[end]) != set.end()) {
			set.erase(s[start]);
			start++;
		} else {
			set.insert(s[end]);
			if (res < end-start+1) {
				res = end-start+1;
			}
			end++;
		}
	}
	return res;
}