
#include "../Solutions.hpp"

using namespace std;

/***************** Happy Number *****************/
/*
 Write an algorithm to determine if a number is "happy".
 
 A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
 
 Example: 19 is a happy number
 
 1^2 + 9^2 = 82
 8^2 + 2^2 = 68
 6^2 + 8^2 = 100
 1^2 + 0^2 + 0^2 = 1
 */

bool Solutions::isHappy(int n) {
    unordered_set<int> numSet;
    while (n!=1) {
        if (numSet.find(n)!=numSet.end()) {
            return false;
        }
        numSet.insert(n);
        int next = 0;
        while (n>9) {
            int digit = n%10;
            next += digit*digit;
            n /= 10;
        }
        next += n*n;
        n = next;
    }
    return true;
}
