#include "../Solutions.hpp"
using namespace std;

/*************** Basic Calculator II **************/
/*
 Implement a basic calculator to evaluate a simple expression string.
 
 The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.
 
 You may assume that the given expression is always valid.
 
 Some examples:
 "3+2*2" = 7
 " 3/2 " = 1
 " 3+5 / 2 " = 5
 Note: Do not use the eval built-in library function.
 */

int Solutions::calculate(string s) {
    vector<char> ops;
    vector<long> nums;
    int index = 0;
    int length = 0;
    
    while (index < s.size()) {
        // operator
        if (s[index]=='+' || s[index]=='-' || s[index]=='*' || s[index]=='/') {
            ops.push_back(s[index]);
            index++;
            length = 1;
            continue;
        }
        //white space
        if (s[index]==' ') {
            index++;
            length = 1;
            continue;
        }
        //number
        while((index+length<s.size()) && isdigit(s[index+length])) {
            length++;
        }
        long num = stoi(s.substr(index,length));
        index += length;
        
        //process if it's operand of * or /
        if (!ops.empty() && (ops.back()=='*' || ops.back()=='/')) {
            long tmp = nums.back();
            char op = ops.back();
            nums.pop_back();
            ops.pop_back();
            long res = (op=='*')?(tmp*num):(tmp/num);
            nums.push_back(res);
        } else {
            nums.push_back(num);
        }
    }
    
    if (nums.size()!=ops.size()+1) {
        cout<<"wrong parse!!!"<<endl;
    }
    
    index = 0;
    long res = nums[index];
    index++;
    while (index<nums.size()) {
        char op = ops[index-1];
        int sign = (op=='+')?1:(-1);
        res += sign*nums[index];
        index++;
    }
    return (int)res;
}
