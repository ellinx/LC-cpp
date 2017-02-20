#include "../Solutions.hpp"

using namespace std;

/***************** Count And Say *****************/
/*
 The count-and-say sequence is the sequence of integers beginning as follows:
 1, 11, 21, 1211, 111221, ...
 
 1 is read off as "one 1" or 11.
 11 is read off as "two 1s" or 21.
 21 is read off as "one 2, then one 1" or 1211.
 Given an integer n, generate the nth sequence.
 
 Note: The sequence of integers will be represented as a string.
*/

string helper(string s);

string Solutions::countAndSay(int n) {
    string cur = "1";
    for (int i=0;i<n-1;i++) {
        cur = helper(cur);
    }
    return cur;
}

string helper(string s) {
    string res;
    char digit = s[0];
    int count = 1;
    for (int i=1;i<s.size();i++) {
        if (digit == s[i]) {
            count++;
        } else {
            res += to_string(count)+digit;
            digit = s[i];
            count = 1;
        }
    }
    res += to_string(count)+digit;
    return res;
}
