
/***************** Largest Number *****************/
/*
 Given a list of non negative integers, arrange them such that they form the largest number.
 
 For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
 
 Note: The result may be very large, so you need to return a string instead of an integer.
 */

#include "../Solutions.hpp"

bool cmp(string a, string b) {
    if (a.size()<b.size() && b.find(a)==0) {
        return cmp(a, b.substr(a.size()));
    } else if (a.size()>b.size() && a.find(b)==0) {
        return cmp(a.substr(b.size()), b);
    }
    return a>b;
}

string Solutions::largestNumber(vector<int>& nums) {
    vector<string> strNums;
    for (int num : nums) {
        strNums.push_back(to_string(num));
    }
    
    sort(strNums.begin(), strNums.end(), cmp);
    
    string s;
    for (string strNum : strNums) {
        s += strNum;
    }
    
    //remove leading zeros
    if (s[0]=='0' && s.size()>1) return "0";
    return s;
}
