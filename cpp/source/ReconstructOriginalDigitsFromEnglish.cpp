
#include "../Solutions.hpp"

/************** Reconstruct Original Digits From English *****************/
/*
 Given a non-empty string containing an out-of-order English representation of digits 0-9, output the digits in ascending order.
 
 Note:
 Input contains only lowercase English letters.
 Input is guaranteed to be valid and can be transformed to its original digits. That means invalid inputs such as "abc" or "zerone" are not permitted.
 Input length is less than 50,000.
 Example 1:
 Input: "owoztneoer"
 
 Output: "012"
 Example 2:
 Input: "fviefuro"
 
 Output: "45"
 */

string Solutions::originalDigits(string s) {
    
    vector<int> digits;
    vector<int> letters(26,0);
    for (char a : s) {
        letters[a-'a']++;
    }
    
    //z,w,u,x,g identify unique digits
    while (letters['z'-'a']>0) {
        digits.push_back(0);
        letters['z'-'a']--;
        letters['e'-'a']--;
        letters['r'-'a']--;
        letters['o'-'a']--;
    }
    while (letters['w'-'a']>0) {
        digits.push_back(2);
        letters['t'-'a']--;
        letters['w'-'a']--;
        letters['o'-'a']--;
    }
    while (letters['u'-'a']>0) {
        digits.push_back(4);
        letters['f'-'a']--;
        letters['o'-'a']--;
        letters['u'-'a']--;
        letters['r'-'a']--;
    }
    while (letters['x'-'a']>0) {
        digits.push_back(6);
        letters['s'-'a']--;
        letters['i'-'a']--;
        letters['x'-'a']--;
    }
    while (letters['g'-'a']>0) {
        digits.push_back(8);
        letters['e'-'a']--;
        letters['i'-'a']--;
        letters['g'-'a']--;
        letters['h'-'a']--;
        letters['t'-'a']--;
    }
    
    //now o,h,s identify unique digits
    while (letters['o'-'a']>0) {
        digits.push_back(1);
        letters['o'-'a']--;
        letters['n'-'a']--;
        letters['e'-'a']--;
    }
    while (letters['h'-'a']>0) {
        digits.push_back(3);
        letters['t'-'a']--;
        letters['h'-'a']--;
        letters['r'-'a']--;
        letters['e'-'a']--;
        letters['e'-'a']--;
    }
    while (letters['s'-'a']>0) {
        digits.push_back(7);
        letters['s'-'a']--;
        letters['e'-'a']--;
        letters['v'-'a']--;
        letters['e'-'a']--;
        letters['n'-'a']--;
    }
    
    //f and n differentiate what's left
    while (letters['f'-'a']>0) {
        digits.push_back(5);
        letters['f'-'a']--;
        letters['i'-'a']--;
        letters['v'-'a']--;
        letters['e'-'a']--;
    }
    while (letters['n'-'a']>0) {
        digits.push_back(9);
        letters['n'-'a']--;
        letters['i'-'a']--;
        letters['n'-'a']--;
        letters['e'-'a']--;
    }
    
    sort(digits.begin(),digits.end());
    string res;
    for (int i:digits) {
        res += to_string(i);
    }
    return res;
}
