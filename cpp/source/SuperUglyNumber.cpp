#include "../Solutions.hpp"
#include "../main.h"

using namespace std;

/***************** Super Ugly Number *****************/
/*
 Write a program to find the nth super ugly number.
 
 Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.
 
 Note:
 (1) 1 is a super ugly number for any given primes.
 (2) The given numbers in primes are in ascending order.
 (3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
 (4) The nth super ugly number is guaranteed to fit in a 32-bit signed integer.
 */

int Solutions::nthSuperUglyNumber(int n, vector<int>& primes) {
    vector<int> dp(n,0);
    vector<int> index(primes.size(),0);
    
    dp[0] = 1;
    
    for (int i=1;i<n;i++) {
        dp[i] = INT_MAX;
        for (int j=0;j<primes.size();j++) {
            dp[i] = min(dp[i], dp[index[j]]*primes[j]);
        }
        //cout<<"i="<<i<<",dp[i]="<<dp[i]<<endl;
        for (int j=0;j<primes.size();j++) {
            if (dp[i] == dp[index[j]]*primes[j]) {
                index[j]++;
            }
        }
    }
    
    printVector(dp);
    return dp.back();
}
