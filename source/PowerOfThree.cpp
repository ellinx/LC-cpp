#include "../Solutions.hpp"
using namespace std;

/*************** Power of Three **************/
/*
 Given an integer, write a function to determine if it is a power of three.
 
 Follow up:
 Could you do it without using any loop / recursion?
 */

bool Solutions::isPowerOfThree(int n) {
    if (n<=0) return false;
    if (n==1) return true;
    
    long long num = 3;
    while (num<n) {
        if (num*num<=n) {
            num *= num;
        } else {
            break;
        }
    }
    if (num==n) {
        return true;
    } else if (n%num==0){
        return isPowerOfThree(n/num);
    }
    
    return false;
}
