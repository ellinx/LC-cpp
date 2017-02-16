#include "../Solutions.hpp"

using namespace std;
//#define RECURSIVE

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

#ifndef RECURSIVE
int Solutions::numDecodings(string s){
    vector<int> dp(s.size(),0);
    if (s.empty()) return 0;
    if (s.size()==1) {
        if (s!="0") return 1;
        else return 0;
    }
    if (s[0]!='0') {
        dp[0] = 1;
    } else {
        dp[0] = 0;
    }
    int tmp = stoi(s.substr(0,2));
    if (tmp<10 || tmp>26) {
        dp[1] = 0;
    } else {
        dp[1] = 1;
    }
    dp[1] += (s[1]!='0')?dp[0]:0;
    for (int i=2;i<s.size();i++) {
        int part1=0;
        int part2=0;
        if (s[i]!='0') {
            part1 = dp[i-1];
        }
        tmp = stoi(s.substr(i-1,2));
        if (tmp>9 && tmp<27) {
            part2 = dp[i-2];
        }
        dp[i] = part1 + part2;
    }
    return dp.back();
}

#else
int Solutions::numDecodings(string s) {
	if (s.empty()) return 0;
	if (s.size() == 1) {
		if (s != "0") return 1;
		else return 0;
	}
	
    int DeOne = 0;
    int DeTwo = 0;
    //decode one char
    if (s[0]!='0') {
        DeOne = (s.size()>1)?numDecodings(s.substr(1,-1)):1;
    } else {
        DeOne = 0;
    }
    
    //decode two char
    int tmp = stoi(s.substr(0,2));
    if (tmp<10 || tmp>26) {
        DeTwo = 0;
    } else {
        DeTwo = (s.size()>2)?numDecodings(s.substr(2,-1)):1;
    }
    return DeOne+DeTwo;
}
#endif

