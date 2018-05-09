#include "../Solutions.hpp"
#include "Tester.hpp"

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
long long coinChangeC(vector<int>& coins, int money) {
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

/*
 You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
 
 Example 1:
 coins = [1, 2, 5], amount = 11
 return 3 (11 = 5 + 5 + 1)
 
 Example 2:
 coins = [2], amount = 3
 return -1.
 
 Note:
 You may assume that you have an infinite number of each kind of coin.
 */

int Solutions::coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount+1, -1);
    dp[0] = 0;
    sort(coins.begin(), coins.end(), greater<int>());

    for (int i=0;i<coins.size();i++) {
        for (int j=coins[i];j<dp.size();j++) {
            if (dp[j-coins[i]]!=-1 && (dp[j]==-1 || dp[j]>dp[j-coins[i]]+1)) {
                dp[j] = dp[j-coins[i]]+1;
            }
        }
    }
    return dp.back();
}
