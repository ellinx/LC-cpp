#include "../Solutions.hpp"

using namespace std;

/***************** Divide Two Integers  *****************/
/*
 Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT. 
*/

int Solutions::divide(int dividend, int divisor) {
	if (divisor==0) return INT_MAX;
	if (dividend==0) return 0;
	int flag=1;
	long a = dividend;
	long b = divisor;
	if (a<0 && b<0) {
		a *= -1;
		b *= -1;
	}else if ( a<0 && b>0) {
		a *= -1;
		flag = -1;
	} else if (a>=0 && b<0) {
		b *= -1;
		flag = -1;
	}
	if (b==1) return (flag*a>INT_MAX)?INT_MAX:flag*a;
	long res=0;

    while (a>=b) {
    	int sum=b;
		int num=1;
		while(a>=sum) {
			sum <<= 1;
			num <<= 1;
		}
		a -= sum>>1;
		res += num>>1;
    }

	return (flag*res>INT_MAX)?INT_MAX:flag*res;
}