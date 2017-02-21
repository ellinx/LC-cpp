#include "../Solutions.hpp"

using namespace std;

/***************** Add Binary *****************/
/*
 Given two binary strings, return their sum (also a binary string).
 
 For example,
 a = "11"
 b = "1"
 Return "100".
*/
string Solutions::addBinary(string a, string b) {
    int sizeA = a.size();
    int sizeB = b.size();
    string res(max(sizeA,sizeB)+1,'0');
    a = string(res.size()-sizeA,'0')+a;
    b = string(res.size()-sizeB,'0')+b;
    int carry = 0;
    for (int i=res.size()-1;i>=0;i--) {
        int sum = a[i]-'0' + b[i]-'0' + carry;
        if (sum==0 || sum==1) {
            res[i] = sum+'0';
            carry = 0;
        } else {
            res[i] = sum-2+'0';
            carry = 1;
        }
    }
    if (res.front()=='0') return res.substr(1,-1);
    return res;
}
