#include "../Solutions.hpp"

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

bool Solutions::isMatch(string s, string p) {
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
