
#include "../Solutions.hpp"

/***************** Evaluate Reverse Polish Notation *****************/
/*
 Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 
 Valid operators are +, -, *, /. Each operand may be an integer or another expression.
 
 Some examples:
 ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 
 */

int Solutions::evalRPN(vector<string>& tokens) {
    stack<int> stk;
    for (int i=0;i<tokens.size();i++) {
        string tmp = tokens[i];
        if (tmp=="+") {
            int num2 = stk.top();
            stk.pop();
            int num1 = stk.top();
            stk.pop();
            stk.push(num1+num2);
        } else if (tmp=="-") {
            int num2 = stk.top();
            stk.pop();
            int num1 = stk.top();
            stk.pop();
            stk.push(num1-num2);
        } else if (tmp=="*") {
            int num2 = stk.top();
            stk.pop();
            int num1 = stk.top();
            stk.pop();
            stk.push(num1*num2);
        } else if (tmp=="/") {
            int num2 = stk.top();
            stk.pop();
            int num1 = stk.top();
            stk.pop();
            stk.push(num1/num2);
        } else {
            stk.push(stoi(tmp));
        }
    }
    return stk.top();
}
