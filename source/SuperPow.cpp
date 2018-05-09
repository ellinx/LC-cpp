#include "../Solutions.hpp"
#include "../Tester.hpp"

/***************** Super Pow *****************/
/*
 Your task is to calculate a^b mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.
 
 Example1:
 a = 2
 b = [3]
 
 Result: 8
 
 Example2:
 a = 2
 b = [1,0]
 
 Result: 1024
 */

//0<=b<=10
int sPDigit(int a, int b) {
    if (a==1 || b==0) return 1;
    
    int mod = 1337;
    int res = a%mod;
    b--;
    while (b!=0) {
        res = (res*(a%mod))%mod;
        b--;
    }
    return res;
}

//ab % k = (a%k)(b%k)%k
int Solutions::superPow(int a, vector<int>& b) {
    if (b.empty()) return 1;
    
    int mod = 1337;
    int lastDigit = b.back();
    b.pop_back();
    return sPDigit(superPow(a, b), 10)*sPDigit(a, lastDigit)%mod;
}
