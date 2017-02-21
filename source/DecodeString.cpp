#include "../Solutions.hpp"

using namespace std;

/***************** Decode String *****************/
/*
 Given an encoded string, return it's decoded string.
 
 The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
 
 You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.
 
 Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].
 
 Examples:
 
 s = "3[a]2[bc]", return "aaabcbc".
 s = "3[a2[c]]", return "accaccacc".
 s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
*/

string Solutions::decodeString(string s) {
    string res;
    int repeat = 0;
    int start = 0;
    int end = 0;
    
    if (s.empty()) return res;
    
    while (end<s.size()) {
        if (s[end]>'0' && s[end]<='9') {
            if (isdigit(s[start])) end++;
            else if (s[start]=='[') end++;
            else {
                res += s.substr(start,end-start);
                start = ++end;
            }
        } else if (s[end]==']'){
            while (repeat>0) {
                res += decodeString(s.substr(start+1,end-start-1));
                repeat--;
            }
            start = ++end;
        } else if (s[end]=='[') {
            repeat = stoi(s.substr(start,end-start));
            start = end++;
        } else {
            end++;
        }
    }
    if (start<end) {
        res += s.substr(start,end-start);
    }
    return res;
}
