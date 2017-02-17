#include "../Solutions.hpp"

using namespace std;

/***************** Multiply Strings *****************/
/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.

Note:

    The length of both num1 and num2 is < 110.
    Both num1 and num2 contains only digits 0-9.
    Both num1 and num2 does not contain any leading zero.
    You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/

string Solutions::multiply(string num1, string num2) {
	int size1 = num1.size();
	int size2 = num2.size();
	string res(size1+size2,'0');
	for (int index2=0;index2<size2;index2++) {
		for (int index1=0;index1<size1;index1++) {
			int index3 = size1+size2-1-index1-index2;
			int digit1 = num1[size1-1-index1]-'0';
			int digit2 = num2[size2-1-index2]-'0';
			int result = res[index3]-'0'+digit1*digit2;

			res[index3] = result%10 +'0';
			res[index3-1] = res[index3-1]+result/10;
		}
	}
	if (res[0]!='0') return res;
	//remove leading zeros
	int start=0;
	while(res[start]=='0') {
		start++;
		if (start>size1+size2-1) return "0";
	}
	return res.substr(start,-1);
}