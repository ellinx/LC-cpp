
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
    if (letters['z'-'a']>0) {
        int times = letters['z'-'a'];
        for (int i=0;i<times;i++)
            digits.push_back(0);
        
        letters['z'-'a'] -= times;
        letters['e'-'a'] -= times;
        letters['r'-'a'] -= times;
        letters['o'-'a'] -= times;
    }
    if (letters['w'-'a']>0) {
        int times = letters['w'-'a'];
        for (int i=0;i<times;i++)
            digits.push_back(2);
        
        letters['t'-'a'] -= times;
        letters['w'-'a'] -= times;
        letters['o'-'a'] -= times;
    }
    if (letters['u'-'a']>0) {
        int times = letters['u'-'a'];
        for (int i=0;i<times;i++)
            digits.push_back(4);
        
        letters['f'-'a'] -= times;
        letters['o'-'a'] -= times;
        letters['u'-'a'] -= times;
        letters['r'-'a'] -= times;
    }
    if (letters['x'-'a']>0) {
        int times = letters['x'-'a'];
        for (int i=0;i<times;i++)
            digits.push_back(6);
        
        letters['s'-'a'] -= times;
        letters['i'-'a'] -= times;
        letters['x'-'a'] -= times;
    }
    if (letters['g'-'a']>0) {
        int times = letters['g'-'a'];
        for (int i=0;i<times;i++)
            digits.push_back(8);
        
        letters['e'-'a'] -= times;
        letters['i'-'a'] -= times;
        letters['g'-'a'] -= times;
        letters['h'-'a'] -= times;
        letters['t'-'a'] -= times;
    }
    
    //now o,h,s identify unique digits
    if (letters['o'-'a']>0) {
        int times = letters['o'-'a'];
        for (int i=0;i<times;i++)
            digits.push_back(1);
        
        letters['o'-'a'] -= times;
        letters['n'-'a'] -= times;
        letters['e'-'a'] -= times;
    }
    if (letters['h'-'a']>0) {
        int times = letters['h'-'a'];
        for (int i=0;i<times;i++)
            digits.push_back(3);
        
        letters['t'-'a'] -= times;
        letters['h'-'a'] -= times;
        letters['r'-'a'] -= times;
        letters['e'-'a'] -= times;
        letters['e'-'a'] -= times;
    }
    if (letters['s'-'a']>0) {
        int times = letters['s'-'a'];
        for (int i=0;i<times;i++)
            digits.push_back(7);
        letters['s'-'a'] -= times;
        letters['e'-'a'] -= times;
        letters['v'-'a'] -= times;
        letters['e'-'a'] -= times;
        letters['n'-'a'] -= times;
    }
    
    //f and n differentiate what's left
    if (letters['f'-'a']>0) {
        int times = letters['f'-'a'];
        for (int i=0;i<times;i++)
            digits.push_back(5);
        
        letters['f'-'a'] -= times;
        letters['i'-'a'] -= times;
        letters['v'-'a'] -= times;
        letters['e'-'a'] -= times;
    }
    if (letters['n'-'a']>0) {
        int times = letters['n'-'a'];
        times >>= 1;//nine has two 'n'
        for (int i=0;i<times;i++)
            digits.push_back(9);
        
        letters['n'-'a'] -= times;
        letters['i'-'a'] -= times;
        letters['n'-'a'] -= times;
        letters['e'-'a'] -= times;
    }
    
    sort(digits.begin(),digits.end());
    string res;
    for (int i:digits) {
        res += to_string(i);
    }
    return res;
}
