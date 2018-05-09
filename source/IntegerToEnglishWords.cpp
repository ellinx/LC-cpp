#include "../Solutions.hpp"

using namespace std;

/***************** Integer to English Words *****************/
/*
 Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 2^31 - 1.
 
 For example,
 123 -> "One Hundred Twenty Three"
 12345 -> "Twelve Thousand Three Hundred Forty Five"
 1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
 Hint:
 
 Did you see a pattern in dividing the number into chunk of words? For example, 123 and 123000.
 Group the number by thousands (3 digits). You can write a helper function that takes a number less than 1000 and convert just that chunk to words.
 There are many edge cases. What are some good test cases? Does your code work with input such as 0? Or 1000010? (middle chunk is zero and should not be printed out)
 */

string helper(int num);

string Solutions::numberToWords(int num) {
    string res;
	vector<int> numGroup(4,0);
	bool isZero = true;
	for (int i=3;i>=0;i--) {
		numGroup[i] = num%1000;
		num /= 1000;
	}

	for (int i=0;i<4;i++) {
		if (numGroup[i]>0) {
			isZero = false;
			if (res.empty()) {
				res += helper(numGroup[i]);
			} else {
				res += " " + helper(numGroup[i]);
			}
			switch (i) {
				case 0:
					res += " Billion";
					break;
				case 1:
					res += " Million";
					break;
				case 2:
					res += " Thousand";
					break;
			}
		}
	}
	if (isZero) return "Zero";
	return res;
}

string helper(int num) {
	string res;
	unordered_map<int,string> hash;
	hash[0] = "Zero";
	hash[1] = "One";
	hash[2] = "Two";
	hash[3] = "Three";
	hash[4] = "Four";
	hash[5] = "Five";
	hash[6] = "Six";
	hash[7] = "Seven";
	hash[8] = "Eight";
	hash[9] = "Nine";
	hash[10] = "Ten";
	hash[11] = "Eleven";
	hash[12] = "Twelve";
	hash[13] = "Thirteen";
	hash[14] = "Fourteen";
	hash[15] = "Fifteen";
	hash[16] = "Sixteen";
	hash[17] = "Seventeen";
	hash[18] = "Eighteen";
	hash[19] = "Nineteen";
	hash[20] = "Twenty";
	hash[30] = "Thirty";
	hash[40] = "Forty";
	hash[50] = "Fifty";
	hash[60] = "Sixty";
	hash[70] = "Seventy";
	hash[80] = "Eighty";
	hash[90] = "Ninety";

	int digit = num/100;
	if (digit!=0) {
		res = hash[digit] + " Hundred";
	}

	digit = num%100;
	if (digit==0) {
		return res;
	}else if ((digit>0 && digit<=20) || digit==30 || digit==40 || digit==50 || digit==60 || digit==70 || digit==80 || digit==90) {
		if (res.empty()) res += hash[digit];
		else res += " " + hash[digit];
	} else if (digit<30) {
		if (res.empty()) res +=  hash[20] + " " + hash[digit-20];
		else res += " " + hash[20] + " " + hash[digit-20];
	} else if (digit<40) {
		if (res.empty()) res += hash[30] + " " + hash[digit-30];
		else res += " " + hash[30] + " " + hash[digit-30];
	} else if (digit<50) {
		if (res.empty()) res += hash[40] + " " + hash[digit-40];
		else res += " " + hash[40] + " " + hash[digit-40];
	} else if (digit<60) {
		if (res.empty()) res += hash[50] + " " + hash[digit-50];
		else res += " " + hash[50] + " " + hash[digit-50];
	} else if (digit<70) {
		if (res.empty()) res += hash[60] + " " + hash[digit-60];
		else res += " " + hash[60] + " " + hash[digit-60];
	} else if (digit<80) {
		if (res.empty()) res += hash[70] + " " + hash[digit-70];
		else res += " " + hash[70] + " " + hash[digit-70];
	} else if (digit<90) {
		if (res.empty()) res += hash[80] + " " + hash[digit-80];
		else res += " " + hash[80] + " " + hash[digit-80];
	} else {
		if (res.empty()) res += hash[90] + " " + hash[digit-90];
		else res += " " + hash[90] + " " + hash[digit-90];
	}
	return res;
}
