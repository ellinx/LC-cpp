#include "../Solutions.hpp"

using namespace std;

/***************** Decode Ways *****************/

/*
 A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26

Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2. 
*/
int helper(string s);

int Solutions::numDecodings(string s) {
	if (s.empty()) return 0;
	if (s.size()==1) {
		if (s!="0") return 1;
		else return 0;
	}
	return helper(s);
}

int helper(string s) {
	if (s.empty()) return 0;

	if (s.size()==1) {
		if (s!="0") return 1;
		else return -1;
	}

	string last1 = s.substr(s.size()-1,2);
	string last2 = s.substr(s.size()-2,2);
	s.pop_back();
	int pre1 = helper(s);
	s.pop_back();
	int pre2 = helper(s);
	if (pre1==0) {
		if (last1=="0") {
			pre1 = -1;
		} else {
			pre1 = 1;
		}
	} else if (pre1>0) {
		if (last1=="0") {
			pre1 = -1;
		}
	}

	int tmp = stoi(last2);
	if (pre2==0) {
		if (tmp==0 || tmp>26) {
			pre2 = -1;
		} else {
			pre2 = 1;
		}
	} else if (pre2>0) {
		if (tmp==0 || tmp>26) {
			pre1 = -1;
		}
	}

	int res=0;
	res += (pre1>0)?pre1:0;
	res += (pre2>0)?pre2:0;
	return res;
}