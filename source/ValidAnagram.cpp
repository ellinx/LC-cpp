
/**************** Valid Anagram **********************/
/*
 Given two strings s and t, write a function to determine if t is an anagram of s.

 For example,
 s = "anagram", t = "nagaram", return true.
 s = "rat", t = "car", return false.
*/

#include "../Solutions.hpp"


bool Solutions::isAnagram(string s, string t) {
    if (s.size() != t.size()) {
        return false;
    }
    int size = (int)s.size();
    if (size == 0) {
        return true;
    }
    
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    for (int i=0;i<size;i++) {
        if (s[i] != t[i]) {
            return false;
        }
    }
    return true;
}
