#include "../Solutions.hpp"

using namespace std;

/***************** Valid Parenthesis *****************/

/*
 Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 
 The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

bool Solutions::isValid(string s) {
    if (s.empty()) return true;
    stack<char> sk;
    for (int i=0;i<s.size();i++) {
        if (s[i]=='(' || s[i]=='[' || s[i]=='{') {
            sk.push(s[i]);
        } else if (s[i]==')') {
            if (!sk.empty() && sk.top()=='(') sk.pop();
            else return false;
        } else if (s[i]==']') {
            if (!sk.empty() && sk.top()=='[') sk.pop();
            else return false;
        } else {
            if (!sk.empty() && sk.top()=='{') sk.pop();
            else return false;
        }
    }
    if (sk.empty()) return true;
    else return false;
}
