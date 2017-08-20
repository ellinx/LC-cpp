#include "../Solutions.hpp"

using namespace std;

/***************** Coin Change *****************/
/*
Given a number of dollars, n, and a list of dollar values for m distinct coins, C={c0,c1,c2,...,c(m-1)} , find and print the number of different ways you can make change for n dollars if each coin is available in an infinite quantity.
 Example 1: n=4, m=3 , coins={1,2,3} then output is 4.
 for n=4 and C={1,2,3} :
 1. {1,1,1,1}
 2. {1,1,2}
 3. {2,2}
 4. {1,3}
 
 Example 2: n=10, m=4 , coins={2,5,3,6} then output is 5.
 for n=10 and C={2,5,3,6} :
 1. {2,2,2,2,2}
 2. {2,2,3,3}
 3. {2,2,6}
 4. {2,3,5}
 5. {5,5}
 
 Hints:
 
 You can solve this problem recursively, but you must optimize your solution to eliminate overlapping subproblems using Dynamic Programming if you wish to pass all test cases. More specifically, think of ways to store the checked solutions and use the stored values to avoid repeatedly calculating the same values.
 Think about the degenerate cases:
 1.How many ways can you make change for 0 dollars?
 2.How many ways can you make change for less than 0 dollars if you have no coins?
 If you are having trouble defining the storage for your precomputed values, then think about it in terms of the base case(n=0).
 */

//combination if coin order does not matter
long long Solutions::coinChange(vector<int>& coins, int money) {
    vector<long> answer(money+1,0);
    answer[0] = 1;
    for (int coin : coins) {
        for (int i=coin;i<=money;i++) {
            answer[i] += answer[i-coin];
        }
    }
    return answer[money];
}

//permutation if coin order does matter
long long coinChangeP(vector<int>& coins, int money) {
    vector<long> res(money+1);
    res[0] = 1;
    for (int i=0;i<money;i++) {
        for (int coin : coins) {
            if (i >= coin) {
                res[i] += res[i-coin];
            }
        }
    }
    return res.back();
}

