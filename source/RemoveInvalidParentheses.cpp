#include "../Solutions.hpp"

using namespace std;

/***************** Remove Invalid Parentheses *****************/
/*
 Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.
 
 Note: The input string may contain letters other than the parentheses ( and ).
 
 Examples:
 "()())()" -> ["()()()", "(())()"]
 "(a)())()" -> ["(a)()()", "(a())()"]
 ")(" -> [""]
*/

bool isValid(string s);

vector<string> Solutions::removeInvalidParentheses(string s) {
    queue<string> toVisit;
    unordered_set<string> visited;
    vector<string> res;
    toVisit.push(s);
    visited.insert(s);
    
    while(!toVisit.empty()) {
        string item = toVisit.front();
        toVisit.pop();
        if (!res.empty()) {
            if (res[0].size()>item.size()) return res;
        }
        if (isValid(item)) {
            res.push_back(item);
        } else {
            for (int i=0;i<item.size();i++) {
                if (item[i]=='(' || item[i]==')') {
                    string tmp = item.substr(0,i)+item.substr(i+1,-1);
                    if (visited.find(tmp)==visited.end()) {
                        toVisit.push(tmp);
                        visited.insert(tmp);
                    }
                }
            }
        }
    }
    return res;
}

bool isValid(string s) {
    int left = 0;
    for (int i=0;i<s.size();i++) {
        if (s[i] == '(') {
            left++;
        } else if (s[i] == ')') {
            if (left>0) left--;
            else return false;
        }
    }
    if (left==0) return true;
    else return false;
}
