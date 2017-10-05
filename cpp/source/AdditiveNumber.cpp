#include "../Solutions.hpp"

/***************** Additive Number *****************/
/*
 Additive number is a string whose digits can form additive sequence.
 
 A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.
 
 For example:
 "112358" is an additive number because the digits can form an additive sequence: 1, 1, 2, 3, 5, 8.
 
 1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
 "199100199" is also an additive number, the additive sequence is: 1, 99, 100, 199.
 1 + 99 = 100, 99 + 100 = 199
 Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.
 
 Given a string containing only digits '0'-'9', write a function to determine if it's an additive number.
 
 Follow up:
 How would you handle overflow for very large input integers?
 
 */

bool DFSCheck(string num1, string num2, int start, string num);
string stringAdd (string s1, string s2);

bool Solutions::isAdditiveNumber(string num) {
    int n = num.size();
    if (n<3) return false;
    
    for (int i=1;i<n-1;i++) {
        string num1 = num.substr(0,i);
        for (int j=i+1;j<n;j++) {
            string num2 = num.substr(i,j-i);
            if (DFSCheck(num1,num2,j,num)) return true;
        }
    }
    return false;
}

bool DFSCheck(string num1, string num2, int start, string num) {
    if ((num1[0]=='0' && num1.size()>1) || (num2[0]=='0' && num2.size()>1)) {
        return false;
    }
    string sum = stringAdd(num1,num2);
    //cout<<num1<<"+"<<num2<<"="<<sum<<endl;
    int n = sum.size();
    if (n>num.size()-start) {
        return false;
    }
    
    if (sum==num.substr(start,n)) {
        if (start+n==num.size()){
            return true;
        }
        return DFSCheck(num2, sum, start+n, num);
    } else {
        return false;
    }
}

string stringAdd (string s1, string s2) {
    string res;
    int a = 0;
    int b = 0;
    int c = 0;
    int index = 0;
    
    for (;index<min(s1.size(),s2.size());index++) {
        a = s1[s1.size()-1-index]-'0';
        b = s2[s2.size()-1-index]-'0';
        int sum = a+b+c;
        c = sum/10;
        sum %= 10;
        res = to_string(sum)+res;
    }
    
    if (index<s1.size()) {
        int size = s1.size()-index-1;
        while (size>=0) {
            a = s1[size]-'0';
            b = 0;
            int sum = a+b+c;
            c = sum/10;
            sum %= 10;
            res = to_string(sum)+res;
            size--;
        }
    } else if (index<s2.size()) {
        int size = s2.size()-index-1;
        while (size>=0) {
            a = 0;
            b = s2[size]-'0';
            int sum = a+b+c;
            c = sum/10;
            sum %= 10;
            res = to_string(sum)+res;
            size--;
        }
    }
    
    if (c!=0) {
        res = to_string(c) + res;
    }
    return res;
}
