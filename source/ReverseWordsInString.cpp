#include "../Solutions.hpp"

using namespace std;

/***************** Reverse Words in a String *****************/
/*
 Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.

click to show clarification.
Clarification:

    What constitutes a word?
    A sequence of non-space characters constitutes a word.
    Could the input string contain leading or trailing spaces?
    Yes. However, your reversed string should not contain leading or trailing spaces.
    How about multiple spaces between two words?
    Reduce them to a single space in the reversed string.
*/

void Solutions::reverseWords(string &s) {
	stack<string> sk;
	int start=0;
	int end=0;
	while (end<s.size()) {
		while (start==end && s[end]==' ') {
			start++;
			end++;
		}
		if (s[end]==' ') {
			sk.push(s.substr(start,end-start));
			start = ++end;
		} else {
			if (s[start]==' ') start++;
			end++;
		}
	}
	if (start<end) {
		sk.push(s.substr(start,end-start));
	}
	s="";
	while(!sk.empty()) {
		if (!s.empty()) {
			s += " ";
		}
		s += sk.top();
		sk.pop();
	}
}