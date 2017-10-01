#include "../Solutions.hpp"

/***************** Best Time to Buy and Sell Stock *****************/
/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Example 1:

Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)

Example 2:

Input: [7, 6, 4, 3, 1]
Output: 0

In this case, no transaction is done, i.e. max profit = 0.
*/

int Solutions::maxProfit(vector<int>& prices) {
	if (prices.size()<2) return 0;
	int res = 0;
	int min = prices[0];
	for (int i=1;i<prices.size();i++) {
		if (prices[i]-min>res) {
			res = prices[i]-min;
		}
		if (prices[i]<min) {
			min = prices[i];
		}
	}
	return res;
}


/***************** Best Time to Buy and Sell Stock II *****************/
/*
 Say you have an array for which the ith element is the price of a given stock on day i.
 
 Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 */

int Solutions::maxProfitII(vector<int>& prices) {
    if (prices.empty()) return 0;
    
    int res = 0;
    int buyPrice = prices[0];
    bool toBuy=true;
    for (int i=1;i<prices.size();i++) {
        if (toBuy) {
            if (prices[i-1]<prices[i]) {
                buyPrice = prices[i-1];
                toBuy = false;
            }
        } else {
            if (prices[i-1]>prices[i]) {
                res += prices[i-1]-buyPrice;
                toBuy = true;
            }
        }
    }
    if (!toBuy && prices.back()>buyPrice) res += prices.back()-buyPrice;
    return res;
}
