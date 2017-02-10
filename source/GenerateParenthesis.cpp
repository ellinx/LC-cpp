#include "Solution.hpp"
using namespace std;

/************** Generate Parentheses ****************/
/*
 Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 For example, given n = 3, a solution set is:

 "((()))", "(()())", "(())()", "()(())", "()()()"
*/
vector<string> Solution::generateParenthesis(int n) {
    return generateParenthesisHelper(n,n);
}

vector<string> Solution::generateParenthesisHelper(int left, int right){
    vector<string> res;
    if (left > 0) {
        vector<string> pre_result = generateParenthesisHelper(left-1, right);
        for (int i=0; i<pre_result.size();i++) {
            res.push_back("("+pre_result[i]);
        }
        if (left < right) {
            pre_result = generateParenthesisHelper(left, right-1);
            for (int i=0;i<pre_result.size();i++) {
                res.push_back(")"+pre_result[i]);
            }
        }
        return res;
    } else if (right > 0) {
        vector<string> pre_result = generateParenthesisHelper(left, right-1);
        for (int i=0;i<pre_result.size();i++) {
            res.push_back(")"+pre_result[i]);
        }
        return res;
    } else {
        res.push_back("");
        return res;
    }
}
