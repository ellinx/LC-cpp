#include "../Solutions.hpp"
using namespace std;

/**************** Valid Anagram **********************/
/*
 Given two strings s and t, write a function to determine if t is an anagram of s.

 For example,
 s = "anagram", t = "nagaram", return true.
 s = "rat", t = "car", return false.
*/

bool Solutions::isAnagram(string s, string t) {
    if (s.size() != t.size()) {
        return false;
    }
    int size = (int)s.size();
    if (size == 0) {
        return true;
    }
    char* s_cstr = new char[size];
    char* t_cstr = new char[size];
    strcpy(s_cstr, s.c_str());
    strcpy(t_cstr, t.c_str());
    sort(s_cstr, s_cstr+size);
    sort(t_cstr, t_cstr+size);

    for (int i=0;i<size;i++) {
        if (s_cstr[i] != t_cstr[i]) {
            return false;
        }
    }
    delete[] s_cstr;
    delete[] t_cstr;
    return true;
}
