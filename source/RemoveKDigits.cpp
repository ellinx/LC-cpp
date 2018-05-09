
#include "../Solutions.hpp"

/***************** Remove K Digits *****************/
/*
 Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.
 
 Note:
 The length of num is less than 10002 and will be ≥ k.
 The given num does not contain any leading zero.
 Example 1:
 
 Input: num = "1432219", k = 3
 Output: "1219"
 Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
 
 Example 2:
 
 Input: num = "10200", k = 1
 Output: "200"
 Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
 
 Example 3:
 
 Input: num = "10", k = 2
 Output: "0"
 Explanation: Remove all the digits from the number and it is left with nothing which is 0.
 */


string Solutions::removeKdigits(string num, int k) {
    if (k==0) return num;
    if (num.size()<=k) return "0";
    
    int index0 = num.find_first_of("0");
    if (index0!=-1) {
        if (index0==k) {
            string res = num.substr(index0+1);
            int index = 0;
            while (index<res.size() && res[index]=='0') index++;
            
            if (index==res.size()) return "0";
            
            return res.substr(index);
        }
        
        if (index0<k) {
            return removeKdigits(num.substr(index0+1), k-index0);
        }
        
        if (index0>k) {
            string prefix = removeKdigits(num.substr(0,index0), k);
            
            if (prefix=="0")
                return num.substr(index0);
            else
                return prefix+num.substr(index0);
        }
    }
    
    
    for (int i=0;i<num.size()-1;i++) {
        if (num[i]>num[i+1]) {
            return removeKdigits(num.substr(0,i)+num.substr(i+1), k-1);
        }
    }
    
    num.pop_back();
    return removeKdigits(num, k-1);
}
